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

#include "ColumnType.h"
#include "AbstractPlatform.h"

class ColumnTypeSimpleArray : public ColumnType
{
public:
	ColumnTypeSimpleArray( const string& name ) : ColumnType( name )
	{
	}

	virtual ID GetID() const override
	{
		return ID::SIMPLE_ARRAY;
	}

	virtual string GetSQLDeclaration( Column* column, AbstractPlatform* platform ) override;
};
