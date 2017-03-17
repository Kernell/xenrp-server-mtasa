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

#include <StdInc.h>

class IEntityRepository
{
public:
	virtual string GetName() const = 0;
	virtual string GetTableName() const = 0;
};
