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
#include "Module.h"

Module::Module( ILuaModuleManager10* module ) :
	LuaVM( nullptr ),
	ModuleManager( module ),
	DatabaseManager( nullptr ),
	ElementManager( nullptr ),
	EventManager( nullptr ),
	CommandManager( nullptr )
{
}

Module::~Module()
{
	SAFE_DELETE( this->ElementManager );
	SAFE_DELETE( this->EventManager );
	SAFE_DELETE( this->CommandManager );
	SAFE_DELETE( this->DatabaseManager );

	LuaVM = nullptr;
}

void Module::Init( lua_State* luaVM )
{
	this->LuaVM = luaVM;

	this->RegisterFunctions();

	this->DatabaseManager = new ::DatabaseManager( this );
	this->ElementManager  = new ::ElementManager( this );
	this->EventManager    = new ::EventManager( this );
	this->CommandManager  = new ::CommandManager( this );
}

void Module::DoPulse()
{
}

void Module::Shutdown()
{
}

void Module::ResourceStarted()
{
	this->DatabaseManager->Connect();
}

void Module::ResourceStopping()
{
	this->DatabaseManager->ResourceStopping();
}

void Module::ResourceStopped()
{
	this->LuaVM = nullptr;
}

bool Module::CommandHandler()
{
	LuaArguments luaArgs;

	luaArgs.ReadArguments( this->LuaVM );

	if( luaArgs.Count() == 0 )
	{
		return 0;
	}

	void* playerSource = nullptr;
	string commandName;

	uint i = 0;

	vector< string > argv;

	for( const auto& iter : luaArgs.GetArguments() )
	{
		switch( i )
		{
			case 0:
			{
				playerSource = iter->GetLightUserData();

				break;
			}
			case 1:
			{
				commandName = iter->GetString();

				break;
			}
			default:
			{
				if( iter->GetType() == LuaType::String )
				{
					argv.push_back( iter->GetString() );
				}

				break;
			}
		}

		++i;
	}

	return this->ExecuteCommand( playerSource, commandName, argv );
}

bool Module::EventHandler()
{
	LuaArguments luaArgs;

	luaArgs.ReadArguments( this->LuaVM );

	if( luaArgs.Count() == 0 )
	{
		return 0;
	}

	return this->EventManager->Call( luaArgs.GetArguments() );
}

bool Module::AddEvent( const string& eventName, const string& handleElement )
{
	if( this->LuaVM )
	{
		char buffer[ 128 ];

		sprintf( buffer, "addEventHandler( '%s', %s, _XREventHandler, true, 'normal' );", eventName.c_str(), handleElement.c_str() );

		luaL_dostring( this->LuaVM, buffer );

		return true;
	}

	return false;
}

bool Module::RemoveEvent( const string& eventName, const string& handleElement )
{
	if( this->LuaVM )
	{
		char buffer[ 128 ];

		sprintf( buffer, "removeEventHandler( '%s', %s, _XREventHandler );", eventName.c_str(), handleElement.c_str() );

		luaL_dostring( this->LuaVM, buffer );

		return true;
	}

	return false;
}

bool Module::ExecuteCommand( PVOID player, const string& commandName, vector< string > argv )
{
	if( !player )
	{
		return false;
	}

	Element* playerElement = this->ElementManager->FindOrCreate( player );

	return this->CommandManager->Execute( playerElement, commandName, argv );
}

void Module::RegisterFunctions()
{
	this->RegisterFunction( "XRInit",           Lua::Functions::XRInit );
	this->RegisterFunction( "XREventHandler",   Lua::Functions::XREventHandler );
	this->RegisterFunction( "XRCommandHandler", Lua::Functions::XRCommandHandler );

	luaL_dostring( this->LuaVM, "function _XREventHandler( ... ) XREventHandler( eventName, source, this, client, ... ); end" );
	luaL_dostring( this->LuaVM, "addEventHandler( 'onResourceStart', resourceRoot, function( res ) XRInit( getResourceName( res ) ) end )" );
}

bool Module::RegisterFunction( const char* functionName, lua_CFunction func )
{
	return this->ModuleManager->RegisterFunction( this->LuaVM, functionName, func );
}

bool Module::GetResourceName( string &name )
{
	return this->ModuleManager->GetResourceName( this->LuaVM, name );
}

CChecksum Module::GetResourceMetaChecksum()
{
	return this->ModuleManager->GetResourceMetaChecksum( this->LuaVM );
}

CChecksum Module::GetResourceFileChecksum( const char* file )
{
	return this->ModuleManager->GetResourceFileChecksum( this->LuaVM, file );
}

unsigned long Module::GetVersion()
{
	return this->ModuleManager->GetVersion();
}

const char* Module::GetVersionString()
{
	return this->ModuleManager->GetVersionString();
}

const char* Module::GetVersionName()
{
	return this->ModuleManager->GetVersionName();
}

unsigned long Module::GetNetcodeVersion()
{
	return this->ModuleManager->GetNetcodeVersion();
}

const char* Module::GetOperatingSystemName()
{
	return this->ModuleManager->GetOperatingSystemName();
}

lua_State* Module::GetResourceFromName( const char* resourceName )
{
	return this->ModuleManager->GetResourceFromName( resourceName );
}
