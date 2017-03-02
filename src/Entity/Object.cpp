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

#include "StdInc.h"
#include "Object.h"

Object::Object( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Object::~Object()
{
}
