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
#include "Water.h"

#include "Core/Module.h"

Water::Water( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Water::Water( Vector3* v1, Vector3* v2, Vector3* v3, Vector3* v4, bool shallow ) :
	Element( nullptr )
{
}

Water::~Water()
{
}

bool Water::SetLevel( float level )
{
	return Lua::Bindings::SetElementWaterLevel( LuaVM, LuaUserdata, level );
}

Vector3 Water::GetVertexPosition( int vertexIndex )
{
	Vector3 value;

	Lua::Bindings::GetWaterVertexPosition( LuaVM, LuaUserdata, vertexIndex, value );

	return value;
}

bool Water::SetVertexPosition( int vertexIndex, const Vector3& position )
{
	return Lua::Bindings::SetWaterVertexPosition( LuaVM, LuaUserdata, vertexIndex, position );
}
