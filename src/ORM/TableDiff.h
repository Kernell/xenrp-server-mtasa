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

#include "StdInc.h"
#include "Index.h"
#include "Column.h"
#include "ColumnDiff.h"
#include "ForeignKeyConstraint.h"

class TableDiff : public AbstractAsset
{
public:
	TableDiff( AbstractAsset* parent,
		const string& tableName,
		const vector< Column* >&     addedColumns   = vector< Column* >(),
		const vector< ColumnDiff* >& changedColumns = vector< ColumnDiff* >(),
		const vector< Column* >&     removedColumns = vector< Column* >(),
		const vector< Index* >&      addedIndexes   = vector< Index* >(),
		const vector< Index* >&      changedIndexes = vector< Index* >(),
		const vector< Index* >&      removedIndexes = vector< Index* >(),
		Table* fromTable = nullptr ) :
		AbstractAsset( parent )
	{
		this->Name           = tableName;
		this->AddedColumns   = addedColumns;
		this->ChangedColumns = changedColumns;
		this->RemovedColumns = removedColumns;
		this->AddedIndexes   = addedIndexes;
		this->ChangedIndexes = changedIndexes;
		this->RemovedIndexes = removedIndexes;
		this->FromTable      = fromTable;
	}

	string GetName() const
	{
		return this->Name;
	}

	string GetNewName() const
	{
		return this->NewName;
	}

	Table* GetFromTable() const
	{
		return this->FromTable;
	}

	void SetFromTable( Table* table )
	{
		this->FromTable = table;
	}

protected:
	string Name;
	string NewName;
	Table* FromTable;

public:
	vector< Column* >               AddedColumns;
	vector< ColumnDiff* >           ChangedColumns;
	vector< Column* >               RemovedColumns;
	vector< Index* >                ChangedIndexes;
	vector< Index* >                RemovedIndexes;
	vector< Index* >                AddedIndexes;
	vector< Column* >               RenamedColumns;
	vector< Index* >                RenamedIndexes;
	vector< ForeignKeyConstraint* > AddedForeignKeys;
	vector< ForeignKeyConstraint* > ChangedForeignKeys;
	vector< ForeignKeyConstraint* > RemovedForeignKeys;
};
