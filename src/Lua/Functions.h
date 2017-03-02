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

#pragma once

namespace Lua
{
	class Functions
	{
	public:
		static int      XRInit                ( lua_State* luaVM );
		static int      XREventHandler        ( lua_State* luaVM );
		static int      XRCommandHandler      ( lua_State* luaVM );
	};
};
