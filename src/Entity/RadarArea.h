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
										RadarArea      ( PVOID luaUserdata );
										RadarArea      ( const Vector2& position, const Vector2& size, const Color& color, Element* visibleTo = nullptr );
	virtual                             ~RadarArea     ();


	virtual Vector2                     GetSize        () const;
	virtual Color                       GetColor       () const;
	virtual bool                        IsFlashing     () const;
	virtual bool                        IsInside       ( const Vector2& position ) const;

	virtual bool                        SetSize        ( const Vector2& vecSize );
	virtual bool                        SetColor       ( const Color& color );
	virtual bool                        SetFlashing    ( bool flashing );
};

#endif