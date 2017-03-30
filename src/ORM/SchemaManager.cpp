/*********************************************************
*
*  Copyright © 2017, Xen Roleplay.
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

#include "StdInc.h"
#include "SchemaManager.h"
#include "Comparator.h"

SchemaManager::SchemaManager( DatabaseManager* db, ::Module* module ) :
	DB( db ),
	Module( module )
{
	this->Platform = new MySQLPlatform();
}

SchemaManager::~SchemaManager()
{
	SAFE_DELETE( this->Platform );
}

void SchemaManager::Synchronize( const vector< IEntityRepository* >& repositories )
{
	Schema* schema1 = this->CreateSchema();
	Schema* schema2 = this->CreateSchema( repositories );

	Comparator comparator;

	SchemaDiff* diff = comparator.Compare( schema1, schema2 );

	const vector< string >& sql = diff->ToSQL( this->Platform );

	delete schema1;
	delete schema2;

	if( sql.size() == 0 )
	{
		this->Module->DebugPrintf( "Nothing to update - your database is already in sync with the current entity metadata\n" );

		return;
	}

	this->Module->DebugPrintf( "Updating database schema...\n" );

	for( const string& query : sql )
	{
		if( !this->DB->GetConnection()->QueryFree( query ) )
		{
			cout << query << endl;

			throw new MySQLException( this->DB->GetConnection() );

			return;
		}
	}

	this->Module->DebugPrintf( "Database schema updated successfully! %d queries were executed\n", sql.size() );
}

Schema* SchemaManager::CreateSchema()
{
	Schema* schema = new Schema();

	string sql = this->Platform->GetListTablesSQL();

	MySQLResult* result = this->DB->GetConnection()->Query( sql );

	if( result )
	{
		for( const MySQLRow& row : *result )
		{
			Table* table = this->CreateTable( schema, row.at( "TableName" ) );

			schema->AddTable( table );
		}

		result->Free();
	}

	return schema;
}

Schema* SchemaManager::CreateSchema( const vector< IEntityRepository* >& repositories )
{
	Schema* schema = new Schema();

	for( IEntityRepository* repo : repositories )
	{
		Table* table = this->CreateTable( schema, repo );

		schema->AddTable( table );
	}

	return schema;
}

Table* SchemaManager::CreateTable( Schema* schema, const string& tableName )
{
	Table* table = new Table( schema, tableName );

	{
		string sql = this->Platform->GetListTableColumnsSQL( table->GetName(), this->DB->GetDatabase() );

		MySQLResult* result = this->DB->GetConnection()->Query( sql );

		if( result == nullptr )
		{
			throw new MySQLException( this->DB->GetConnection() );
		}

		this->CreateTableColumns( table, result->FetchAll() );

		result->Free();
	}

	if( this->Platform->SupportsForeignKeyConstraints() )
	{
		string sql = this->Platform->GetListTableForeignKeysSQL( table->GetName(), this->DB->GetDatabase() );

		MySQLResult* result = this->DB->GetConnection()->Query( sql );

		if( result == nullptr )
		{
			throw new MySQLException( this->DB->GetConnection() );
		}

		this->CreateTableForeignKeys( table, result->FetchAll() );
	
		result->Free();
	}

	{
		string sql = this->Platform->GetListTableIndexesSQL( table->GetName(), this->DB->GetDatabase() );

		MySQLResult* result = this->DB->GetConnection()->Query( sql );

		if( result == nullptr )
		{
			throw new MySQLException( this->DB->GetConnection() );
		}

		this->CreateTableIndexes( table, result->FetchAll() );

		result->Free();
	}

	return table;
}

Table* SchemaManager::CreateTable( Schema* schema, IEntityRepository* repository )
{
	TiXmlDocument doc( "Config/" + repository->GetName() + ".xml" );

	if( !doc.LoadFile() )
	{
		throw new exception( ( "Table config '" + repository->GetName() + ".xml' not found" ).c_str() );
	}

	TiXmlElement* root = doc.FirstChildElement( "table" );

	if( !root )
	{
		throw new exception( ( "Table config '%s.xml' is invalid\n", repository->GetName()).c_str() );
	}

	auto attribute = []( TiXmlElement* node, const string& name ) -> string
	{
		const char* value = node->Attribute( name.c_str() );

		if( value )
		{
			return string( value );
		}

		return string();
	};

	auto error = []( const string& message, const string& xmlName, uint64_t lineNumber )
	{
		stringstream ss;

		ss << xmlName << ".xml:" << lineNumber << ": " << message;

		throw new exception( ss.str().c_str() );
	};

	const string& tableName = attribute( root, "name" );

	TiXmlNode*    child = nullptr;
	TiXmlElement* node  = nullptr;

	uint64_t lineNumber = 0;

	vector< map< string, string > > columns;
	vector< map< string, string > > indexes;

	for( child = root->FirstChild(); child != nullptr; child = child->NextSibling() )
	{
		++lineNumber;

		node = child->ToElement();

		const string& columnName = child->ValueStr();

		if( columnName == "column" )
		{
			string name    = attribute( node, "name" );
			string type    = attribute( node, "type" );
			string default = attribute( node, "default" );
			string extra   = attribute( node, "extra" );

			if( name.empty() )
			{
				error( "Column without 'name' attribute", repository->GetName(), lineNumber );
			}

			if( name == "id" )
			{
				type  = "int(11) unsigned";
				extra = "auto_increment";
			}

			if( type.empty() )
			{
				error( "Column without 'type' attribute", repository->GetName(), lineNumber );
			}

			map< string, string > row;

			row[ "Field" ]        = name;
			row[ "Type" ]         = type;
			row[ "Null" ]         = default == "NULL" ? "YES" : "NO";
			row[ "Default" ]      = default;
			row[ "Extra" ]        = extra;
			row[ "Comment" ]      = attribute( node, "comment" );
			row[ "CharacterSet" ] = attribute( node, "characterset" );
			row[ "Collation" ]    = attribute( node, "collation" );

			columns.push_back( row );

			if( name == "id" )
			{
				map< string, string > index;

				index[ "Table" ]         = tableName;
				index[ "Non_unique" ]    = "0";
				index[ "Key_name" ]      = "PRIMARY";
				index[ "Seq_in_index" ]  = "1";
				index[ "Column_name" ]   = name;
				index[ "Index_type" ]    = "BTREE";

				indexes.push_back( index );
			}
		}
	}

	Table* table = new Table( schema, tableName );

	this->CreateTableColumns( table, columns );
	this->CreateTableIndexes( table, indexes );

	return table;
}

void SchemaManager::CreateTableColumns( Table* table, const vector< map< string, string > >& rows )
{
	for( const map< string, string >& row : rows )
	{
		string columnName = row.at( "Field" );
		string type       = strtok( const_cast< char* >( row.at( "Type" ).c_str() ), "(), " );
		size_t length     = 0;
		bool   fixed      = false;
		string default    = row.at( "Default" );
		string extra      = row.at( "Extra" );

		if( row.count( "Length" ) != 0 )
		{
			length = stoi( row.at( "Length" ) );
		}
		else
		{
			char* _type = strtok( nullptr, "(), " );

			if( _type )
			{
				length = stoi( _type );
			}
		}

		type = this->Platform->GetDoctrineTypeMapping( type );

		if( type == "char" || type == "binary" )
		{
			fixed = true;
		}
		else if( type == "float" || type == "double" || type == "real" || type == "numeric" || type == "decimal" )
		{
			/*if( preg_match( "([A-Za-z]+\(([0-9]+)\,([0-9]+)\))", row.at( "type" ), match ) )
			{
				precision = match[ 1 ];
				scale     = match[ 2 ];
				length    = 0;
			}*/
		}
		else if( type == "tinytext" )
		{
			length = MySQLPlatform::LENGTH_LIMIT_TINYTEXT;
		}
		else if( type == "text" )
		{
			length = MySQLPlatform::LENGTH_LIMIT_TEXT;
		}
		else if( type == "mediumtext" )
		{
			length = MySQLPlatform::LENGTH_LIMIT_MEDIUMTEXT;
		}
		else if( type == "tinyblob" )
		{
			length = MySQLPlatform::LENGTH_LIMIT_TINYBLOB;
		}
		else if( type == "blob" )
		{
			length = MySQLPlatform::LENGTH_LIMIT_BLOB;
		}
		else if( type == "mediumblob" )
		{
			length = MySQLPlatform::LENGTH_LIMIT_MEDIUMBLOB;
		}

		Column* column = new Column( table, columnName, ColumnType::GetType( type ) );

		column->SetLength( length );
		column->SetUnsigned( type.find( "unsigned" ) != string::npos );
		column->SetDefault( default );
		column->SetNotNull( row.at( "Null" ) != "YES" );
		column->SetAutoincrement( extra.find( "auto_increment" ) != string::npos );
		column->SetComment( row.at( "Comment" ) );

		table->AddColumn( column );
	}
}

