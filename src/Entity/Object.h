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

class Object;

#ifndef __OBJECT_H
#define __OBJECT_H

#include "Element.h"

class Object : public Element
{
public:
												Object                     ( PVOID luaUserdata );
	virtual                                     ~Object                    ();
};

#endif