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
#include "Table.h"

Table::Table( AbstractAsset* parent, const string& tableName ) : AbstractAsset( parent )
{
	this->SetName( tableName );
}

void Table::SetPrimaryKey( const StringArray& columns, const string& indexName )
{
	this->AddIndex( this->_createIndex( columns, indexName, true, true ) );

	for( const string& columnName : columns )
	{
		Column* column = this->GetColumn( columnName );

		if( column )
		{
			column->SetNotNull( true );
		}
	}
}

void Table::AddIndex( const StringArray& columnNames, string indexName, const Flags& flags, const Options& options )
{
	if( indexName.empty() )
	{
		StringArray columnNamesCopy;

		columnNamesCopy.push_back( this->GetName() );

		indexName = this->_generateIdentifierName( columnNamesCopy, "idx", MaxIdentifierLength );
	}

	this->AddIndex( this->_createIndex( columnNames, indexName, false, false, flags, options ) );
}

void Table::DropPrimaryKey()
{
	this->DropIndex( this->_primaryKeyName );

	this->_primaryKeyName = string();
}

void Table::DropIndex( string indexName )
{
	const string& normalizedIndexName = this->NormalizeIdentifier( indexName );

	for( auto iter = this->_indexes.begin(); iter != this->_indexes.end(); ++iter )
	{
		if( (*iter)->GetName() == indexName || (*iter)->GetName() == normalizedIndexName )
		{
			this->_indexes.erase( iter );

			return;
		}
	}

	throw new SchemaException::IndexDoesNotExist( normalizedIndexName, this->GetName() );
}

void Table::AddUniqueIndex( const StringArray& columnNames, string indexName, const Options& options )
{
	if( indexName.empty() )
	{
		StringArray columnNamesCopy;

		columnNamesCopy.push_back( this->GetName() );

		indexName = this->_generateIdentifierName( columnNamesCopy, "uniq", MaxIdentifierLength );
	}

	this->AddIndex( this->_createIndex( columnNames, indexName, true, false, Flags(), options ) );
}

void Table::RenameIndex( const string& _oldIndexName, const string& _newIndexName )
{
	string oldIndexName = this->NormalizeIdentifier( _oldIndexName );
	string normalizedNewIndexName = this->NormalizeIdentifier( _newIndexName );

	if( oldIndexName == normalizedNewIndexName )
	{
		return;
	}

	if( !this->HasIndex( oldIndexName ) )
	{
		throw new SchemaException::IndexDoesNotExist( oldIndexName, this->GetName() );
	}

	if( this->HasIndex( normalizedNewIndexName ) )
	{
		throw new SchemaException::IndexAlreadyExists( normalizedNewIndexName, this->GetName() );
	}

	Index* oldIndex = this->GetIndex( oldIndexName );

	if( oldIndex->IsPrimary() )
	{
		this->DropPrimaryKey();

		this->SetPrimaryKey( oldIndex->GetColumns(), _newIndexName );

		return;
	}

	this->DropIndex( _oldIndexName );

	if( oldIndex->IsUnique() )
	{
		return this->AddUniqueIndex( oldIndex->GetColumns(), _newIndexName, oldIndex->GetOptions() );
	}

	this->AddIndex( oldIndex->GetColumns(), _newIndexName, oldIndex->GetFlags(), oldIndex->GetOptions() );
}

bool Table::ColumnsAreIndexed( const StringArray& columnsNames )
{
	for( const Index* index : this->GetIndexes() )
	{
		if( index->SpansColumns( columnsNames ) )
		{
			return true;
		}
	}

	return false;
}

Index* Table::_createIndex( const StringArray& columnNames, const string& indexName, bool isUnique, bool isPrimary, const Index::Flags& flags, const Index::Options& options )
{
	for( const auto& columnName : columnNames )
	{
		if( !this->HasColumn( columnName ) )
		{
			throw new SchemaException::ColumnDoesNotExist( columnName, this->GetName() );
		}
	}

	return new Index( this, indexName, columnNames, isUnique, isPrimary, flags, options );
}

