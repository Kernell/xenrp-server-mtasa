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

class RadarArea;

#ifndef __RADARAREA_H
#define __RADARAREA_H

#include "Element.h"

class RadarArea : public Element
{
public:
												RadarArea                     ( PVOID luaUserdata );
	virtual                                     ~RadarArea                    ();
};

#endif