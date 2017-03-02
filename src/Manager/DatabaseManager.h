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

#include "Core/Module.h"

class DatabaseManager
{
public:
	DatabaseManager             ( Module* module );
	~DatabaseManager            ();

	void                        Connect();
	void                        ResourceStopping();

	bool                        IsConnected() const;

protected:
	void                        Disconnect();

private:
	Module*                     Module;
	MySQL*                      DB;

	string                      Hostname;
	string                      Username;
	string                      Password;
	string                      Database;
};

#endif