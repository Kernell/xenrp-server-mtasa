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

class Water;

#ifndef __WATER_H
#define __WATER_H

#include "Element.h"

class Water : public Element
{
public:
									Water                     ( PVOID luaUserdata );
	                                Water                     ( Vector3* v1, Vector3* v2, Vector3* v3, Vector3* v4, bool shallow );
	virtual                         ~Water                    ();

	virtual bool                    SetLevel			      ( float level );
///	virtual bool                    SetAllLevel	              ( float level );
///	virtual bool                    SetWorldLevel		      ( float level, bool includeWorldNonSeaLevel );
///	virtual bool                    ResetWorldLevel	          ();
	virtual Vector3                 GetVertexPosition	      ( int vertexIndex );
	virtual bool                    SetVertexPosition	      ( int vertexIndex, const Vector3& position );
///	virtual Color                   GetColor                  () const;
///	virtual bool                    SetColor                  ( const Color& color );
///	virtual bool                    ResetColor                ();
};

#endif