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

class Column;

#ifndef __COLUMN_H
#define __COLUMN_H

#include "AbstractAsset.h"

#include "ColumnTypeArray.h"
#include "ColumnTypeDateTime.h"
#include "ColumnTypeInteger.h"
#include "ColumnTypeText.h"
#include "ColumnTypeBigInt.h"
#include "ColumnTypeDateTimeTz.h"
#include "ColumnTypeJsonArray.h"
#include "ColumnTypeTime.h"
#include "ColumnTypeBinary.h"
#include "ColumnTypeDate.h"
#include "ColumnTypeObject.h"
#include "ColumnTypeBlob.h"
#include "ColumnTypeDecimal.h"
#include "ColumnTypeSimpleArray.h"
#include "ColumnTypeBoolean.h"
#include "ColumnTypeFloat.h"
#include "ColumnTypeSmallInt.h"
#include "ColumnTypeGuid.h"
#include "ColumnTypeString.h"

class Column : public AbstractAsset
{
public:
	Column       ( AbstractAsset* parent, const string& columnName, ColumnType* type );

	void         SetType             ( ColumnType* type );
	void         SetLength           ( size_t length );
	void         SetPrecision        ( int precision );
	void         SetScale            ( int scale );
	void         SetUnsigned         ( bool __unsigned );
	void         SetFixed            ( bool fixed );
	void         SetNotNull          ( bool notnull );
	void         SetDefault          ( const string& default );
	void         SetColumnDefinition ( const string& value );

	ColumnType*  GetType             () const;
	size_t       GetLength           () const;

	int          GetPrecision        () const;
	int          GetScale            () const;
	bool         GetUnsigned         () const;
	bool         GetFixed            () const;
	bool         GetNotNull          () const;
	string       GetDefault          () const;
	string       GetColumnDefinition () const;
	bool         GetAutoincrement    () const;
	
	void         SetAutoincrement    ( bool flag );
	void         SetComment          ( const string& comment );

	string       GetComment          () const;

public:
	ColumnType* Type;
	string      Default;
	bool        NotNull;
	size_t      Length;
	int         Precision;
	int         Scale;
	bool        Fixed;
	bool        Unsigned;
	bool        AutoIncrement;
	string      ColumnDefinition;
	string      Comment;
	string      Version;

	string      Charset;
	string      Collation;
	bool        Primary;
	bool        Unique;

	map< string, string >  Options;
};

#endif
