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
#include "MySQLPlatform.h"
#include "ForeignKeyConstraint.h"

string MySQLPlatform::DoModifyLimitQuery( const string & query, int limit, int offset )
{
	stringstream stream;

	if( limit != -1 )
	{
		stream << " LIMIT " << limit;

		if( offset != -1 )
		{
			stream << " OFFSET " << offset;
		}
	}
	else if( offset != -1 )
	{
		stream << " LIMIT 18446744073709551615 OFFSET " << offset;
	}

	return stream.str();
}

string MySQLPlatform::GetIdentifierQuoteCharacter()
{
	return "`";
}

string MySQLPlatform::GetRegexpExpression()
{
	return "RLIKE";
}

string MySQLPlatform::GetGuidExpression()
{
	return "UUID()";
}

string MySQLPlatform::GetLocateExpression( const string& str, const string& substr, int startPos )
{
	stringstream ss;

	ss << "LOCATE(" + substr << ", " + str;

	if( startPos != 0 )
	{
		ss << ", " << startPos;
	}

	ss << ")";

	return ss.str();
}

string MySQLPlatform::GetConcatExpression( const vector< string >& args )
{
	return "CONCAT(" + VectorJoin( args, ", " ) + ")";
}

string MySQLPlatform::GetDateArithmeticIntervalExpression( const string& date, const string& op, int interval, const string& unit )
{
	stringstream function;
		
	function << ( op == "+" ? "DATE_ADD" : "DATE_SUB" );
	function << "(" << date << ", INTERVAL " << interval << " " << unit << ")";

	return function.str();
}

string MySQLPlatform::GetDateDiffExpression( const string& date1, const string& date2 )
{
	return "DATEDIFF(" + date1 + ", " + date2 + ")";
}

string MySQLPlatform::GetListDatabasesSQL()
{
	return "SHOW DATABASES";
}

string MySQLPlatform::GetListTableConstraintsSQL( const string& table )
{
	return "SHOW INDEX FROM " + table;
}

string MySQLPlatform::GetListTableIndexesSQL( const string& table, const string& currentDatabase )
{
	if( !currentDatabase.empty() )
	{
		string _currentDatabase = this->QuoteStringLiteral( currentDatabase );
		string _table           = this->QuoteStringLiteral( table );

		return "SELECT"
			" TABLE_NAME   AS `Table`,"
			" NON_UNIQUE   AS `Non_unique`,"
			" INDEX_NAME   AS `Key_name`,"
			" SEQ_IN_INDEX AS `Seq_in_index`,"
			" COLUMN_NAME  AS `Column_name`,"
			" COLLATION    AS `Collation`,"
			" CARDINALITY  AS `Cardinality`,"
			" SUB_PART     AS `Sub_part`,"
			" PACKED       AS `Packed`,"
			" NULLABLE     AS `Null`,"
			" INDEX_TYPE   AS `Index_type`,"
			" COMMENT      AS `Comment`"
			" FROM information_schema.STATISTICS"
			" WHERE TABLE_NAME = " + _table + " AND TABLE_SCHEMA = " + _currentDatabase;
	}

	return "SHOW INDEX FROM " + table;
}

string MySQLPlatform::GetListViewsSQL( const string& database )
{
	return "SELECT * FROM information_schema.VIEWS WHERE TABLE_SCHEMA = " + this->QuoteStringLiteral( database );
}

string MySQLPlatform::GetListTableForeignKeysSQL( const string& table, const string& database )
{
	string tableName       = this->QuoteStringLiteral( table );
	string databaseNameSql = database.empty() ? "DATABASE()" : this->QuoteStringLiteral( database );

	string sql = "SELECT DISTINCT k.`CONSTRAINT_NAME`, k.`COLUMN_NAME`, k.`REFERENCED_TABLE_NAME`, k.`REFERENCED_COLUMN_NAME` "
		"FROM information_schema.KEY_COLUMN_USAGE k"
		" WHERE k.table_name = " + tableName +
		" AND k.table_schema = " + databaseNameSql +
		" AND k.`REFERENCED_COLUMN_NAME` is not NULL";

	return sql;
}

string MySQLPlatform::GetCreateViewSQL( const string& name, const string& sql )
{
	return "CREATE VIEW " + name + " AS " + sql;
}

string MySQLPlatform::GetDropViewSQL( const string& name )
{
	return "DROP VIEW " + name;
}

