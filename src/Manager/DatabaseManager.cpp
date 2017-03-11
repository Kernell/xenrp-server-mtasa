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

DatabaseManager::DatabaseManager( ::Module* module ) :
	Module( module ),
	DB( nullptr )
{
	this->Hostname = "127.0.0.1";
	this->Username = "mta_5uxxx";
	this->Password = "nUpLa32zWsDV3JhW";
	this->Database = "mta_5uxxx";
}

DatabaseManager::~DatabaseManager()
{
	this->Disconnect();

	this->Module = nullptr;
}

void DatabaseManager::Connect()
{
	if( !this->DB )
	{
		try
		{
			this->DB = new MySQL( this->Hostname, this->Username, this->Password, this->Database );
		}
		catch( std::exception* e )
		{
			this->Module->ErrorPrintf( "MySQL: %s\n", e->what() );

			this->Disconnect();
		}
	}

	if( !this->IsConnected() )
	{
		if( this->DB )
		{
			this->Module->ErrorPrintf( "MySQL: failed to connect to %s: (%d) %s\n", this->Hostname, this->DB->Errno(), this->DB->Error().c_str() );
		}

		this->Disconnect();
	}
}

void DatabaseManager::ResourceStopping()
{
}

bool DatabaseManager::IsConnected() const
{
	return this->DB ? this->DB->Ping() : false;
}

void DatabaseManager::Disconnect()
{
	SAFE_DELETE( this->DB );
}
