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

#pragma once

class Schema;

#ifndef __SCHEMA_H
#define __SCHEMA_H

#include "StdInc.h"
#include "AbstractAsset.h"
#include "AbstractPlatform.h"
#include "Table.h"
#include "SchemaException.h"

class Schema : public AbstractAsset
{
public:
	Schema( map< string, Table* > tables = map< string, Table* >() ) :
		AbstractAsset( nullptr )
	{
		for( const auto& iter : tables )
		{
			this->AddTable( iter.second );
		}
	}

	void AddTable( Table* table )
	{
		string tableName = table->GetName();

		if( this->Tables.count( tableName ) > 0 )
		{
			throw new SchemaException::TableAlreadyExists( tableName );
		}

		this->Tables[ tableName ] = table;
	}

	map< string, Table* > GetTables() const
	{
		return this->Tables;
	}

	StringArray GetTableNames() const
	{
		StringArray keys;

		for( const auto& iter : this->Tables )
		{
			keys.push_back( iter.first );
		}

		return keys;
	}

	Table* GetTable( const string& tableName ) const
	{
		if( this->Tables.count( tableName ) == 0 )
		{
			throw SchemaException::TableDoesNotExist( tableName );
		}

		return this->Tables.at( tableName );
	}

	bool HasTable( const string& tableName ) const
	{
		return this->Tables.count( tableName ) != 0;
	}

	Table* CreateTable( const string& tableName )
	{
		Table* table = new Table( this, tableName );

		this->AddTable( table );

		return table;
	}

	void RenameTable( const string& oldTableName, const string& newTableName )
	{
		Table* table = this->GetTable( oldTableName );

		table->SetName( newTableName );

		this->Tables.erase( oldTableName );
		this->AddTable( table );
	}

	void DropTable( const string& tableName )
	{
		Table* table = this->GetTable( tableName );

		this->Tables.erase( tableName );
	}

protected:
	map < string, Table* > Tables;
};

#endif
