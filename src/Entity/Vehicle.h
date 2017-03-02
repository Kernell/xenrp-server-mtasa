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

class Vehicle;

#ifndef __VEHICLE_H
#define __VEHICLE_H

#include "Element.h"

class Vehicle : public Element
{
public:
												Vehicle                     ( PVOID luaUserdata );
	virtual                                     ~Vehicle                    ();
};

#endif