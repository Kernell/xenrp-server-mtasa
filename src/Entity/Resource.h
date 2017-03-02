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

class Resource;

#ifndef __RESOURCE_H
#define __RESOURCE_H

#include "Element.h"

class Resource : public Element
{
public:
												Resource                     ( PVOID luaUserdata );
	virtual                                     ~Resource                    ();
};

#endif