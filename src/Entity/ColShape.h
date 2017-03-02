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

class ColShape;

#ifndef __COLSHAPE_H
#define __COLSHAPE_H

#include "Element.h"

class ColShape : public Element
{
public:
												ColShape                     ( PVOID luaUserdata );
	virtual                                     ~ColShape                    ();
};

#endif