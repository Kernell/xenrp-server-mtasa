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

class Team;

#ifndef __TEAM_H
#define __TEAM_H

#include "Element.h"

class Team : public Element
{
public:
												Team                     ( PVOID luaUserdata );
	virtual                                     ~Team                    ();
};

#endif