string MySQLPlatform::GetVarcharTypeDeclarationSQLSnippet( size_t length, bool fixed )
{
	stringstream ss;

	ss << ( fixed ? "CHAR" : "VARCHAR" ) << "(" << length << ")";

	return ss.str();
}

string MySQLPlatform::GetBinaryTypeDeclarationSQLSnippet( size_t length, bool fixed )
{
	stringstream ss;

	ss << ( fixed ? "BINARY" : "VARBINARY" ) << "(" << length << ")";

	return ss.str();
}

string MySQLPlatform::GetClobTypeDeclarationSQL( Column* field )
{
	size_t length = field->Length;

	if( length <= LENGTH_LIMIT_TINYTEXT )
	{
		return "TINYTEXT";
	}

	if( length <= LENGTH_LIMIT_TEXT )
	{
		return "TEXT";
	}

	if( length <= LENGTH_LIMIT_MEDIUMTEXT )
	{
		return "MEDIUMTEXT";
	}

	return "LONGTEXT";
}

string MySQLPlatform::GetDateTimeTypeDeclarationSQL( Column* fieldDeclaration )
{
	if( !fieldDeclaration->Version.empty() && fieldDeclaration->Version == "true" )
	{
		return "TIMESTAMP";
	}

	return "DATETIME";
}

string MySQLPlatform::GetDateTypeDeclarationSQL( Column* fieldDeclaration )
{
	return "DATE";
}

string MySQLPlatform::GetTimeTypeDeclarationSQL( Column* fieldDeclaration )
{
	return "TIME";
}

string MySQLPlatform::GetBooleanTypeDeclarationSQL( Column* columnDef )
{
	return "TINYINT(1)";
}

string MySQLPlatform::GetCollationFieldDeclaration( const string& collation )
{
	return this->GetColumnCollationDeclarationSQL( collation );
}

bool MySQLPlatform::PrefersIdentityColumns()
{
	return true;
}

bool MySQLPlatform::SupportsIdentityColumns()
{
	return true;
}

bool MySQLPlatform::SupportsInlineColumnComments()
{
	return true;
}

bool MySQLPlatform::SupportsColumnCollation()
{
	return true;
}

string MySQLPlatform::GetListTablesSQL()
{
	//return "SHOW TABLES";
	return "SELECT TABLE_NAME AS TableName FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_SCHEMA = DATABASE()";
}

string MySQLPlatform::GetListTableColumnsSQL( const string& _table, const string& _database )
{
	string table    = this->QuoteStringLiteral( _table );
	string database = "DATABASE()";

	if( !_database.empty() )
	{
		database = this->QuoteStringLiteral( _database );
	}

	return "SELECT"
			" COLUMN_NAME AS Field,"
			" COLUMN_TYPE AS Type,"
			" IS_NULLABLE AS `Null`,"
			" COLUMN_KEY AS `Key`,"
			" COLUMN_DEFAULT AS `Default`,"
			" EXTRA AS Extra,"
			" COLUMN_COMMENT AS Comment,"
			" CHARACTER_SET_NAME AS CharacterSet,"
			" COLLATION_NAME AS Collation"
		" FROM information_schema.COLUMNS"
		" WHERE TABLE_SCHEMA = " + database + " AND TABLE_NAME = " + table;
}

string MySQLPlatform::GetCreateDatabaseSQL( const string& name )
{
	return "CREATE DATABASE " + name;
}

string MySQLPlatform::GetDropDatabaseSQL( const string& name )
{
	return "DROP DATABASE " + name;
}

AbstractPlatform::StringArray MySQLPlatform::_getCreateTableSQL( const string& tableName, const vector< Column* >& columns, const TableOptions& options )
{
	StringArray sql;
	string      queryFields = this->GetColumnDeclarationListSQL( columns );

	if( !options.UniqueConstraints.empty() )
	{
		for( const auto& iter : options.UniqueConstraints )
		{
			queryFields += ", " + this->GetUniqueConstraintDeclarationSQL( iter.first, iter.second );
		}
	}

	if( !options.Indexes.empty() )
	{
		for( const auto& iter : options.Indexes )
		{
			queryFields += ", " + this->GetIndexDeclarationSQL( iter.first, iter.second );
		}
	}

	if( !options.Primary.empty() )
	{
		StringArray keyColumns;

		for( const auto& iter : options.Primary )
		{
			keyColumns.push_back( iter );
		}

		queryFields += ", PRIMARY KEY(" + VectorJoin( keyColumns, ", " ) + ")";
	}

	string query = "CREATE ";

	if( options.Temporary )
	{
		query += "TEMPORARY ";
	}

	query += "TABLE " + tableName + " (" + queryFields + ") ";
	query += this->BuildTableOptions( options );
	query += this->BuildPartitionOptions( options );

	sql.push_back( query );

	string engine = "INNODB";

	if( !options.Engine.empty() )
	{
		engine = strtoupper( options.Engine );
	}

	if( !options.ForeignKeys.empty() && engine == "INNODB" )
	{
		for( const auto& iter : options.ForeignKeys )
		{
			sql.push_back( this->GetCreateForeignKeySQL( iter, tableName ) );
		}
	}

	return sql;
}

