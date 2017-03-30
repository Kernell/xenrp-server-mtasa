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
#include "ForeignKeyConstraint.h"

ForeignKeyConstraint::ForeignKeyConstraint( AbstractAsset* parent, const StringArray & localColumnNames, Table* foreignTable, const StringArray& foreignColumnNames, const string& name, const Options& options ) :
	AbstractAsset( parent )
{
	this->SetName( name );

	if( !localColumnNames.empty() )
	{
		for( const string& name : localColumnNames )
		{
			this->_localColumnNames[ name ] = name;
		}
	}

	this->_foreignTable = foreignTable;

	for( const string& name : foreignColumnNames )
	{
		this->_foreignColumnNames[ name ] = name;
	}

	this->_options = options;
}

string ForeignKeyConstraint::GetLocalTableName() const
{
	return this->_localTable->GetName();
}

void ForeignKeyConstraint::SetLocalTable( Table* table )
{
	this->_localTable = table;
}

Table* ForeignKeyConstraint::GetLocalTable() const
{
	return this->_localTable;
}

AbstractAsset::StringArray ForeignKeyConstraint::GetLocalColumns() const
{
	StringArray columns;

	for( const auto& iter : this->_localColumnNames )
	{
		columns.push_back( iter.first );
	}

	return columns;
}

AbstractAsset::StringArray ForeignKeyConstraint::GetQuotedLocalColumns() const
{
	StringArray columns;

	for( const auto& iter : this->_localColumnNames )
	{
		columns.push_back( "`" + iter.first + "`" );
	}

	return columns;
}

AbstractAsset::StringArray ForeignKeyConstraint::GetUnquotedLocalColumns() const
{
	StringArray columns;

	for( const auto& col : this->GetLocalColumns() )
	{
		columns.push_back( this->TrimQuotes( col ) );
	}

	return columns;
}

AbstractAsset::StringArray ForeignKeyConstraint::GetUnquotedForeignColumns() const
{
	StringArray columns;

	for( const auto& col : this->GetForeignColumns() )
	{
		columns.push_back( this->TrimQuotes( col ) );
	}

	return columns;
}

AbstractAsset::StringArray ForeignKeyConstraint::GetColumns() const
{
	return this->GetLocalColumns();
}

AbstractAsset::StringArray ForeignKeyConstraint::GetQuotedColumns() const
{
	return this->GetQuotedLocalColumns();
}

string ForeignKeyConstraint::GetForeignTableName() const
{
	return this->_foreignTable->GetName();
}

string ForeignKeyConstraint::GetUnqualifiedForeignTableName() const
{
	StringArray parts;
	string _part;

	for( const char& iter : this->_foreignTable->GetName() )
	{
		if( iter == '.' )
		{
			parts.push_back( _part );
			_part.clear();
		}
		else
		{
			_part.push_back( iter );
		}
	}

	return strtolower( *parts.rbegin() );
}

string ForeignKeyConstraint::GetQuotedForeignTableName() const
{
	return "`" + this->_foreignTable->GetName() + "`";
}

AbstractAsset::StringArray ForeignKeyConstraint::GetForeignColumns() const
{
	StringArray names;

	for( const auto& str : this->_foreignColumnNames )
	{
		names.push_back( str.first );
	}

	return names;
}

AbstractAsset::StringArray ForeignKeyConstraint::GetQuotedForeignColumns() const
{
	StringArray columns;

	for( const auto& column : this->_foreignColumnNames )
	{
		columns.push_back( "`" + column.first + "`" );
	}

	return columns;
}

bool ForeignKeyConstraint::HasOption( const string& name ) const
{
	return this->_options.count( name ) > 0;
}

string ForeignKeyConstraint::GetOption( const string& name ) const
{
	return this->_options.at( name );
}

AbstractAsset::Options ForeignKeyConstraint::GetOptions() const
{
	return this->_options;
}

bool ForeignKeyConstraint::IntersectsIndexColumns( Index* index ) const
{
	for( const string& indexColumn : index->GetColumns() )
	{
		for( const auto& iter : this->_localColumnNames )
		{
			if( strtolower( indexColumn ) == strtolower( iter.second ) )
			{
				return true;
			}
		}
	}

	return false;
}
