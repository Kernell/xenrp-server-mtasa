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
#include "Core/Module.h"

Module* g_Module = nullptr;

DLL_EXPORT bool InitModule( ILuaModuleManager10* pManager, char* szModuleName, char* szAuthor, float* fVersion )
{
	g_Module = new Module( pManager );

    strncpy( szModuleName, MODULE_NAME, MAX_INFO_LENGTH );
    strncpy( szAuthor, MODULE_AUTHOR, MAX_INFO_LENGTH );

    (*fVersion) = MODULE_VERSION;

    return true;
}

DLL_EXPORT void RegisterFunctions( lua_State* luaVM )
{
    if( g_Module )
	{
		PVOID resource = Lua::Bindings::GetThisResource( luaVM );

		if( resource )
		{
			string name;

			if( Lua::Bindings::GetResourceName( luaVM, resource, name ) && name == MODULE_SERVER_RESOURCE )
			{
				g_Module->Init( luaVM );
			}
		}
	}
}

DLL_EXPORT bool DoPulse()
{
	if( g_Module )
	{
		g_Module->DoPulse();
	}

    return true;
}

DLL_EXPORT bool ShutdownModule()
{
    if( g_Module )
	{
		g_Module->Shutdown();

		delete g_Module;
	}

	g_Module = nullptr;

    return true;
}

DLL_EXPORT bool ResourceStopping( lua_State* luaVM )
{
	if( g_Module && g_Module->GetLua() == luaVM )
	{
		g_Module->ResourceStopping();
	}

    return true;
}

DLL_EXPORT bool ResourceStopped( lua_State* luaVM )
{
	if( g_Module && g_Module->GetLua() == luaVM )
	{
		g_Module->ResourceStopped();
	}

    return true;
}