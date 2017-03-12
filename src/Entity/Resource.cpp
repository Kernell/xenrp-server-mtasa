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
#include "Resource.h"

#include "Core/Module.h"

extern Module* g_Module;

Resource::Resource( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Resource::Resource( const string& resourceName, const char* organizationalDir ) :
	Element( nullptr )
{
	this->LuaUserdata = Lua::Bindings::CreateResource( LuaVM, resourceName.c_str(), organizationalDir );
}

Resource::~Resource()
{
}

void Resource::Destroy()
{
}

Resource* Resource::Copy( const string& newResourceName, const char* organizationalDir ) const
{
	PVOID userdata = Lua::Bindings::CopyResource( LuaVM, LuaUserdata, newResourceName.c_str(), organizationalDir );

	return this->ElementManager->FindOrCreate< Resource* >( userdata );
}

Element* Resource::GetRoot() const
{
	PVOID userdata = Lua::Bindings::GetResourceRootElement( LuaVM, LuaUserdata );

	return this->ElementManager->FindOrCreate( userdata );
}

Element* Resource::GetMapRoot( const string& map ) const
{
	PVOID userdata = Lua::Bindings::GetResourceMapRootElement( LuaVM, LuaUserdata, map.c_str() );

	return this->ElementManager->FindOrCreate( userdata );
}

Element* Resource::GetDynamicRoot() const
{
	PVOID userdata = Lua::Bindings::GetResourceDynamicElementRoot( LuaVM, LuaUserdata );

	return this->ElementManager->FindOrCreate( userdata );
}

ArgumentsVector Resource::GetExportedFunctions() const
{
	return ArgumentsVector();
}

string Resource::GetInfo( const string& attribute ) const
{
	string value;

	Lua::Bindings::GetResourceInfo( LuaVM, LuaUserdata, attribute.c_str(), value );

	return value;
}

uint Resource::GetLastStartTime() const
{
	uint value;

	Lua::Bindings::GetResourceLastStartTime( LuaVM, LuaUserdata, value );

	return value;
}

string Resource::GetLoadFailureReason() const
{
	string value;

	Lua::Bindings::GetResourceLoadFailureReason( LuaVM, LuaUserdata, value );

	return value;
}

uint Resource::GetLoadTime() const
{
	uint value;

	Lua::Bindings::GetResourceLoadTime( LuaVM, LuaUserdata, value );

	return value;
}

string Resource::GetName() const
{
	string value;

	Lua::Bindings::GetResourceName( LuaVM, LuaUserdata, value );

	return value;
}

ResourceState Resource::GetState() const
{
	string value;

	Lua::Bindings::GetResourceState( LuaVM, LuaUserdata, value );

	ResourceState state = ResourceState::UNKNOWN;

	if( value == "loaded" )
		state = ResourceState::LOADED;
	else if( value == "running" )
		state = ResourceState::RUNNING;
	else if( value == "starting" )
		state = ResourceState::STARTING;
	else if( value == "stopping" )
		state = ResourceState::STOPPING;
	else if( value == "failed to load" )
		state = ResourceState::FAILED_TO_LOAD;

	return state;
}

bool Resource::RemoveFile( const string& filename )
{
	return Lua::Bindings::RemoveResourceFile( LuaVM, LuaUserdata, filename.c_str() );
}

bool Resource::RemoveDefaultSetting( const string& settingName )
{
	return Lua::Bindings::RemoveResourceDefaultSetting( LuaVM, LuaUserdata, settingName.c_str() );
}

bool Resource::Start( ResourceParams params )
{
	bool persistent             = params & ResourceParams::PERSISTENT;
	bool startIncludedResources = params & ResourceParams::START_INCLUDED_RESOURCES;
	bool loadServerConfigs      = params & ResourceParams::LOAD_SERVER_CONFIGS;
	bool loadMaps               = params & ResourceParams::LOAD_MAPS;
	bool loadServerScripts      = params & ResourceParams::LOAD_SERVER_SCRIPTS;
	bool loadHTML               = params & ResourceParams::LOAD_HTML;
	bool loadClientConfigs      = params & ResourceParams::LOAD_CLIENT_CONFIGS;
	bool loadClientScripts      = params & ResourceParams::LOAD_CLIENT_SCRIPTS;
	bool loadFiles              = params & ResourceParams::LOAD_FILES;

	return Lua::Bindings::StartResource( LuaVM, LuaUserdata );
}

bool Resource::Restart()
{
	return Lua::Bindings::RestartResource( LuaVM, LuaUserdata );
}

bool Resource::Stop()
{
	return Lua::Bindings::StopResource( LuaVM, LuaUserdata );
}

bool Resource::SetDefaultSetting( const string& settingName, const string& settingValue )
{
	return Lua::Bindings::SetResourceDefaultSetting( LuaVM, LuaUserdata, settingName.c_str(), settingValue.c_str() );
}

bool Resource::SetDefaultSetting( const string& settingName, int settingValue )
{
	return Lua::Bindings::SetResourceDefaultSetting( LuaVM, LuaUserdata, settingName.c_str(), settingValue );
}

bool Resource::SetDefaultSetting( const string& settingName, float settingValue )
{
	return Lua::Bindings::SetResourceDefaultSetting( LuaVM, LuaUserdata, settingName.c_str(), settingValue );
}

bool Resource::SetInfo( const string& attribute, const string& value )
{
	return Lua::Bindings::SetResourceInfo( LuaVM, LuaUserdata, attribute.c_str(), value.c_str() );
}

bool Resource::UpdateACLRequest( const string& rightName, bool access, const char* byWho )
{
	return Lua::Bindings::UpdateResourceACLRequest( LuaVM, LuaUserdata, rightName.c_str(), access, byWho );
}

bool Resource::Refresh( bool refreshAll )
{
	return Lua::Bindings::RefreshResources( g_Module->GetLua(), refreshAll );
}

bool Resource::Delete( const string& resourceName )
{
	return Lua::Bindings::DeleteResource( g_Module->GetLua(), resourceName.c_str() );
}

bool Resource::Rename( const string& resourceName, const string& newResourceName, const char* organizationalDir )
{
	return Lua::Bindings::RenameResource( g_Module->GetLua(), resourceName.c_str(), newResourceName.c_str(), organizationalDir );
}

Resource* Resource::GetFromName( const string& resourceName )
{
	PVOID userdata = Lua::Bindings::GetResourceFromName( g_Module->GetLua(), resourceName.c_str() );

	return g_Module->GetElementManager()->FindOrCreate< Resource* >( userdata );
}

vector< Resource* > Resource::GetAll()
{
	::ElementManager* em = g_Module->GetElementManager();

	vector< Resource* > list;

	for( const auto& iter : Lua::Bindings::GetResources( g_Module->GetLua() ) )
	{
		if( iter.GetType() == LuaType::LightUserdata )
		{
			Resource* resource = em->FindOrCreate< Resource* >( iter.GetLightUserData() );

			if( resource )
			{
				list.push_back( resource );
			}
		}
	}

	return list;
}

Resource* Resource::GetCurrent()
{
	return g_Module->GetElementManager()->FindOrCreate< Resource* >( Lua::Bindings::GetThisResource( g_Module->GetLua() ) );
}
