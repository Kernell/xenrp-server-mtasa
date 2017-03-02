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
#include "Functions.h"
#include "Core/Module.h"

using namespace Lua;

extern Module* g_Module;

int Functions::XRInit( lua_State* luaVM )
{
	if( luaVM )
	{
		LuaArgument pLuaArgument( luaVM, -1 );

		string name = pLuaArgument.GetString();

		if( name == MODULE_SERVER_RESOURCE )
		{
			if( g_Module->GetLua() == luaVM )
			{
				g_Module->ResourceStarted();

				return 1;
			}
		}
	}

	return 0;
}

int Functions::XREventHandler( lua_State* luaVM )
{
	if( luaVM )
	{
		if( g_Module->GetLua() == luaVM )
		{
			g_Module->EventHandler();

			return 1;
		}
	}

	return 0;
}

int Functions::XRCommandHandler( lua_State* luaVM )
{
	if( luaVM )
	{
		if( g_Module->GetLua() == luaVM )
		{
			g_Module->CommandHandler();

			return 1;
		}
	}

	return 0;
}
