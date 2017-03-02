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

class Ped;

#ifndef __PED_H
#define __PED_H

#include "Element.h"

class Ped : public Element
{
public:
												Ped                     ( PVOID luaUserdata );
	virtual                                     ~Ped                    ();
};

#endif
