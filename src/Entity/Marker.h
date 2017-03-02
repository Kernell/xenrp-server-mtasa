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

class Marker;

#ifndef __MARKER_H
#define __MARKER_H

#include "Element.h"

class Marker : public Element
{
public:
												Marker                     ( PVOID luaUserdata );
	virtual                                     ~Marker                    ();
};

#endif