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
#include "Index.h"

Index::Index( AbstractAsset* parent, const string & indexName, const StringArray& columns, bool isUnique, bool isPrimary, Flags flags, Options options ) :
	AbstractAsset( parent ),
	_isUnique( false ),
	_isPrimary( false )
{
	this->SetName( indexName );

	this->_isUnique = isUnique || isPrimary;
	this->_isPrimary = isPrimary;

	this->options = options;

	for( const auto& column : columns )
	{
		this->_addColumn( column );
	}

	for( const auto& flag : flags )
	{
		this->AddFlag( flag );
	}
}

void Index::_addColumn( const string& column )
{
	this->_columns.push_back( column );
}

AbstractAsset::StringArray Index::GetColumns() const
{
	return this->_columns;
}

AbstractAsset::StringArray Index::GetQuotedColumns() const
{
	vector< string > columns;

	for( string column : this->_columns )
	{
		columns.push_back( "`" + column + "`" );
	}

	return columns;
}

AbstractAsset::StringArray Index::GetUnquotedColumns() const
{
	StringArray columns;

	for( const auto& col : this->GetColumns() )
	{
		columns.push_back( this->TrimQuotes( col ) );
	}

	return columns;
}

bool Index::IsSimpleIndex() const
{
	return !this->_isPrimary && !this->_isUnique;
}

bool Index::IsUnique() const
{
	return this->_isUnique;
}

bool Index::IsPrimary() const
{
	return this->_isPrimary;
}

bool Index::HasColumnAtPosition( const string& _columnName, size_t pos )
{
	string columnName = this->TrimQuotes( strtolower( _columnName ) );

	StringArray indexColumns;

	for( const string& str : this->GetUnquotedColumns() )
	{
		indexColumns.push_back( strtolower( str ) );
	}

	size_t _pos = 0;

	for( const auto& _name : indexColumns )
	{
		if( _pos == pos )
		{
			return true;
		}

		++_pos;
	}

	return false;
}

bool Index::SpansColumns( const StringArray& columnNames ) const
{
	StringArray columns = this->GetColumns();
	size_t      numberOfColumns = columns.size();
	bool        sameColumns = true;

	for( size_t i = 0; i < numberOfColumns; ++i )
	{
		if( columnNames.size() <= i || this->TrimQuotes( strtolower( columns[ i ] ) ) != this->TrimQuotes( strtolower( columnNames[ i ] ) ) )
		{
			sameColumns = false;
		}
	}

	return sameColumns;
}

bool Index::IsFullfilledBy( Index* other ) const
{
	if( other->GetColumns().size() != this->GetColumns().size() )
	{
		return false;
	}

	bool sameColumns = this->SpansColumns( other->GetColumns() );

	if( sameColumns )
	{
		if( !this->SamePartialIndex( other ) )
		{
			return false;
		}

		if( !this->IsUnique() && !this->IsPrimary() )
		{
			return true;
		}

		if( other->IsPrimary() != this->IsPrimary() )
		{
			return false;
		}

		if( other->IsUnique() != this->IsUnique() )
		{
			return false;
		}

		return true;
	}

	return false;
}

bool Index::Overrules( Index* other ) const
{
	if( other->IsPrimary() )
	{
		return false;
	}
	else if( this->IsSimpleIndex() && other->IsUnique() )
	{
		return false;
	}

	if( this->SpansColumns( other->GetColumns() ) && ( this->IsPrimary() || this->IsUnique() ) && this->SamePartialIndex( other ) )
	{
		return true;
	}

	return false;
}

AbstractAsset::StringArray Index::GetFlags() const
{
	StringArray flags;

	for( const auto& iter : this->_flags )
	{
		flags.push_back( iter.first );
	}

	return flags;
}

void Index::AddFlag( const string& flag )
{
	this->_flags[ strtolower( flag ) ] = true;
}

bool Index::HasFlag( const string& flag ) const
{
	return this->_flags.count( strtolower( flag ) ) > 0;
}

void Index::RemoveFlag( const string& flag )
{
	this->_flags.erase( strtolower( flag ) );
}

bool Index::HasOption( const string& name ) const
{
	return this->options.count( strtolower( name ) ) > 0;
}

string Index::GetOption( const string& _name ) const
{
	string name = strtolower( _name );

	for( const auto& iter : this->options )
	{
		if( iter.first == name )
		{
			return iter.second;
		}
	}

	return string();
}

AbstractAsset::Options Index::GetOptions() const
{
	return this->options;
}

bool Index::SamePartialIndex( Index* other ) const
{
	if( this->HasOption( "where" ) && other->HasOption( "where" ) && this->GetOption( "where" ) == other->GetOption( "where" ) )
	{
		return true;
	}

	if( !this->HasOption( "where" ) && !other->HasOption( "where" ) )
	{
		return true;
	}

	return false;
}
