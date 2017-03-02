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
#include "Element.h"

#include "Core/Module.h"
#include "Manager/ElementManager.h"

extern Module* g_Module;

Element::Element( PVOID luaUserdata ) :
	LuaUserdata( luaUserdata )
{
	g_Module->GetElementManager()->AddToList( this );
}

Element::~Element()
{
	g_Module->GetElementManager()->RemoveFromList( this );

	this->LuaUserdata = nullptr;
}

void Element::DoPulse()
{
}

void Element::Save() const
{
}
