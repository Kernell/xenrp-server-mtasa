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
#include "ColShape.h"

#include "Core/Module.h"

ColShape::ColShape( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

ColShape* ColShape::CreateCircle( const Vector2& position, float radius )
{
	ColShape* colshape = new ColShape( nullptr );

	colshape->LuaUserdata = Lua::Bindings::CreateColCircle( colshape->LuaVM, position, radius );

	return colshape;
}

ColShape* ColShape::CreateCuboid( const Vector3& position, const Vector3& size )
{
	ColShape* colshape = new ColShape( nullptr );

	colshape->LuaUserdata = Lua::Bindings::CreateColCuboid( colshape->LuaVM, position, size );

	return colshape;
}

ColShape* ColShape::CreateSphere( const Vector3& position, float radius )
{
	ColShape* colshape = new ColShape( nullptr );

	colshape->LuaUserdata = Lua::Bindings::CreateColSphere( colshape->LuaVM, position, radius );

	return colshape;
}

ColShape* ColShape::CreateRectangle( const Vector2& position, const Vector2& size )
{
	ColShape* colshape = new ColShape( nullptr );

	colshape->LuaUserdata = Lua::Bindings::CreateColRectangle( colshape->LuaVM, position, size );

	return colshape;
}

ColShape* ColShape::CreatePolygon( const vector< Vector2 >& pointList )
{
	ColShape* colshape = new ColShape( nullptr );

	colshape->LuaUserdata = Lua::Bindings::CreateColPolygon( colshape->LuaVM, pointList );

	return colshape;
}

ColShape* ColShape::CreateTube( const Vector3& position, float radius, float height )
{
	ColShape* colshape = new ColShape( nullptr );

	colshape->LuaUserdata = Lua::Bindings::CreateColTube( colshape->LuaVM, position, radius, height );

	return colshape;
}

ColShape::~ColShape()
{
}
