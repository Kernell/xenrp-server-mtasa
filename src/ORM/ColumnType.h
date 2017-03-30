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

class ColumnType;

#ifndef __COLUMNTYPE_H
#define __COLUMNTYPE_H

#include "AbstractAsset.h"

class AbstractPlatform;
class Column;

class ColumnType
{
public:
	enum ID
	{
		INVALID,
		ARRAY,
		SIMPLE_ARRAY,
		JSON_ARRAY,
		BIGINT,
		BOOLEAN,
		DATETIME,
		DATETIMETZ,
		DATE,
		TIME,
		DECIMAL,
		INTEGER,
		OBJECT,
		SMALLINT,
		STRING,
		TEXT,
		BINARY,
		BLOB,
		FLOAT,
		GUID
	};

public:
	ColumnType( const string& name );

	virtual ID GetID() const
	{
		return ID::INVALID;
	}

	virtual string GetName() const
	{
		return this->Name;
	}

	static ColumnType* GetType( ID id );
	static ColumnType* GetType( const string& name );

	virtual string GetSQLDeclaration       ( Column* column,      AbstractPlatform* platform ) = 0;
	virtual string ConvertToDatabaseValue  ( const string& value, AbstractPlatform* platform );
	virtual string ConvertFromDatabaseValue( const string& value, AbstractPlatform* platform );

private:
	string Name;
	static map< ID, ColumnType* > TypesMap;
};

#endif
