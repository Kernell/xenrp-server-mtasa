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

class Console;

#ifndef __CONSOLE_H
#define __CONSOLE_H

#include "Player.h"

class Console : public Player
{
public:
												Console                     ( PVOID luaUserdata );
	virtual                                     ~Console                    ();
};

#endif