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
#include "DatabaseManager.h"

#include "Repository/VehicleRepository.h"

DatabaseManager::DatabaseManager( ::Module* module ) :
	Module( module ),
	Connection( nullptr ),
	SchemaManager( nullptr )
{
	this->Hostname = "127.0.0.1";
	this->Username = "mta_5uxxx";
	this->Password = "nUpLa32zWsDV3JhW";
	this->Database = "mta_5uxxx";

	SchemaManager = new ::SchemaManager( this, module );
}

DatabaseManager::~DatabaseManager()
{
	this->Disconnect();

	this->Module = nullptr;

	SAFE_DELETE( SchemaManager );
}

void DatabaseManager::Connect()
{
	if( !this->Connection )
	{
		try
		{
			this->Connection = new MySQL( this->Hostname, this->Username, this->Password, this->Database );
		}
		catch( std::exception* e )
		{
			this->Module->ErrorPrintf( "MySQL: %s\n", e->what() );

			this->Disconnect();
		}
	}

	if( !this->IsConnected() )
	{
		if( this->Connection )
		{
			this->Module->ErrorPrintf( "MySQL: failed to connect to %s: (%d) %s\n", this->Hostname, this->Connection->Errno(), this->Connection->Error().c_str() );
		}

		this->Disconnect();

		return;
	}

	this->Initialize();
}

void DatabaseManager::Initialize()
{
	this->RegisterRepository( new VehicleRepository( this ) );

	try
	{
		this->SchemaManager->Synchronize( this->RepositoryList );
	}
	catch( exception* e )
	{
		this->Module->ErrorPrintf( "%s\n", e->what() );
	}
}

void DatabaseManager::ResourceStopping()
{
}

bool DatabaseManager::IsConnected() const
{
	return this->Connection ? this->Connection->Ping() : false;
}

IEntityRepository* DatabaseManager::GetRepository( const string& typeName ) const
{
	for( IEntityRepository* repo : this->RepositoryList )
	{
		if( repo->GetName() == typeName )
		{
			return repo;
		}
	}

	return nullptr;
}

void DatabaseManager::RegisterRepository( IEntityRepository* repository )
{
	this->RepositoryList.push_back( repository );
}

MySQL* DatabaseManager::GetConnection() const
{
	return this->Connection;
}

void DatabaseManager::Disconnect()
{
	SAFE_DELETE( this->Connection );
}