Column* Table::AddColumn( const string& columnName, const string& typeName, const Index::Options& options )
{
	Column* column = new Column( this, columnName, ColumnType::GetType( typeName ) );

	this->AddColumn( column );

	return column;
}

void Table::DropColumn( const string& columnName )
{
	const string& normalizedName = this->NormalizeIdentifier( columnName );

	for( auto iter = this->_columns.begin(); iter != this->_columns.end(); ++iter )
	{
		if( (*iter)->GetName() == columnName || ( *iter )->GetName() == normalizedName )
		{
			this->_columns.erase( iter );
		}
	}
}

void Table::AddForeignKeyConstraint( Table* foreignTable, const StringArray& localColumnNames, const StringArray& foreignColumnNames, const Options& options, const string& constraintName )
{
	StringArray localColumnNamesCopy( localColumnNames );

	localColumnNamesCopy.push_back( this->GetName() );

	string constraintNewName = !constraintName.empty() ? constraintName : this->_generateIdentifierName( localColumnNamesCopy, "fk", MaxIdentifierLength );

	this->AddNamedForeignKeyConstraint( constraintNewName, foreignTable, localColumnNames, foreignColumnNames, options );
}

void Table::AddUnnamedForeignKeyConstraint( Table* foreignTable, const StringArray& localColumnNames, const StringArray& foreignColumnNames, const Options& options )
{
	this->AddForeignKeyConstraint( foreignTable, localColumnNames, foreignColumnNames, options );
}

void Table::AddNamedForeignKeyConstraint( const string& name, Table* foreignTable, const StringArray& localColumnNames, const StringArray& foreignColumnNames, Options options )
{
	for( const string& columnName : foreignColumnNames )
	{
		if( !foreignTable->HasColumn( columnName ) )
		{
			throw new SchemaException::ColumnDoesNotExist( columnName, foreignTable->GetName() );
		}
	}

	for( const string& columnName : localColumnNames )
	{
		if( !this->HasColumn( columnName ) )
		{
			throw new SchemaException::ColumnDoesNotExist( columnName, this->GetName() );
		}
	}

	ForeignKeyConstraint* constraint = new ForeignKeyConstraint( this, localColumnNames, foreignTable, foreignColumnNames, name, options );

	this->AddForeignKeyConstraint( constraint );
}

void Table::AddForeignKeyConstraint( ForeignKeyConstraint* constraint )
{
	string name;

	constraint->SetLocalTable( this );

	if( constraint->GetName().length() > 0 )
	{
		name = constraint->GetName();
	}
	else
	{
		StringArray columns( constraint->GetLocalColumns() );

		columns.push_back( this->GetName() );

		name = this->_generateIdentifierName( columns, "fk", MaxIdentifierLength );
	}

	name = this->NormalizeIdentifier( name );

	this->_fkConstraints.push_back( constraint );

	StringArray columns( constraint->GetColumns() );

	columns.push_back( this->GetName() );

	const string& indexName = this->_generateIdentifierName( columns, "idx", MaxIdentifierLength );

	Index* indexCandidate = this->_createIndex( constraint->GetColumns(), indexName, false, false );

	for( Index* index : this->_indexes )
	{
		if( indexCandidate->IsFullfilledBy( index ) )
		{
			delete indexCandidate;

			return;
		}
	}

	this->AddIndex( indexCandidate );

	this->implicitIndexes[ this->NormalizeIdentifier( indexName ) ] = indexCandidate;
}

void Table::AddColumn( Column* column )
{
	for( Column* col : this->_columns )
	{
		if( col == column )
		{
			throw new SchemaException::ColumnAlreadyExists( this->GetName(), this->NormalizeIdentifier( column->GetName() ) );
		}
	}

	this->_columns.push_back( column );
}