string MySQLPlatform::GetDefaultValueDeclarationSQL( Column* field )
{
	if( field->Type->GetID() == ColumnType::TEXT || field->Type->GetID() == ColumnType::BLOB )
	{
		field->Default = "NULL";
	}

	return AbstractPlatform::GetDefaultValueDeclarationSQL( field );
}

string MySQLPlatform::BuildTableOptions( TableOptions options )
{
	StringArray tableOptions;

	if( options.Charset.empty() )
	{
		options.Charset = "utf8";
	}

	tableOptions.push_back( "DEFAULT CHARACTER SET " + options.Charset );

	if( options.Collate.empty() )
	{
		options.Collate = "utf8_unicode_ci";
	}

	tableOptions.push_back( "COLLATE " + options.Collate );

	if( options.Engine.empty() )
	{
		options.Engine = "InnoDB";
	}

	tableOptions.push_back( "ENGINE = " + options.Engine );

	if( !options.AutoIncrement.empty() )
	{
		tableOptions.push_back( "AUTO_INCREMENT = " + options.AutoIncrement );
	}

	if( !options.Comment.empty() )
	{
		tableOptions.push_back( "COMMENT = " + this->QuoteStringLiteral( options.Comment ) );
	}

	if( !options.RowFormat.empty() )
	{
		tableOptions.push_back( "ROW_FORMAT = " + options.RowFormat );
	}

	return VectorJoin( tableOptions, " " );
}

string MySQLPlatform::BuildPartitionOptions( const TableOptions& options )
{
	return !options.PartitionOptions.empty() ? " " + options.PartitionOptions : "";
}

MySQLPlatform::StringArray MySQLPlatform::GetAlterTableSQL( TableDiff* diff )
{
	StringArray queryParts;

	if( !diff->GetNewName().empty() )
	{
		queryParts.push_back( "RENAME TO `" + diff->GetNewName() + "`" );
	}

	for( Column* col : diff->AddedColumns )
	{
		queryParts.push_back( "ADD " + this->GetColumnDeclarationSQL( col ) );
	}

	for( const auto& iter : diff->RemovedColumns )
	{
		queryParts.push_back( "DROP " + iter->GetQuotedName() );
	}

	for( const auto& iter : diff->ChangedColumns )
	{
		ColumnDiff*  columnDiff  = iter;
		Column*      column      = columnDiff->Column;

		// Don"t propagate default value changes for unsupported column types.
		if( columnDiff->HasChanged( "default" ) && columnDiff->ChangedProperties.size() == 1
			&& ( column->Type->GetID() == ColumnType::TEXT || column->Type->GetID() == ColumnType::BLOB ) )
		{
			continue;
		}

		queryParts.push_back( "CHANGE `" + ( columnDiff->GetOldColumnName() ) + "` " + this->GetColumnDeclarationSQL( column ) );
	}

	for( const auto& iter : diff->RenamedColumns )
	{
		Column* column       = iter;
		string oldColumnName = iter->GetName();

		queryParts.push_back( "CHANGE `" + oldColumnName + "` " + this->GetColumnDeclarationSQL( column ) );
	}

	for( auto iter = diff->AddedIndexes.begin(); iter != diff->AddedIndexes.end(); ++iter )
	{
		if( !( *iter )->GetOption( "primary" ).empty() || ( *iter )->GetName() == "primary" )
		{
			StringArray keyColumns = ( *iter )->GetColumns();

			queryParts.push_back( "ADD PRIMARY KEY (" + VectorJoin( keyColumns, ", " ) + ")" );
		}
	}

	StringArray sql;

	if( queryParts.size() > 0 )
	{
		sql.push_back( "ALTER TABLE `" + diff->GetName() + "` " + VectorJoin( queryParts, ", " ) );
	}

	for( const string& str : this->GetPreAlterTableIndexForeignKeySQL( diff ) )
	{
		sql.push_back( str );
	}

	for( const string& str : this->GetPostAlterTableIndexForeignKeySQL( diff ) )
	{
		sql.push_back( str );
	}

	return sql;
}

