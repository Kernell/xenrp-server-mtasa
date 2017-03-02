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

class Ban;

#ifndef __BAN_H
#define __BAN_H

#include "Element.h"

class Ban : public Element
{
public:
												Ban                     ( PVOID luaUserdata );
	virtual                                     ~Ban                    ();
};

#endif