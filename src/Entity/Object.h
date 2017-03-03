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

class Object;

#ifndef __OBJECT_H
#define __OBJECT_H

#include "Element.h"

class Object : public Element
{
public:
										Object                     ( PVOID luaUserdata );
										Object                     ( ushort modelID, const Vector3& position = Vector3(), const Vector3& rotation = Vector3(), bool isLowLod = false );
	virtual                             ~Object                    ();

	virtual Vector3                     GetScale                   ();

	virtual bool                        SetScale                   ( const Vector3& scale );
	virtual bool                        Move                       ( ulong time, const Vector3& position, const Vector3& rotation, const string& easingType, float easingPeriod, float easingAmplitude, float easingOvershoot );
	virtual bool                        Stop                       ();
};

#endif