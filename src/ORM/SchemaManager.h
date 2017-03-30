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

class SchemaManager;

#ifndef __SCHEMAMANAGER_H
#define __SCHEMAMANAGER_H

#include "Schema.h"
#include "MySQLPlatform.h"
#include "Manager/DatabaseManager.h"

class DatabaseManager;

class SchemaManager
{
public:
	SchemaManager( DatabaseManager* db, Module* module );
	~SchemaManager();

	void                  Synchronize            ( const vector< IEntityRepository* >& repositories );

	Schema*               CreateSchema           ();
	Schema*               CreateSchema           ( const vector< IEntityRepository* >& repositories );

protected:
	Table*                CreateTable            ( Schema* schema, const string& tableName );
	Table*                CreateTable            ( Schema* schema, IEntityRepository* repository );
	void                  CreateTableColumns     ( Table* table, const vector< map< string, string > >& rows );
	void                  CreateTableForeignKeys ( Table* table, const vector< map< string, string > >& rows );
	void                  CreateTableIndexes     ( Table* table, const vector< map< string, string > >& rows );

protected:
	Module* Module;
	DatabaseManager* DB;
	MySQLPlatform* Platform;
};

#endif
