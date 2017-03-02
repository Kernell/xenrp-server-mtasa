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

class Pickup;

#ifndef __PICKUP_H
#define __PICKUP_H

#include "Element.h"

class Pickup : public Element
{
public:
												Pickup                     ( PVOID luaUserdata );
	virtual                                     ~Pickup                    ();
};

#endif