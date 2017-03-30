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

class SchemaDiff;

#ifndef __SCHEMADIFF_H
#define __SCHEMADIFF_H

#include "Schema.h"

class SchemaDiff : public AbstractAsset
{
public:
	Schema* FromSchema;

	map< string, Table* >                NewTables;
	map< string, TableDiff* >            ChangedTables;
	map< string, Table* >                RemovedTables;
	vector< ForeignKeyConstraint* >      OrphanedForeignKeys;

public:
	SchemaDiff( AbstractAsset* parent,
		const map< string, Table* >&     newTables     = map< string, Table* >(),
		const map< string, TableDiff* >& changedTables = map< string, TableDiff* >(),
		const map< string, Table* >&     removedTables = map< string, Table* >(),
		Schema* fromSchema = nullptr );

	vector< string > ToSQL( AbstractPlatform* platform, bool saveMode = false );
};

#endif
