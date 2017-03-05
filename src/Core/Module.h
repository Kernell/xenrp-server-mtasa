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

class Module;

#ifndef __MODULE_H
#define __MODULE_H

#include "MySQL.h"

#include "ILuaModuleManager.h"

#include "Lua/LuaArgument.h"
#include "Lua/LuaArguments.h"
#include "Lua/Functions.h"

#include "Entity/Element.h"
#include "Entity/Ped.h"
#include "Entity/Player.h"
#include "Entity/Console.h"
#include "Entity/Marker.h"
#include "Entity/Object.h"
#include "Entity/Pickup.h"
#include "Entity/RadarArea.h"
#include "Entity/Resource.h"
#include "Entity/Team.h"
#include "Entity/Vehicle.h"
#include "Entity/Water.h"
#include "Entity/Account.h"
#include "Entity/Ban.h"
#include "Entity/Blip.h"
#include "Entity/ColShape.h"
#include "Entity/World.h"

#include "Lua/Bindings.h"

#include "Manager/DatabaseManager.h"
#include "Manager/ElementManager.h"
#include "Manager/CommandManager.h"
#include "Manager/EventManager.h"

class Module
{
public:
	Module( ILuaModuleManager10* moduleManager );
	~Module();

	void                                    Init                ( lua_State* luaVM );
	void                                    DoPulse             ();
	void									Shutdown            ();

	void									ResourceStarted     ();
	void									ResourceStopping    ();
	void									ResourceStopped     ();

	bool                                    CommandHandler      ();
	bool                                    EventHandler        ();
	bool                                    AddEvent            ( const string& eventName, const string& handleElement );
	bool                                    RemoveEvent         ( const string& eventName, const string& handleElement );

	bool                                    ExecuteCommand      ( PVOID player, const string& commandName, vector< string > argv );

	void                                    RegisterFunctions   ();

	inline lua_State*                       GetLua              () const { return this->LuaVM; }

	inline DatabaseManager*                 GetDatabase         () const { return this->DatabaseManager; }
	inline EventManager*                    GetEventManager     () const { return this->EventManager; }
	inline ElementManager*                  GetElementManager   () const { return this->ElementManager; }
	inline CommandManager*                  GetCommandManager   () const { return this->CommandManager; }

	inline ILuaModuleManager10*             GetModuleManager() const
	{
		return this->ModuleManager;
	}

	template< typename ... Type >
	void									Printf( const char* format, Type ... args ) const
	{
		this->ModuleManager->Printf( format, args ... );
	}

	template< typename ... Type >
	void									DebugPrintf( const char* format, Type ... args ) const
	{
		this->ModuleManager->DebugPrintf( this->LuaVM, format, args ... );
	}

	template< typename ... Type >
	void									ErrorPrintf( const char* format, Type ... args ) const
	{
		this->ModuleManager->ErrorPrintf( format, args ... );
	}

	bool									RegisterFunction           ( const char* functionName, lua_CFunction func );
	bool									GetResourceName            ( string &name );
	CChecksum								GetResourceMetaChecksum    ();
	CChecksum								GetResourceFileChecksum    ( const char* file );

	unsigned long							GetVersion();
	const char*								GetVersionString();
	const char*								GetVersionName();
	unsigned long							GetNetcodeVersion();
	const char*								GetOperatingSystemName();

	lua_State*								GetResourceFromName( const char* resourceName );

private:
	ILuaModuleManager10*                    ModuleManager;
	lua_State*                              LuaVM;

	DatabaseManager*                        DatabaseManager;
	ElementManager*                         ElementManager;
	CommandManager*                         CommandManager;
	EventManager*                           EventManager;
};

#endif
