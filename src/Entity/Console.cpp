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
#include "Console.h"

#include "Core/Module.h"

Console::Console( PVOID luaUserdata ) :
	Player( luaUserdata )
{
}

Console::~Console()
{
}

bool Console::OutputChatBox( const string& text, const Color& color, bool colorCoded )
{
	return Lua::Bindings::OutputServerLog( LuaVM, text.c_str() );
}

bool Console::OutputConsole( const string& text )
{
	return Lua::Bindings::OutputServerLog( LuaVM, text.c_str() );
}