void SchemaManager::CreateTableForeignKeys( Table* table, const vector< map< string, string > >& rows )
{
	struct ConstraintData
	{
		string Name;
		vector< string > Local;
		vector< string > Foreign;
		string ForeignTable;
		const char* OnDelete = nullptr;
		const char* OnUpdate = nullptr;
	};

	map< string, ConstraintData > list;

	for( const map< string, string >& row : rows )
	{
		const string& name = row.at( "CONSTRAINT_NAME" );

		if( list.count( name ) == 0 )
		{
			ConstraintData data;

			data.Name         = row.at( "CONSTRAINT_NAME" );
			data.ForeignTable = row.at( "REFERENCED_TABLE_NAME" );
			data.OnDelete     = row.count( "DELETE_RULE" ) > 0 && row.at( "DELETE_RULE" ) != "RESTRICT" ? row.at( "DELETE_RULE" ).c_str() : nullptr;
			data.OnUpdate     = row.count( "UPDATE_RULE" ) > 0 && row.at( "UPDATE_RULE" ) != "RESTRICT" ? row.at( "UPDATE_RULE" ).c_str() : nullptr;

			list[ name ] = data;
		}
			
		list[ name ].Local.push_back( row.at( "COLUMN_NAME" ) );
		list[ name ].Foreign.push_back( row.at( "REFERENCED_COLUMN_NAME" ) );
	}

	for( const auto& iter : list )
	{
		const ConstraintData& data = iter.second;

		map< string, string > options
		{
			{ "OnDelete", data.OnDelete },
			{ "OnUpdate", data.OnUpdate }
		};

		table->AddNamedForeignKeyConstraint( data.Name, table, data.Local, data.Foreign, options );
	}
}

