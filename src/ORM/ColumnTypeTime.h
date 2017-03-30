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
#include "ColumnType.h"
#include "AbstractPlatform.h"

class ColumnTypeTime : public ColumnType
{
public:
	ColumnTypeTime( const string& name ) : ColumnType( name )
	{
	}

	virtual ID GetID() const override
	{
		return ID::TIME;
	}

	virtual string GetSQLDeclaration( Column* column, AbstractPlatform* platform ) override;
};