void Table::AddIndex( Index* indexCandidate )
{
	string indexName = this->NormalizeIdentifier( indexCandidate->GetName() );

	StringArray replacedImplicitIndexes;

	for( const auto& iter : this->implicitIndexes )
	{
		string name = iter.first;
		Index* implicitIndex = iter.second;

		if( implicitIndex->IsFullfilledBy( indexCandidate ) && this->HasIndex( name ) )
		{
			replacedImplicitIndexes.push_back( name );
		}
	}

	if( ( this->HasIndex( indexName ) && find( replacedImplicitIndexes.begin(), replacedImplicitIndexes.end(), indexName ) == replacedImplicitIndexes.end() ) ||
		( !this->_primaryKeyName.empty() && indexCandidate->IsPrimary() )
		)
	{
		throw new SchemaException::IndexAlreadyExists( indexName, this->GetName() );
	}

	for( const string& name : replacedImplicitIndexes )
	{
		this->DropIndex( name );
		this->implicitIndexes.erase( name );
	}

	if( indexCandidate->IsPrimary() )
	{
		this->_primaryKeyName = indexName;
	}

	this->_indexes.push_back( indexCandidate );
}

vector< Column* > Table::GetColumns() const
{
	return this->_columns;
}

bool Table::HasColumn( Column* column ) const
{
	for( Column* col : this->_columns )
	{
		if( col == column )
		{
			return true;
		}
	}

	return false;
}

bool Table::HasColumn( const string& columnName ) const
{
	const string& normalizedName = this->NormalizeIdentifier( columnName );

	for( Column* col : this->_columns )
	{
		if( col->GetName() == columnName || col->GetName() == normalizedName )
		{
			return true;
		}
	}

	return false;
}

Column* Table::GetColumn( const string& columnName ) const
{
	const string& normalizedName = this->NormalizeIdentifier( columnName );

	for( Column* col : this->_columns )
	{
		if( col->GetName() == columnName || col->GetName() == normalizedName )
		{
			return col;
		}
	}

	throw new SchemaException::ColumnDoesNotExist( columnName, this->GetName() );
}

Index* Table::GetPrimaryKey() const
{
	if( !this->HasPrimaryKey() )
	{
		return nullptr;
	}

	return this->GetIndex( this->_primaryKeyName );
}

AbstractAsset::StringArray Table::GetPrimaryKeyColumns() const
{
	if( !this->HasPrimaryKey() )
	{
		throw new exception( ( "Table " + this->GetName() + " has no primary key" ).c_str() );
	}

	return this->GetPrimaryKey()->GetColumns();
}

bool Table::HasPrimaryKey() const
{
	return this->HasIndex( this->_primaryKeyName );
}

bool Table::HasIndex( const Index* index ) const
{
	for( const Index* idx : this->_indexes )
	{
		if( idx == index )
		{
			return true;
		}
	}

	return false;
}

bool Table::HasIndex( const string& indexName ) const
{
	const string& normalizedName = this->NormalizeIdentifier( indexName );

	for( Index* index : this->_indexes )
	{
		if( index->GetName() == indexName || index->GetName() == normalizedName )
		{
			return true;
		}
	}

	return false;
}

Index* Table::GetIndex( const string& indexName ) const
{
	string normalizedName = this->NormalizeIdentifier( indexName );

	for( Index* index : this->_indexes )
	{
		if( index->GetName() == indexName || index->GetName() == normalizedName )
		{
			return index;
		}
	}

	throw new SchemaException::IndexDoesNotExist( normalizedName, this->GetName() );

	return nullptr;
}

vector< Index* > Table::GetIndexes() const
{
	return this->_indexes;
}

vector< ForeignKeyConstraint* > Table::GetForeignKeys() const
{
	return this->_fkConstraints;
}

TableOptions* Table::GetOptions()
{
	return &this->_options;
}

string Table::NormalizeIdentifier( const string& identifier ) const
{
	return this->TrimQuotes( strtolower( identifier ) );
}
