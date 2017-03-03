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

class Marker;

#ifndef __MARKER_H
#define __MARKER_H

#include "Element.h"

class Marker : public Element
{
public:
									Marker                    ( PVOID luaUserdata );
									Marker                    ( const Vector3& position, const string& type, float size, const Color& color, Element* visibleTo = nullptr );
	virtual                         ~Marker                   ();

///	virtual uint                    GetCount                  () const;
	virtual string                  GetType                   () const;
	virtual float                   GetSize                   () const;
	virtual Color                   GetColor                  () const;
	virtual Vector3                 GetTarget                 () const;
	virtual string                  GetIcon                   () const;

	virtual bool                    SetType                   ( const string& type );
	virtual bool                    SetSize                   ( float size );
	virtual bool                    SetColor                  ( const Color& color );
	virtual bool                    SetTarget                 ( const Vector3& target );
	virtual bool                    SetIcon                   ( const string& icon );

public:
	static const string MARKER_TYPE_CHECKPOINT;
	static const string MARKER_TYPE_RING;
	static const string MARKER_TYPE_CYLINDER;
	static const string MARKER_TYPE_ARROW;
	static const string MARKER_TYPE_CORONA;
};

#endif