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

class Comparator;

#ifndef __ORM_COMPARATOR_H
#define __ORM_COMPARATOR_H

#include "SchemaDiff.h"

class Comparator
{
public:
	Comparator();
	~Comparator();

	SchemaDiff*        Compare              ( Schema* fromSchema, Schema* toSchema );
	TableDiff*         DiffTable            ( SchemaDiff* schemaDiff, Table* table1, Table* table2 );
	void               DetectColumnRenamings( TableDiff* tableDifferences );
	bool               DiffForeignKey       ( ForeignKeyConstraint* key1, ForeignKeyConstraint* key2 );
	vector< string >   DiffColumn           ( Column* column1, Column* column2 );
	bool               DiffIndex            ( Index* index1, Index* index2 );

protected:
	SchemaDiff* Diff;
};

#endif