MySQLPlatform::StringArray MySQLPlatform::GetPreAlterTableIndexForeignKeySQL( TableDiff* diff )
{
	StringArray sql;
	string      table = "`" + diff->GetName() + "`";

	for( Index* changedIndex : diff->ChangedIndexes )
	{
		StringArray sql1 = this->GetPreAlterTableAlterPrimaryKeySQL( diff, changedIndex );

		sql.insert( sql.end(), sql1.begin(), sql1.end() );
	}

	auto iter = diff->RemovedIndexes.begin();

	while( iter != diff->RemovedIndexes.end() )
	{
		Index* remIndex = *iter;

		StringArray sql1 = this->GetPreAlterTableAlterPrimaryKeySQL( diff, remIndex );

		sql.insert( sql.end(), sql1.begin(), sql1.end() );

		for( auto iter2 = diff->AddedIndexes.begin(); iter2 != diff->AddedIndexes.end(); ++iter2 )
		{
			Index* addIndex = *iter;

			if( remIndex->GetColumns() == addIndex->GetColumns() )
			{
				string indexClause = "INDEX " + addIndex->GetName();

				if( addIndex->IsPrimary() )
				{
					indexClause = "PRIMARY KEY";
				}
				else if( addIndex->IsUnique() )
				{
					indexClause = "UNIQUE INDEX " + addIndex->GetName();
				}

				string query;

				query = "ALTER TABLE " + table + " DROP INDEX " + remIndex->GetName() + ", ";
				query += "ADD " + indexClause;
				query += " (" + this->GetIndexFieldDeclarationListSQL( addIndex->GetQuotedColumns() ) + ")";

				sql.push_back( query );

				iter = diff->RemovedIndexes.erase( iter );
				diff->AddedIndexes.erase( iter2 );

				break;
			}
			else
			{
				++iter;
			}
		}
	}

	string engine = "INNODB";

	if( diff->GetFromTable() != nullptr )
	{
		engine = strtoupper( diff->GetFromTable()->GetOptions()->Engine );
	}

	if( engine != "INNODB" )
	{
		diff->AddedForeignKeys.clear();
		diff->ChangedForeignKeys.clear();
		diff->RemovedForeignKeys.clear();
	}

	StringArray sql1 = this->GetPreAlterTableAlterIndexForeignKeySQL( diff );
	StringArray sql2 = __super::GetPreAlterTableIndexForeignKeySQL( diff );
	StringArray sql3 = this->GetPreAlterTableRenameIndexForeignKeySQL( diff );

	sql.insert( sql.end(), sql1.begin(), sql1.end() );
	sql.insert( sql.end(), sql2.begin(), sql2.end() );
	sql.insert( sql.end(), sql3.begin(), sql3.end() );

	return sql;
}

MySQLPlatform::StringArray MySQLPlatform::GetPreAlterTableAlterPrimaryKeySQL( TableDiff* diff, Index* index )
{
	StringArray sql;

	if( !index->IsPrimary() || diff->GetFromTable() == nullptr )
	{
		return sql;
	}

	string tableName = "`" + diff->GetName() + "`";

	// Dropping primary keys requires to unset autoincrement attribute on the particular column first.
	for( const string& columnName : index->GetColumns() )
	{
		Column* column = diff->GetFromTable()->GetColumn( columnName );

		if( column->GetAutoincrement() == true )
		{
			column->SetAutoincrement( false );

			sql.push_back( "ALTER TABLE " + tableName + " MODIFY " + this->GetColumnDeclarationSQL( column ) );

			// original autoincrement information might be needed later on by other parts of the table alteration
			column->SetAutoincrement( true );
		}
	}

	return sql;
}

