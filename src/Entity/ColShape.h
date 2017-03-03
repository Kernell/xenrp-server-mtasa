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
			ColShape   ( PVOID luaUserdata );

	static  ColShape* CreateCircle      ( const Vector2& position, float radius );
	static  ColShape* CreateCuboid      ( const Vector3& position, const Vector3& size );
	static  ColShape* CreateSphere      ( const Vector3& position, float radius );
	static  ColShape* CreateRectangle   ( const Vector2& position, const Vector2& size );
	static  ColShape* CreatePolygon     ( const vector< Vector2 >& pointList );
	static  ColShape* CreateTube        ( const Vector3& position, float radius, float height );

	virtual ~ColShape  ();
};

#endif