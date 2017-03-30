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

class DatabaseManager;

#ifndef __DATABASEMANAGER_H
#define __DATABASEMANAGER_H

#include "SharedUtil/xml/tinyxml.h"

#include "Core/Module.h"
#include "Repository/EntityRepository.h"

#include "ORM/SchemaManager.h"

class DatabaseManager
{
public:
	DatabaseManager             ( Module* module );
	~DatabaseManager            ();

	void                        Connect();
	void                        ResourceStopping();

	bool                        IsConnected() const;

	IEntityRepository*          GetRepository      ( const string& typeName ) const;

	MySQL*                      GetConnection      () const;

	inline string               GetHostname() const { return this->Hostname; }
	inline string               GetUsername() const { return this->Username; }
	inline string               GetPassword() const { return this->Password; }
	inline string               GetDatabase() const { return this->Database; }

protected:
	void                        Initialize();
	void                        Disconnect();
	void                        RegisterRepository( IEntityRepository* repository );

private:
	Module*                     Module;
	MySQL*                      Connection;
	SchemaManager*              SchemaManager;

	string                      Hostname;
	string                      Username;
	string                      Password;
	string                      Database;

	vector< IEntityRepository* > RepositoryList;
};

#endif