MySQLPlatform::StringArray MySQLPlatform::GetPreAlterTableAlterIndexForeignKeySQL( TableDiff* diff )
{
	StringArray sql;

	string tableName = "`" + diff->GetName() + "`";

	for( Index* changedIndex : diff->ChangedIndexes )
	{
		Table* table        = diff->GetFromTable();

		if( table != nullptr && changedIndex->IsPrimary() )
		{
			const StringArray& columns = table->GetPrimaryKeyColumns();

			for( const string& columnName : columns )
			{
				Column* column = table->GetColumn( columnName );

				const StringArray& cols = changedIndex->GetColumns();

				if( column->GetAutoincrement() && find( cols.begin(), cols.end(), columnName ) == cols.end() )
				{
					column->SetAutoincrement( false );

					sql.push_back( "ALTER TABLE " + tableName + " MODIFY " + this->GetColumnDeclarationSQL( column ) );

					column->SetAutoincrement( true );
				}
			}
		}
	}

	return sql;
}

MySQLPlatform::StringArray MySQLPlatform::GetPreAlterTableRenameIndexForeignKeySQL( TableDiff* diff )
{
	StringArray sql;
	string tableName = "`" + diff->GetName() + "`";

	const vector< ForeignKeyConstraint* >& keys = this->GetRemainingForeignKeyConstraintsRequiringRenamedIndexes( diff );

	for( ForeignKeyConstraint* foreignKey : keys )
	{
		const auto& _keys = diff->ChangedForeignKeys;

		for( const auto& iter : _keys )
		{
			if( iter == foreignKey )
			{
				sql.push_back( this->GetDropForeignKeySQL( foreignKey->GetName(), tableName ) );
			}
		}
	}

	return sql;
}

vector< ForeignKeyConstraint* > MySQLPlatform::GetRemainingForeignKeyConstraintsRequiringRenamedIndexes( TableDiff* diff )
{
	vector< ForeignKeyConstraint* > foreignKeys;

	if( diff->RenamedIndexes.empty() || diff->GetFromTable() == nullptr )
	{
		return foreignKeys;
	}

	vector< ForeignKeyConstraint* > remainingForeignKeys;

	const auto& keys = diff->GetFromTable()->GetForeignKeys();

	for( const auto& iter : keys )
	{
		bool _found = false;

		for( ForeignKeyConstraint* k : diff->RemovedForeignKeys )
		{
			if( k == iter )
			{
				_found = true;

				break;
			}
		}

		if( !_found )
		{
			remainingForeignKeys.push_back( iter );
		}
	}

	for( ForeignKeyConstraint* foreignKey : remainingForeignKeys )
	{
		for( Index* index : diff->RenamedIndexes )
		{
			if( foreignKey->IntersectsIndexColumns( index ) )
			{
				foreignKeys.push_back( foreignKey );

				break;
			}
		}
	}

	return foreignKeys;
}

MySQLPlatform::StringArray MySQLPlatform::GetPostAlterTableIndexForeignKeySQL( TableDiff* diff )
{
	StringArray result;

	StringArray a1 = __super::GetPostAlterTableIndexForeignKeySQL( diff );
	StringArray a2 = this->GetPostAlterTableRenameIndexForeignKeySQL( diff );

	result.insert( result.end(), a1.begin(), a1.end() );
	result.insert( result.end(), a2.begin(), a2.end() );

	return result;
}

MySQLPlatform::StringArray MySQLPlatform::GetPostAlterTableRenameIndexForeignKeySQL( TableDiff* diff )
{
	StringArray sql;

	string tableName = "`" + ( !diff->GetNewName().empty() ? diff->GetNewName() : diff->GetName() ) + "`";

	const auto& idx = this->GetRemainingForeignKeyConstraintsRequiringRenamedIndexes( diff );

	for( const auto& foreignKey : idx )
	{
		for( const auto& iter : diff->ChangedForeignKeys )
		{
			if( iter == foreignKey )
			{
				sql.push_back( this->GetCreateForeignKeySQL( foreignKey, tableName ) );

				break;
			}
		}
	}

	return sql;
}

string MySQLPlatform::GetCreateIndexSQLFlags( Index* index )
{
	string type = "";

	if( index->IsUnique() )
	{
		type += "UNIQUE ";
	}
	else if( index->HasFlag( "fulltext" ) )
	{
		type += "FULLTEXT ";
	}
	else if( index->HasFlag( "spatial" ) )
	{
		type += "SPATIAL ";
	}

	return type;
}

string MySQLPlatform::GetIntegerTypeDeclarationSQL( Column* columnDef )
{
	return "INT" + this->_getCommonIntegerTypeDeclarationSQL( columnDef );
}

string MySQLPlatform::GetBigIntTypeDeclarationSQL( Column* columnDef )
{
	return "BIGINT" + this->_getCommonIntegerTypeDeclarationSQL( columnDef );
}