void SchemaManager::CreateTableIndexes( Table* table, const vector< map< string, string > >& rows )
{
	struct IndexData
	{
		string IndexName;
		bool   IsUnique;
		bool   IsPrimary;

		vector< string >      Columns;
		vector< string >      Flags;
	};

	map< string, IndexData >  indexes;

	for( map< string, string > row : rows )
	{
		string keyName = row[ "Key_name" ];

		if( row.count( "primary" ) )
		{
			keyName = "primary";
		}

		keyName = strtolower( keyName );

		if( indexes.count( keyName ) == 0 )
		{
			IndexData index;

			index.IndexName = row[ "Key_name" ];
			index.IsUnique  = row[ "Non_unique" ] != "0";
			index.IsPrimary = row[ "Key_name" ] == "PRIMARY";

			index.Columns.push_back( row[ "Column_name" ] );

			const string& IndexType = row[ "Index_type" ];

			if( IndexType.find( "FULLTEXT" ) != string::npos )
			{
				index.Flags.push_back( "FULLTEXT" );
			}
			else if( IndexType.find( "SPATIAL" ) != string::npos )
			{
				index.Flags.push_back( "SPATIAL" );
			}

			indexes[ keyName ] = index;
		}
		else
		{
			indexes[ keyName ].Columns.push_back( row[ "Column_name" ] );
		}
	}

	for( const auto& iter : indexes )
	{
		const IndexData& idx = iter.second;

		Index* index = new Index( table, idx.IndexName, idx.Columns, idx.IsUnique, idx.IsPrimary, idx.Flags );

		table->AddIndex( index );
	}
}
