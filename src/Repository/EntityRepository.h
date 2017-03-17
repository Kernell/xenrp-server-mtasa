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

#include <StdInc.h>
#include "IEntityRepository.h"
#include "Core/MySQL.h"
#include "Core/MySQLResult.h"

class ElementManager;
class DatabaseManager;

template< typename T >
class EntityRepository : public IEntityRepository
{
public:
	EntityRepository( DatabaseManager* db ) :
		DB( db )
	{
	}

	virtual ~EntityRepository()
	{
		this->Entities.clear();
	}

	virtual T* GetByID( const string& id )
	{
		return this->GetByID( stoi( id.c_str() ) );
	}

	virtual T* GetByID( uint64_t id )
	{
		if( !this->DB->IsConnected() )
		{
			return nullptr;
		}

		return nullptr;
	}

	virtual vector< T* > SelectAll( const char* order = nullptr, const char* orderBy = nullptr, int limit = -1 )
	{
		vector< T* > result;

		if( !this->DB->IsConnected() )
		{
			return result;
		}

		string query = "SELECT ";

		{
			const TableColumns& tableColumns = this->DB->GetTableSchema( this->GetTableName() );

			bool _first = true;

			for( const auto& col : tableColumns )
			{
				if( _first )
				{
					query += ", ";

					_first = false;
				}

				query += "t." + col.Name;
			}
		}

		query += " FROM " + this->GetTableName() + " t ORDER BY t." + ( orderBy ? orderBy : "id" ) + " " + ( order ? order : "ASC" );

		MySQLResult* mysql_result = this->DB->Query( query );

		if( mysql_result )
		{
			for( MySQLRow row : *mysql_result )
			{
				string id = row[ "id" ];

				T* entity = this->Entities[ id ];

				if( !entity )
				{
					T* entity = this->CreateFromQuery( row );
				}

				result.push_back( entity );
			}

			mysql_result->Free();
		}

		return result;
	}

	virtual T* CreateFromQuery( const MySQLRow& row ) = 0;

protected:
	DatabaseManager*  DB;

	map< string, T* > Entities;
};