string MySQLPlatform::GetSmallIntTypeDeclarationSQL( Column* columnDef )
{
	return "SMALLINT" + this->_getCommonIntegerTypeDeclarationSQL( columnDef );
}

string MySQLPlatform::_getCommonIntegerTypeDeclarationSQL( Column* columnDef )
{
	string autoinc;

	if( columnDef->AutoIncrement )
	{
		autoinc = " AUTO_INCREMENT";
	}

	string _unsigned = columnDef->Unsigned ? " UNSIGNED" : "";

	return _unsigned + autoinc;
}

string MySQLPlatform::GetAdvancedForeignKeyOptionsSQL( ForeignKeyConstraint* foreignKey )
{
	string query;

	if( foreignKey->HasOption( "match" ) )
	{
		query += " MATCH " + foreignKey->GetOption( "match" );
	}

	query += __super::GetAdvancedForeignKeyOptionsSQL( foreignKey );

	return query;
}

string MySQLPlatform::GetDropIndexSQL( Index* index, Table* table )
{
	string indexName = index->GetQuotedName();
	string tableName = table->GetQuotedName();

	if( index->IsPrimary() )
	{
		// mysql primary keys are always named "PRIMARY",
		// so we cannot use them in statements because of them being keyword.
		return this->GetDropPrimaryKeySQL( tableName );
	}

	return "DROP INDEX " + indexName + " ON " + tableName;
}

string MySQLPlatform::GetDropIndexSQL( const string& index, const string& tableName )
{
	return "DROP INDEX " + index + " ON " + tableName;
}

string MySQLPlatform::GetDropPrimaryKeySQL( const string& table )
{
	return "ALTER TABLE " + table + " DROP PRIMARY KEY";
}

string MySQLPlatform::GetSetTransactionIsolationSQL( int level )
{
	return "SET SESSION TRANSACTION ISOLATION LEVEL " + this->_getTransactionIsolationLevelSQL( level );
}

string MySQLPlatform::GetReadLockSQL()
{
	return "LOCK IN SHARE MODE";
}

size_t MySQLPlatform::GetVarcharMaxLength()
{
	return 65535;
}

size_t MySQLPlatform::GetBinaryMaxLength()
{
	return 65535;
}


string MySQLPlatform::GetDropTemporaryTableSQL( Table* table )
{
	return "DROP TEMPORARY TABLE " + table->GetQuotedName();
}

string MySQLPlatform::GetBlobTypeDeclarationSQL( Column* field )
{
	if( field->Length > 0 )
	{
		size_t length = field->Length;

		if( length <= LENGTH_LIMIT_TINYBLOB )
		{
			return "TINYBLOB";
		}

		if( length <= LENGTH_LIMIT_BLOB )
		{
			return "BLOB";
		}

		if( length <= LENGTH_LIMIT_MEDIUMBLOB )
		{
			return "MEDIUMBLOB";
		}
	}

	return "LONGBLOB";
}

string MySQLPlatform::QuoteStringLiteral( const string& str )
{
	// MySQL requires backslashes to be escaped aswell.
	return __super::QuoteStringLiteral( str_replace( "\\", "\\\\", str ) );
}

void MySQLPlatform::InitializeTypeMappings()
{
	this->TypeMapping =
	{
        { "bool",       "boolean",      },
        { "tinyint",    "boolean",		},
        { "smallint",   "smallint",		},
        { "mediumint",  "integer",		},
        { "int",        "integer",		},
        { "integer",    "integer",      },
        { "bigint",     "bigint",		},
        { "tinytext",   "text",			},
        { "mediumtext", "text",			},
        { "longtext",   "text",			},
        { "text",       "text",			},
        { "varchar",    "string",		},
        { "string",     "string",		},
        { "char",       "string",		},
        { "date",       "date",			},
        { "datetime",   "datetime",		},
        { "timestamp",  "datetime",		},
        { "time",       "time",			},
        { "float",      "float",		},
        { "double",     "float",		},
        { "real",       "float",		},
        { "decimal",    "decimal",		},
        { "numeric",    "decimal",		},
        { "year",       "date",			},
        { "longblob",   "blob",			},
        { "blob",       "blob",			},
        { "mediumblob", "blob",			},
        { "tinyblob",   "blob",			},
        { "binary",     "binary",		},
        { "varbinary",  "binary",		},
        { "set",        "simple_array", },
	};
}
