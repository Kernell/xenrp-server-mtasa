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

class Water;

#ifndef __WATER_H
#define __WATER_H

#include "Element.h"

class Water : public Element
{
public:
												Water                     ( PVOID luaUserdata );
	virtual                                     ~Water                    ();
};

#endif