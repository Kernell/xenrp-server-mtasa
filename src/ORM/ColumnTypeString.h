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

class ColumnTypeString : public ColumnType
{
public:
	ColumnTypeString( const string& name ) : ColumnType( name )
	{
	}

	virtual ID GetID() const override
	{
		return ID::STRING;
	}

	virtual string GetSQLDeclaration( Column* column, AbstractPlatform* platform ) override;
};
