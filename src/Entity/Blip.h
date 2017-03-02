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

class Blip;

#ifndef __BLIP_H
#define __BLIP_H

#include "Element.h"

class Blip : public Element
{
public:
												Blip                     ( PVOID luaUserdata );
	virtual                                     ~Blip                    ();
};

#endif