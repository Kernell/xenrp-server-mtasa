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
#include "Bindings.h"

// All-Seeing Eye related Functions
using namespace Lua;

string Bindings::Get( lua_State* pLuaVM, const char* szKey )
{
	LuaArguments pLuaArguments; 
	
	pLuaArguments.PushString( szKey );
	
	if( pLuaArguments.Call( pLuaVM, "get", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );
		
		if( const char* szString = pLuaArgument.GetString() )
		{
			return string( szString );
		}
	}
	
	return string();
}

bool Bindings::Set( lua_State *pLuaVM, const char* szKey, const char* szValue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szKey );
	pLuaArguments.PushString( szValue );
	
	if( pLuaArguments.Call( pLuaVM, "set", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );
		
		return pLuaArgument.GetBoolean();
	}

	return false;
}

string Bindings::GetGameType( lua_State *pLuaVM )
{
	string sResult = "";

	LuaArguments pLuaArguments; 

	if( pLuaArguments.Call( pLuaVM, "getGameType", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( const char *szString = pLuaArgument.GetString() )
			return string( szString );
	}

	return string();
}

string Bindings::GetMapName( lua_State *pLuaVM )
{
	LuaArguments pLuaArguments; 

	if( pLuaArguments.Call( pLuaVM, "getMapName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( const char *szString = pLuaArgument.GetString() )
			return string( szString );
	}

	return string();
}

string Bindings::GetRuleValue( lua_State *pLuaVM, const char* szKey )
{
	LuaArguments pLuaArguments; 
	
	pLuaArguments.PushString( szKey );
	
	if( pLuaArguments.Call( pLuaVM, "getRuleValue", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );
		
		if( const char *szString = pLuaArgument.GetString() )
			return string( szString );
	}
	
	return string();
}

bool Bindings::RemoveRuleValue( lua_State *pLuaVM, const char* szKey )
{
	LuaArguments pLuaArguments; 

	pLuaArguments.PushString( szKey );

	if( pLuaArguments.Call( pLuaVM, "removeRuleValue", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetGameType( lua_State *pLuaVM, const char* szGameType )
{
	LuaArguments pLuaArguments; 

	pLuaArguments.PushString( szGameType );

	if( pLuaArguments.Call( pLuaVM, "setGameType", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetMapName( lua_State *pLuaVM, const char* szMapName )
{
	LuaArguments pLuaArguments; 

	pLuaArguments.PushString( szMapName );

	if( pLuaArguments.Call( pLuaVM, "setMapName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetRuleValue( lua_State *pLuaVM, const char* szKey, const char* szValue )
{
	LuaArguments pLuaArguments; 

	pLuaArguments.PushString( szKey );
	pLuaArguments.PushString( szValue );

	if( pLuaArguments.Call( pLuaVM, "setRuleValue", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

string Bindings::GetPlayerAnnounceValue( lua_State* pLuaVM, PVOID pElement, const char* szKey )
{
	LuaArguments pLuaArguments; 
	
	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushString( szKey );
	
	if( pLuaArguments.Call( pLuaVM, "getPlayerAnnounceValue", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );
		
		if( const char *szString = pLuaArgument.GetString() )
			return string( szString );
	}
	
	return string();
}

bool Bindings::SetPlayerAnnounceValue( lua_State* pLuaVM, PVOID pElement, const char* szKey, const char* szValue )
{
	LuaArguments pLuaArguments; 
	
	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushString( szKey );
	pLuaArguments.PushString( szValue );
	
	if( pLuaArguments.Call( pLuaVM, "setPlayerAnnounceValue", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );
		
		return pLuaArgument.GetBoolean();
	}
	
	return false;
}

bool Bindings::AddCommandHandler( lua_State* pLuaVM, const char* szCommand, lua_CFunction iLuaFunction, bool bRestricted, bool bCaseSensitive )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szCommand );
	pLuaArguments.PushFunction( iLuaFunction );
	pLuaArguments.PushBoolean( bRestricted );
	pLuaArguments.PushBoolean( bCaseSensitive );

	if( pLuaArguments.Call( pLuaVM, "addCommandHandler", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::ExecuteCommandHandler( lua_State* pLuaVM, const char* szCommand, PVOID pUserData, const char* szArgs )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szCommand );
	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szArgs );

	if( pLuaArguments.Call( pLuaVM, "executeCommandHandler", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::RemoveCommandHandler( lua_State* pLuaVM, const char* szCommand, lua_CFunction iLuaFunction )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szCommand );
	pLuaArguments.PushFunction( iLuaFunction );

	if( pLuaArguments.Call( pLuaVM, "removeCommandHandler", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::AddEvent( lua_State* pLuaVM, const char* szName, bool bAllowRemoteTrigger )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushBoolean( bAllowRemoteTrigger );

	if( pLuaArguments.Call( pLuaVM, "addEvent", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::AddEventHandler( lua_State* pLuaVM, const char* szName, PVOID pUserData, lua_CFunction iLuaFunction, bool bPropagated, const char* szEventPriority )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushFunction( iLuaFunction );
	pLuaArguments.PushBoolean( bPropagated );
	pLuaArguments.PushString( szEventPriority );

	if( pLuaArguments.Call( pLuaVM, "addEventHandler", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::RemoveEventHandler( lua_State* pLuaVM, const char* szName, PVOID pUserData, lua_CFunction iLuaFunction )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushFunction( iLuaFunction );

	if( pLuaArguments.Call( pLuaVM, "removeEventHandler", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::TriggerEvent( lua_State* pLuaVM, const char* szName, PVOID pUserData, LuaArguments& arguments )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushArguments( arguments );

	if( pLuaArguments.Call( pLuaVM, "triggerEvent", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::CancelEvent( lua_State* pLuaVM, bool bCancel, const char* szReason )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bCancel );
	pLuaArguments.PushString( szReason );

	if( pLuaArguments.Call( pLuaVM, "cancelEvent", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::WasEventCancelled( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "wasEventCancelled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

string Bindings::GetCancelReason( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getCancelReason", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			return pLuaArgument.GetString();
		}
	}

	return string();
}

bool Bindings::TriggerClientEvent( lua_State* pLuaVM, PVOID pSendTo, const char* szName, PVOID pSource, LuaArguments& arguments )
{
	LuaArguments pLuaArguments;

	if( pSendTo )
	{
		pLuaArguments.PushUserData( pSendTo );
	}

	pLuaArguments.PushString( szName );
	pLuaArguments.PushUserData( pSource );
	pLuaArguments.PushArguments( arguments );

	if( pLuaArguments.Call( pLuaVM, "triggerClientEvent", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

// Element create/destroy

PVOID Bindings::CreateElement( lua_State* pLuaVM, const char* szTypeName, const char* szID )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szTypeName );

	if( szID && strlen( szID ) > 0 )
	{
		pLuaArguments.PushString( szID );
	}

	if( pLuaArguments.Call( pLuaVM, "createElement", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::DestroyElement( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "destroyElement", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

PVOID Bindings::CloneElement( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& vecPosition, bool bCloneElement )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushBoolean( bCloneElement );

	if( pLuaArguments.Call( pLuaVM, "cloneElement", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

// Element get funcs

ArgumentsVector Bindings::GetElementsByType( lua_State* pLuaVM, const char* szTypeName, PVOID pUserData )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szTypeName );

	if( pUserData )
	{
		pLuaArguments.PushUserData( pUserData );
	}

	if( pLuaArguments.Call( pLuaVM, "getElementsByType", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

bool Bindings::IsElement( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElement", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

string Bindings::GetElementType( lua_State* pLuaVM, PVOID pUserData )
{
	string strResult;

	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementType", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strResult = pLuaArgument.GetString();
		}
	}

	return strResult;
}

PVOID Bindings::GetElementByID( lua_State* pLuaVM, const char* szID, unsigned int uiIndex )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szID );

	if( uiIndex )
	{
		pLuaArguments.PushNumber( uiIndex );
	}

	if( pLuaArguments.Call( pLuaVM, "getElementByID", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::GetElementByIndex( lua_State* pLuaVM, int iIndex )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( iIndex );

	if( pLuaArguments.Call( pLuaVM, "getElementByIndex", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::GetElementChild( lua_State* pLuaVM, PVOID pUserData, int iIndex )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iIndex );

	if( pLuaArguments.Call( pLuaVM, "getElementChild", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

int Bindings::GetElementChildrenCount( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementChildrenCount", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

string Bindings::GetElementID( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementID", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			return pLuaArgument.GetString();
		}
	}

	return string();
}

LuaArgument Bindings::GetElementData( lua_State* pLuaVM, PVOID pUserData, string sKey, bool bInherit )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sKey.c_str() );
	pLuaArguments.PushBoolean( bInherit );

	if( pLuaArguments.Call( pLuaVM, "getElementData", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument;
}

LuaArguments Bindings::GetAllElementData( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getAllElementData", 1 ) )
	{
		pLuaArguments.ReadArguments( pLuaVM );
	}
	else
	{
		pLuaArguments.DeleteArguments();
	}

	return pLuaArguments;
}

PVOID Bindings::GetElementParent( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementParent", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetElementPosition( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecPosition )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getElementPosition", 3 ) )
	{
		vecPosition.fX = static_cast< float >( LuaArgument( pLuaVM, -3 ).GetNumber() );
		vecPosition.fY = static_cast< float >( LuaArgument( pLuaVM, -2 ).GetNumber() );
		vecPosition.fZ = static_cast< float >( LuaArgument( pLuaVM, -1 ).GetNumber() );
		
		return true;
	}

	return false;
}

bool Bindings::GetElementRotation( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecRotation )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getElementRotation", 3 ) )
	{
		vecRotation.fX = static_cast< float >( LuaArgument( pLuaVM, -3 ).GetNumber() );
		vecRotation.fY = static_cast< float >( LuaArgument( pLuaVM, -2 ).GetNumber() );
		vecRotation.fZ = static_cast< float >( LuaArgument( pLuaVM, -1 ).GetNumber() );
		
		return true;
	}


	return false;
}

bool Bindings::GetElementVelocity( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecVelocity )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getElementVelocity", 3 ) )
	{
		vecVelocity.fX = static_cast< float >( LuaArgument( pLuaVM, -3 ).GetNumber() );
		vecVelocity.fY = static_cast< float >( LuaArgument( pLuaVM, -2 ).GetNumber() );
		vecVelocity.fZ = static_cast< float >( LuaArgument( pLuaVM, -1 ).GetNumber() );
		
		return true;
	}


	return false;
}

bool Bindings::GetElementInterior( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucInterior )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementInterior", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		ucInterior = static_cast< unsigned char >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool Bindings::IsElementWithinColShape( lua_State* pLuaVM, PVOID pUserData, bool& bWithin )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementWithinColShape", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bWithin = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsElementWithinMarker( lua_State* pLuaVM, PVOID pUserData, bool& bWithin )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementWithinMarker", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bWithin = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetElementDimension( lua_State* pLuaVM, PVOID pUserData, unsigned short& usDimension )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementDimension", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		usDimension = pLuaArgument.GetNumber< unsigned short >();

		return true;
	}

	return false;
}

bool Bindings::GetElementZoneName( lua_State* pLuaVM, PVOID pUserData, string& strOutName, bool bCitiesOnly )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bCitiesOnly );

	if( pLuaArguments.Call( pLuaVM, "getElementZoneName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutName = pLuaArgument.GetString();
		
			return true;
		}
	}

	return false;
}

bool Bindings::IsElementAttached( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementAttached", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

PVOID Bindings::GetElementAttachedTo( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementAttachedTo", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::GetElementColShape( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementColShape", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetElementAlpha( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucAlpha )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementAlpha", 1 ) )
	{
		ucAlpha = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::IsElementDoubleSided( lua_State* pLuaVM, PVOID pUserData, bool& bDoubleSided )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementDoubleSided", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bDoubleSided = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetElementHealth( lua_State* pLuaVM, PVOID pUserData, float& fHealth )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementHealth", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fHealth = pLuaArgument.GetNumber< float >();

		return true;
	}

	return false;
}

bool Bindings::GetElementModel( lua_State* pLuaVM, PVOID pUserData, unsigned short& usModel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementModel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		usModel = pLuaArgument.GetNumber< unsigned short >();

		return true;
	}

	return false;
}

bool Bindings::IsElementInWater( lua_State* pLuaVM, PVOID pUserData, bool& bInWater )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementInWater", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bInWater = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetElementAttachedOffsets( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecPosition, Math::Vector3& vecRotation )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementAttachedOffsets", 6 ) )
	{
		vecPosition.fX	= static_cast< float >( LuaArgument( pLuaVM, -6 ).GetNumber() );
		vecPosition.fY	= static_cast< float >( LuaArgument( pLuaVM, -5 ).GetNumber() );
		vecPosition.fZ	= static_cast< float >( LuaArgument( pLuaVM, -4 ).GetNumber() );
		vecRotation.fX	= static_cast< float >( LuaArgument( pLuaVM, -3 ).GetNumber() );
		vecRotation.fY	= static_cast< float >( LuaArgument( pLuaVM, -2 ).GetNumber() );
		vecRotation.fZ	= static_cast< float >( LuaArgument( pLuaVM, -1 ).GetNumber() );

		return true;
	}

	return false;
}

PVOID Bindings::GetElementSyncer( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementSyncer", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetElementCollisionsEnabled( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementCollisionsEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::IsElementFrozen( lua_State* pLuaVM, PVOID pUserData, bool& bFrozen )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementFrozen", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bFrozen = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetLowLodElement( lua_State* pLuaVM, PVOID pUserData, PVOID& pOutLowLodElement )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getLowLodElement", 1 ) )
	{
		pOutLowLodElement = LuaArgument( pLuaVM, -1 ).GetLightUserData();

		return true;
	}

	return false;
}

bool Bindings::IsElementLowLod( lua_State* pLuaVM, PVOID pUserData, bool& bOutLowLod )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementLowLod", 1 ) )
	{
		bOutLowLod = LuaArgument( pLuaVM, -1 ).GetBoolean();
	
		return true;
	}

	return false;
}

// Element set funcs

bool Bindings::ClearElementVisibleTo( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "clearElementVisibleTo", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementID( lua_State* pLuaVM, PVOID pUserData, string sID )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sID.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setElementID", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementData( lua_State* pLuaVM, PVOID pUserData, string sKey, const LuaArgument& Variable )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sKey.c_str() );
	pLuaArguments.PushArgument( Variable );

	if( pLuaArguments.Call( pLuaVM, "setElementData", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RemoveElementData( lua_State* pLuaVM, PVOID pUserData, string sKey )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sKey.c_str() );

	if( pLuaArguments.Call( pLuaVM, "removeElementData", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementParent( lua_State* pLuaVM, PVOID pUserData, PVOID pTarget )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pTarget );

	if( pLuaArguments.Call( pLuaVM, "setElementParent", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementPosition( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& vecPosition, bool bWarp )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushBoolean( bWarp );

	if( pLuaArguments.Call( pLuaVM, "setElementPosition", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementRotation( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& vecRotation, const char* szRotationOrder, bool bNewWay )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecRotation.fX );
	pLuaArguments.PushNumber( vecRotation.fY );
	pLuaArguments.PushNumber( vecRotation.fZ );
	pLuaArguments.PushString( szRotationOrder );
	pLuaArguments.PushBoolean( bNewWay );

	if( pLuaArguments.Call( pLuaVM, "setElementRotation", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementVelocity( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& vecVelocity )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecVelocity.fX );
	pLuaArguments.PushNumber( vecVelocity.fY );
	pLuaArguments.PushNumber( vecVelocity.fZ );

	if( pLuaArguments.Call( pLuaVM, "setElementVelocity", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementVisibleTo( lua_State* pLuaVM, PVOID pUserData, PVOID pTarget, bool bVisible )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pTarget );
	pLuaArguments.PushBoolean( bVisible );

	if( pLuaArguments.Call( pLuaVM, "setElementVisibleTo", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementInterior( lua_State* pLuaVM, PVOID pUserData, int iInterior )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iInterior );

	if( pLuaArguments.Call( pLuaVM, "setElementInterior", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementDimension( lua_State* pLuaVM, PVOID pUserData, int iDimension )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iDimension );

	if( pLuaArguments.Call( pLuaVM, "setElementDimension", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::AttachElements( lua_State* pLuaVM, PVOID pUserData, PVOID pTarget, Math::Vector3& vecPosition, Math::Vector3& vecRotation )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( vecRotation.fX );
	pLuaArguments.PushNumber( vecRotation.fY );
	pLuaArguments.PushNumber( vecRotation.fZ );

	if( pLuaArguments.Call( pLuaVM, "attachElements", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::DetachElements( lua_State* pLuaVM, PVOID pUserData, PVOID pTarget )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pTarget )
	{
		pLuaArguments.PushUserData( pTarget );
	}

	if( pLuaArguments.Call( pLuaVM, "detachElements", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementAlpha( lua_State* pLuaVM, PVOID pUserData, int iAlpha )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iAlpha );

	if( pLuaArguments.Call( pLuaVM, "setElementAlpha", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementDoubleSided( lua_State* pLuaVM, PVOID pUserData, bool bDoubleSided )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDoubleSided );

	if( pLuaArguments.Call( pLuaVM, "setElementDoubleSided", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementHealth( lua_State* pLuaVM, PVOID pUserData, float fHealth )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fHealth );

	if( pLuaArguments.Call( pLuaVM, "setElementHealth", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementModel( lua_State* pLuaVM, PVOID pUserData, int iModel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iModel );

	if( pLuaArguments.Call( pLuaVM, "setElementModel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementAttachedOffsets( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecPosition, Math::Vector3& vecRotation )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( vecRotation.fX );
	pLuaArguments.PushNumber( vecRotation.fY );
	pLuaArguments.PushNumber( vecRotation.fZ );

	if( pLuaArguments.Call( pLuaVM, "setElementAttachedOffsets", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementSyncer( lua_State* pLuaVM, PVOID pUserData, PVOID pPlayer )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pPlayer );

	if( pLuaArguments.Call( pLuaVM, "setElementSyncer", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementCollisionsEnabled( lua_State* pLuaVM, PVOID pUserData, bool bEnabled )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setElementCollisionsEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetElementFrozen( lua_State* pLuaVM, PVOID pUserData, bool bFrozen )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bFrozen );

	if( pLuaArguments.Call( pLuaVM, "setElementFrozen", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetLowLodElement( lua_State* pLuaVM, PVOID pUserData, bool bEnabled )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setLowLodElement", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Player get functions

unsigned int Bindings::GetPlayerCount( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getPlayerCount", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetNumber< unsigned int >();
	}

	return 0;
}

PVOID Bindings::GetPlayerFromName( lua_State* pLuaVM, const char* szNick )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szNick );

	if( pLuaArguments.Call( pLuaVM, "getPlayerFromName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetPlayerPing( lua_State* pLuaVM, PVOID pUserData, unsigned int& uiPing )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerPing", 1 ) )
	{
		uiPing = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool Bindings::GetPlayerMoney( lua_State* pLuaVM, PVOID pUserData, long& lMoney )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerMoney", 1 ) )
	{
		lMoney = LuaArgument( pLuaVM, -1 ).GetNumber< long >();

		return true;
	}

	return false;
}

PVOID Bindings::GetRandomPlayer( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getRandomPlayer", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return 0;
}

bool Bindings::IsPlayerMuted( lua_State* pLuaVM, PVOID pUserData, bool& bMuted )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPlayerMuted", 1 ) )
	{
		bMuted = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

PVOID Bindings::GetPlayerTeam( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerTeam", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetPlayerWantedLevel( lua_State* pLuaVM, PVOID pUserData, unsigned int& uiWantedLevel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerWantedLevel", 1 ) )
	{
		uiWantedLevel = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned int >();

		return true;
	}

	return false;
}

ArgumentsVector Bindings::GetAlivePlayers( lua_State* pLuaVM )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getAlivePlayers", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

ArgumentsVector Bindings::GetDeadPlayers( lua_State* pLuaVM )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getDeadPlayers", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

bool Bindings::GetPlayerIdleTime( lua_State* pLuaVM, PVOID pUserData, unsigned int& uiIdleTime )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerIdleTime", 1 ) )
	{
		uiIdleTime = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool Bindings::IsPlayerMapForced( lua_State* pLuaVM, PVOID pUserData, bool& bForced )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPlayerMapForced", 1 ) )
	{
		bForced = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetPlayerNametagText( lua_State* pLuaVM, PVOID pUserData, string& strOutText )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerNametagText", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutText = pLuaArgument.GetString();
			
			return true;
		}
	}

	return false;
}

bool Bindings::GetPlayerNametagColor( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucR, unsigned char& ucG, unsigned char& ucB )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerNametagColor", 3 ) )
	{
		ucR	= LuaArgument( pLuaVM, -3 ).GetNumber< unsigned char >();
		ucG	= LuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		ucB	= LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::IsPlayerNametagShowing( lua_State* pLuaVM, PVOID pUserData, bool& bShowing )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPlayerNametagShowing", 1 ) )
	{
		bShowing = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

string Bindings::GetPlayerSerial( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerSerial", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			return pLuaArgument.GetString();
		}
	}

	return string();
}

string Bindings::GetPlayerUserName( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerUserName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			return pLuaArgument.GetString();
		}
	}

	return string();
}

bool Bindings::GetPlayerBlurLevel( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucLevel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerBlurLevel", 1 ) )
	{
		ucLevel = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();
	}

	return false;
}

bool Bindings::GetPlayerName( lua_State* pLuaVM, PVOID pUserData, string& strOutName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutName = pLuaArgument.GetString();
		
			return true;
		}
	}

	return false;
}

bool Bindings::GetPlayerIP( lua_State* pLuaVM, PVOID pUserData, string& strOutIP )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerIP", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutIP = pLuaArgument.GetString();
		
			return true;
		}
	}

	return false;
}

PVOID Bindings::GetPlayerAccount( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerAccount", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

string Bindings::GetPlayerVersion( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerVersion", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			return pLuaArgument.GetString();
		}
	}

	return string();
}

ArgumentsMap Bindings::GetPlayerACInfo( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;
	
	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getPlayerACInfo", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}
	
	return pLuaArgument.GetTable();
}

// Player set functions

bool Bindings::SetPlayerMoney( lua_State* pLuaVM, PVOID pUserData, int iAmount, bool bInstant )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iAmount );
	pLuaArguments.PushBoolean( bInstant );

	if( pLuaArguments.Call( pLuaVM, "setPlayerMoney", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GivePlayerMoney( lua_State* pLuaVM, PVOID pUserData, int iAmount )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iAmount );

	if( pLuaArguments.Call( pLuaVM, "givePlayerMoney", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::TakePlayerMoney( lua_State* pLuaVM, PVOID pUserData, int iAmount )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iAmount );

	if( pLuaArguments.Call( pLuaVM, "takePlayerMoney", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SpawnPlayer( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecPosition, int iRotation, int iSkinID, int iInterior, int iDimension, PVOID pTeam )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( iRotation );
	pLuaArguments.PushNumber( iSkinID );
	pLuaArguments.PushNumber( iInterior );
	pLuaArguments.PushNumber( iDimension );

	if( pTeam )
	{
		pLuaArguments.PushUserData( pTeam );
	}

	if( pLuaArguments.Call( pLuaVM, "spawnPlayer", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ShowPlayerHudComponent( lua_State* pLuaVM, PVOID pUserData, string sComponent, bool bShow )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sComponent.c_str() );
	pLuaArguments.PushBoolean( bShow );

	if( pLuaArguments.Call( pLuaVM, "showPlayerHudComponent", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPlayerWantedLevel( lua_State* pLuaVM, PVOID pUserData, int iLevel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iLevel );

	if( pLuaArguments.Call( pLuaVM, "setPlayerWantedLevel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ForcePlayerMap( lua_State* pLuaVM, PVOID pUserData, bool bForceOn )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bForceOn );

	if( pLuaArguments.Call( pLuaVM, "forcePlayerMap", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPlayerNametagText( lua_State* pLuaVM, PVOID pUserData, string sText )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sText.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setPlayerNametagText", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPlayerNametagColor( lua_State* pLuaVM, PVOID pUserData, int iRed, int iGreen, int iBlue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iRed );
	pLuaArguments.PushNumber( iGreen );
	pLuaArguments.PushNumber( iBlue );

	if( pLuaArguments.Call( pLuaVM, "setPlayerNametagColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPlayerNametagShowing( lua_State* pLuaVM, PVOID pUserData, bool bShowing )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bShowing );

	if( pLuaArguments.Call( pLuaVM, "setPlayerNametagShowing", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPlayerMuted( lua_State* pLuaVM, PVOID pUserData, bool bMuted )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bMuted );

	if( pLuaArguments.Call( pLuaVM, "setPlayerMuted", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPlayerBlurLevel( lua_State* pLuaVM, PVOID pUserData, int iLevel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iLevel );

	if( pLuaArguments.Call( pLuaVM, "setPlayerBlurLevel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RedirectPlayer( lua_State* pLuaVM, PVOID pUserData, const char* szServerIP, int iServerPort, const char* szServerPassword )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szServerIP );
	pLuaArguments.PushNumber( iServerPort );
	pLuaArguments.PushString( szServerPassword );

	if( pLuaArguments.Call( pLuaVM, "redirectPlayer", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPlayerName( lua_State* pLuaVM, PVOID pUserData, string sName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sName.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setPlayerName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::DetonateSatchels( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "detonateSatchels", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::TakePlayerScreenShot( lua_State* pLuaVM, PVOID pUserData, int iWidth, int iHeight, string sTag, int iQuality, int iMaxBandwith )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iWidth );
	pLuaArguments.PushNumber( iHeight );
	pLuaArguments.PushString( sTag.c_str() );
	pLuaArguments.PushNumber( iQuality );
	pLuaArguments.PushNumber( iMaxBandwith );

	if( pLuaArguments.Call( pLuaVM, "takePlayerScreenShot", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Ped get functions

PVOID Bindings::CreatePed( lua_State* pLuaVM, int iModelid, const Math::Vector3& vecPosition, float fRot, bool bSynced )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( iModelid );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( fRot );
	pLuaArguments.PushBoolean( bSynced );

	if( pLuaArguments.Call( pLuaVM, "createPed", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetPedArmor( lua_State* pLuaVM, PVOID pUserData, float& fArmor )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedArmor", 1 ) )
	{
		fArmor = LuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

bool Bindings::IsPedChoking( lua_State* pLuaVM, PVOID pUserData, bool& bIsChoking )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedChoking", 1 ) )
	{
		bIsChoking = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsPedDead( lua_State* pLuaVM, PVOID pUserData, bool& bDead )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedDead", 1 ) )
	{
		bDead = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsPedDucked( lua_State* pLuaVM, PVOID pUserData, bool& bDucked )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedDucked", 1 ) )
	{
		bDucked = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetPedStat( lua_State* pLuaVM, PVOID pUserData, unsigned short usStat, float& fValue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usStat );

	if( pLuaArguments.Call( pLuaVM, "getPedStat", 1 ) )
	{
		fValue = LuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

PVOID Bindings::GetPedTarget( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedTarget", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

int Bindings::GetPedWeapon( lua_State* pLuaVM, PVOID pUserData, int iWeaponSlot )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iWeaponSlot );

	if( pLuaArguments.Call( pLuaVM, "getPedWeapon", 1 ) )
	{
		return LuaArgument( pLuaVM, -1 ).GetNumber< int >();
	}

	return 0;
}

bool Bindings::GetPedClothes( lua_State* pLuaVM, PVOID pUserData, unsigned char ucType, string& strOutTexture, string& strOutModel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucType );

	if( pLuaArguments.Call( pLuaVM, "getPedClothes", 2 ) )
	{
		strOutTexture	= LuaArgument( pLuaVM, -2 ).GetString();
		strOutModel		= LuaArgument( pLuaVM, -1 ).GetString();

		return true;
	}

	return false;
}

bool Bindings::DoesPedHaveJetPack( lua_State* pLuaVM, PVOID pUserData, bool& bHasJetPack )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "doesPedHaveJetPack", 1 ) )
	{
		bHasJetPack = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsPedOnGround( lua_State* pLuaVM, PVOID pUserData, bool& bOnGround )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedOnGround", 1 ) )
	{
		bOnGround = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetPedFightingStyle( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucStyle )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedFightingStyle", 1 ) )
	{
		ucStyle = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetPedMoveAnim( lua_State* pLuaVM, PVOID pUserData, unsigned int& iMoveAnim )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedMoveAnim", 1 ) )
	{
		iMoveAnim = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool Bindings::GetPedGravity( lua_State* pLuaVM, PVOID pUserData, float& fGravity )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedGravity", 1 ) )
	{
		fGravity = LuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

PVOID Bindings::GetPedContactElement( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedContactElement", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetPedWeaponSlot( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucWeaponSlot )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedWeaponSlot", 1 ) )
	{
		ucWeaponSlot = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::IsPedDoingGangDriveby( lua_State* pLuaVM, PVOID pUserData, bool & bDoingGangDriveby )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedDoingGangDriveby", 1 ) )
	{
		bDoingGangDriveby = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsPedOnFire( lua_State* pLuaVM, PVOID pUserData, bool & bIsOnFire )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedOnFire", 1 ) )
	{
		bIsOnFire = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsPedHeadless( lua_State* pLuaVM, PVOID pUserData, bool & bIsHeadless )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedHeadless", 1 ) )
	{
		bIsHeadless = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsPedFrozen( lua_State* pLuaVM, PVOID pUserData, bool & bIsFrozen )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedFrozen", 1 ) )
	{
		bIsFrozen = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

PVOID Bindings::GetPedOccupiedVehicle( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedOccupiedVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetPedOccupiedVehicleSeat( lua_State* pLuaVM, PVOID pUserData, unsigned int& uiSeat )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedOccupiedVehicleSeat", 1 ) )
	{
		uiSeat = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool Bindings::IsPedInVehicle( lua_State* pLuaVM, PVOID pUserData, bool & bIsInVehicle )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedInVehicle", 1 ) )
	{
		bIsInVehicle = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetWeaponProperty( lua_State* pLuaVM, unsigned char ucWeaponID, const char* szWeaponSkill, const char* szProperty, short& uData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushString( szWeaponSkill );
	pLuaArguments.PushString( szProperty );

	if( pLuaArguments.Call( pLuaVM, "getWeaponProperty", 1 ) )
	{
		uData = LuaArgument( pLuaVM, -1 ).GetNumber< short >();

		return true;
	}
	
	return false;
}

bool Bindings::GetOriginalWeaponProperty( lua_State* pLuaVM, unsigned char ucWeaponID, const char* szWeaponSkill, const char* szProperty, short& uData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushString( szWeaponSkill );
	pLuaArguments.PushString( szProperty );

	if( pLuaArguments.Call( pLuaVM, "getOriginalWeaponProperty", 1 ) )
	{
		uData = LuaArgument( pLuaVM, -1 ).GetNumber< short >();

		return true;
	}
	
	return false;
}

// Ped set functions

bool Bindings::SetPedArmor( lua_State* pLuaVM, PVOID pUserData, float fArmor )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fArmor );

	if( pLuaArguments.Call( pLuaVM, "setPedArmor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::KillPed( lua_State* pLuaVM, PVOID pUserData, PVOID pKiller, unsigned char ucKillerWeapon, unsigned char ucBodyPart, bool bStealth )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pKiller );
	pLuaArguments.PushNumber( ucKillerWeapon );
	pLuaArguments.PushNumber( ucBodyPart );
	pLuaArguments.PushBoolean( bStealth );

	if( pLuaArguments.Call( pLuaVM, "killPed", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedStat( lua_State* pLuaVM, PVOID pUserData, unsigned short usStat, float fValue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usStat );
	pLuaArguments.PushNumber( fValue );

	if( pLuaArguments.Call( pLuaVM, "setPedStat", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::AddPedClothes( lua_State* pLuaVM, PVOID pUserData, const char* szTexture, const char* szModel, unsigned char ucType )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szTexture );
	pLuaArguments.PushString( szModel );
	pLuaArguments.PushNumber( ucType );

	if( pLuaArguments.Call( pLuaVM, "addPedClothes", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RemovePedClothes( lua_State* pLuaVM, PVOID pUserData, unsigned char ucType, const char* szTexture, const char* szModel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucType );
	pLuaArguments.PushString( szTexture );
	pLuaArguments.PushString( szModel );

	if( pLuaArguments.Call( pLuaVM, "removePedClothes", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GivePedJetPack( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "givePedJetPack", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RemovePedJetPack( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "removePedJetPack", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedFightingStyle( lua_State* pLuaVM, PVOID pUserData, unsigned char ucStyle )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucStyle );

	if( pLuaArguments.Call( pLuaVM, "setPedFightingStyle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedMoveAnim( lua_State* pLuaVM, PVOID pUserData, unsigned int iMoveAnim )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iMoveAnim );

	if( pLuaArguments.Call( pLuaVM, "setPedMoveAnim", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedGravity( lua_State* pLuaVM, PVOID pUserData, float fGravity )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fGravity );

	if( pLuaArguments.Call( pLuaVM, "setPedGravity", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedChoking( lua_State* pLuaVM, PVOID pUserData, bool bChoking )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bChoking );

	if( pLuaArguments.Call( pLuaVM, "setPedChoking", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedWeaponSlot( lua_State* pLuaVM, PVOID pUserData, unsigned char ucWeaponSlot )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucWeaponSlot );

	if( pLuaArguments.Call( pLuaVM, "setPedWeaponSlot", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::WarpPedIntoVehicle( lua_State* pLuaVM, PVOID pUserData, PVOID pVehicle, unsigned int uiSeat )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pVehicle );
	pLuaArguments.PushNumber( uiSeat );

	if( pLuaArguments.Call( pLuaVM, "warpPedIntoVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RemovePedFromVehicle( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "removePedFromVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedDoingGangDriveby( lua_State* pLuaVM, PVOID pUserData, bool bGangDriveby )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bGangDriveby );

	if( pLuaArguments.Call( pLuaVM, "setPedDoingGangDriveby", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedAnimation( lua_State* pLuaVM, PVOID pUserData, const char * szBlockName, const char * szAnimName, int iTime, bool bLoop, bool bUpdatePosition, bool bInterruptable, bool bFreezeLastFrame )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szBlockName );
	pLuaArguments.PushString( szAnimName );
	pLuaArguments.PushNumber( iTime );
	pLuaArguments.PushBoolean( bLoop );
	pLuaArguments.PushBoolean( bUpdatePosition );
	pLuaArguments.PushBoolean( bInterruptable );
	pLuaArguments.PushBoolean( bFreezeLastFrame );

	if( pLuaArguments.Call( pLuaVM, "setPedAnimation", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedAnimationProgress( lua_State* pLuaVM, PVOID pUserData, const char * szAnimName, float fProgress )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szAnimName );
	pLuaArguments.PushNumber( fProgress );

	if( pLuaArguments.Call( pLuaVM, "setPedAnimationProgress", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedOnFire( lua_State* pLuaVM, PVOID pUserData, bool bIsOnFire )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bIsOnFire );

	if( pLuaArguments.Call( pLuaVM, "setPedOnFire", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedHeadless( lua_State* pLuaVM, PVOID pUserData, bool bIsHeadless )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bIsHeadless );

	if( pLuaArguments.Call( pLuaVM, "setPedHeadless", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedFrozen( lua_State* pLuaVM, PVOID pUserData, bool bIsFrozen )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bIsFrozen );

	if( pLuaArguments.Call( pLuaVM, "setPedFrozen", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ReloadPedWeapon( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "reloadPedWeapon", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetWeaponProperty( lua_State* pLuaVM, unsigned char ucWeaponID, const char* szWeaponSkill, const char* szProperty, short uData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushString( szWeaponSkill );
	pLuaArguments.PushString( szProperty );
	pLuaArguments.PushNumber( uData );

	if( pLuaArguments.Call( pLuaVM, "setWeaponProperty", 1 ) )
	{
		return LuaArgument( pLuaVM, -1 ).GetBoolean();
	}
	
	return false;
}

// Vehicle create/destroy functions

PVOID Bindings::CreateVehicle( lua_State* pLuaVM, int model, float fX, float fY, float fZ, float fRX, float fRY, float fRZ, string numberplate, bool direction, int variant1, int variant2 )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( model );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRX );
	pLuaArguments.PushNumber( fRY );
	pLuaArguments.PushNumber( fRZ );

	if( numberplate.length() > 0 )
	{
		pLuaArguments.PushString( numberplate.c_str() );
		pLuaArguments.PushBoolean( direction );
		pLuaArguments.PushNumber( variant1 );
		pLuaArguments.PushNumber( variant2 );
	}

	if( pLuaArguments.Call( pLuaVM, "createVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

// Vehicle get functions

bool Bindings::GetVehicleType( lua_State* pLuaVM, PVOID pUserData, string& strType )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleType", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strType = pLuaArgument.GetString();
		}

		return true;
	}

	return false;
}

bool Bindings::GetVehicleVariant( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucVariant, unsigned char& ucVariant2 )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleVariant", 2 ) )
	{
		ucVariant	= static_cast< unsigned char >( LuaArgument( pLuaVM, -2 ).GetNumber() );
		ucVariant2	= static_cast< unsigned char >( LuaArgument( pLuaVM, -1 ).GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetVehicleColor( lua_State* pLuaVM, PVOID pUserData, SharedUtil::VehicleColor& color )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( true );

	int iLuaTop = lua_gettop( pLuaVM );

	if( pLuaArguments.Call( pLuaVM, "getVehicleColor", 9 ) )
	{
		SharedUtil::Color color1, color2, color3, color4;

		int iResults = lua_gettop( pLuaVM ) - iLuaTop;

		for( int iArgument	= -iResults, i = 1; iArgument < 0; iArgument++, i++ )
		{
			ASSERT( lua_type( pLuaVM, iArgument ) == LUA_TNUMBER );

			unsigned char ucValue = static_cast< unsigned char >( lua_tonumber( pLuaVM, iArgument ) );

			switch( i )
			{
				case 1: color1.R  = ucValue; break;
				case 2: color1.G  = ucValue; break;
				case 3: color1.B  = ucValue; break;

				case 4: color2.R  = ucValue; break;
				case 5: color2.G  = ucValue; break;
				case 6: color2.B  = ucValue; break;

				case 7: color3.R  = ucValue; break;
				case 8: color3.G  = ucValue; break;
				case 9: color3.B  = ucValue; break;

				case 10: color4.R = ucValue; break;
				case 11: color4.G = ucValue; break;
				case 12: color4.B = ucValue; break;
			}
		}

		color1.A = color2.A = color3.A = color4.A = 255;

		color.SetRGBColors( color1, color2, color3, color4 );

		return true;
	}

	return false;
}

bool Bindings::GetVehicleModelFromName( lua_State* pLuaVM, const char* szName, unsigned short& usID )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );

	if( pLuaArguments.Call( pLuaVM, "getVehicleModelFromName", 1 ) )
	{
		usID = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned short >();

		return true;
	}

	return false;
}

bool Bindings::GetVehicleLandingGearDown( lua_State* pLuaVM, PVOID pUserData, bool& bGearDown )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleLandingGearDown", 1 ) )
	{
		bGearDown = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetVehicleMaxPassengers( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucMaxPassengers )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleMaxPassengers", 1 ) )
	{
		ucMaxPassengers = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetVehicleName( lua_State* pLuaVM, PVOID pUserData, string& strOutName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutName = pLuaArgument.GetString();
		}

		return true;
	}

	return false;
}

bool Bindings::GetVehicleNameFromModel( lua_State* pLuaVM, unsigned short usModel, string& strOutName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usModel );

	if( pLuaArguments.Call( pLuaVM, "getVehicleNameFromModel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutName = pLuaArgument.GetString();
		}

		return true;
	}

	return false;
}

PVOID Bindings::GetVehicleOccupant( lua_State* pLuaVM, PVOID pUserData, unsigned int uiSeat )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( uiSeat );

	if( pLuaArguments.Call( pLuaVM, "getVehicleOccupant", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

ArgumentsVector Bindings::GetVehicleOccupants( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleOccupants", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

PVOID Bindings::GetVehicleController( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleController", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetVehicleSirensOn( lua_State* pLuaVM, PVOID pUserData, bool& bSirensOn )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleSirensOn", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			bSirensOn = pLuaArgument.GetBoolean();

			return true;
		}
	}

	return false;
}

bool Bindings::GetVehicleTurnVelocity( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecTurnVelocity )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTurnVelocity", 3 ) )
	{
		vecTurnVelocity.fX = LuaArgument( pLuaVM, -3 ).GetNumber< float >();
		vecTurnVelocity.fY = LuaArgument( pLuaVM, -2 ).GetNumber< float >();
		vecTurnVelocity.fZ = LuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

bool Bindings::GetVehicleTurretPosition( lua_State* pLuaVM, PVOID pUserData, Math::Vector2& vecPosition )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTurretPosition", 2 ) )
	{
		vecPosition.fX = LuaArgument( pLuaVM, -2 ).GetNumber< float >();
		vecPosition.fY = LuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

bool Bindings::IsVehicleLocked( lua_State* pLuaVM, PVOID pUserData, bool& bLocked )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleLocked", 1 ) )
	{
		bLocked = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

ArgumentsVector Bindings::GetVehiclesOfType( lua_State* pLuaVM, unsigned int uiModel )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( uiModel );

	if( pLuaArguments.Call( pLuaVM, "getVehiclesOfType", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

bool Bindings::GetVehicleUpgradeOnSlot( lua_State* pLuaVM, PVOID pUserData, unsigned char ucSlot, unsigned short& usUpgrade )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucSlot );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgradeOnSlot", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Number )
		{
			usUpgrade = pLuaArgument.GetNumber< unsigned short >();

			return true;
		}
	}

	return false;
}

ArgumentsVector Bindings::GetVehicleUpgrades( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgrades", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

bool Bindings::GetVehicleUpgradeSlotName( lua_State* pLuaVM, unsigned char ucSlot, string& strOutName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucSlot );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgradeSlotName", 1 ) )
	{
		strOutName = LuaArgument( pLuaVM, -1 ).GetString();
		
		return true;
	}

	return false;
}

bool Bindings::GetVehicleUpgradeSlotName( lua_State* pLuaVM, unsigned short usUpgrade, string& strOutName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usUpgrade );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgradeSlotName", 1 ) )
	{
		strOutName = LuaArgument( pLuaVM, -1 ).GetString();
		
		return true;
	}

	return false;
}

ArgumentsVector Bindings::GetVehicleCompatibleUpgrades( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleCompatibleUpgrades", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

bool Bindings::GetVehicleDoorState( lua_State* pLuaVM, PVOID pUserData, unsigned char ucDoor, unsigned char& ucState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucDoor );

	if( pLuaArguments.Call( pLuaVM, "getVehicleDoorState", 1 ) )
	{
		ucState = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetVehicleWheelStates( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucFrontLeft, unsigned char& ucRearLeft, unsigned char& ucFrontRight, unsigned char& ucRearRight )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleWheelStates", 4 ) )
	{
		ucFrontLeft		= static_cast< unsigned char >( LuaArgument( pLuaVM, -4 ).GetNumber() );
		ucRearLeft		= static_cast< unsigned char >( LuaArgument( pLuaVM, -3 ).GetNumber() );
		ucFrontRight	= static_cast< unsigned char >( LuaArgument( pLuaVM, -2 ).GetNumber() );
		ucRearRight		= static_cast< unsigned char >( LuaArgument( pLuaVM, -1 ).GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetVehicleLightState( lua_State* pLuaVM, PVOID pUserData, unsigned char ucLight, unsigned char& ucState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucLight );

	if( pLuaArguments.Call( pLuaVM, "getVehicleLightState", 1 ) )
	{
		ucState = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetVehiclePanelState( lua_State* pLuaVM, PVOID pUserData, unsigned char ucPanel, unsigned char& ucState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucPanel );

	if( pLuaArguments.Call( pLuaVM, "getVehiclePanelState", 1 ) )
	{
		ucState = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetVehicleOverrideLights( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucLights )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleOverrideLights", 1 ) )
	{
		ucLights = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

PVOID Bindings::GetVehicleTowedByVehicle( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTowedByVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::GetVehicleTowingVehicle( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTowingVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetVehiclePaintjob( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucPaintjob )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehiclePaintjob", 1 ) )
	{
		ucPaintjob = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetVehiclePlateText( lua_State* pLuaVM, PVOID pUserData, char* szPlateText )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehiclePlateText", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		strncpy( szPlateText, pLuaArgument.GetString(), 8 );

		return true;
	}

	return false;
}

bool Bindings::IsVehicleDamageProof( lua_State* pLuaVM, PVOID pUserData, bool& bDamageProof )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleDamageProof", 1 ) )
	{
		bDamageProof = LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsVehicleFuelTankExplodable( lua_State* pLuaVM, PVOID pUserData, bool& bExplodable )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleFuelTankExplodable", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bExplodable = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsVehicleFrozen( lua_State* pLuaVM, PVOID pUserData, bool& bFrozen )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleFrozen", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bFrozen = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsVehicleOnGround( lua_State* pLuaVM, PVOID pUserData, bool& bOnGround )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleOnGround", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bOnGround = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetVehicleEngineState( lua_State* pLuaVM, PVOID pUserData, bool& bState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleEngineState", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bState = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsTrainDerailed( lua_State* pLuaVM, PVOID pUserData, bool& bDerailed )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isTrainDerailed", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bDerailed = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsTrainDerailable( lua_State* pLuaVM, PVOID pUserData, bool& bDerailable )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isTrainDerailable", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bDerailable = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetTrainDirection( lua_State* pLuaVM, PVOID pUserData, bool& bDirection )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getTrainDirection", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bDirection = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::GetTrainSpeed( lua_State* pLuaVM, PVOID pUserData, float& fSpeed )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getTrainSpeed", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fSpeed = pLuaArgument.GetNumber< float >();

		return true;
	}

	return false;
}

bool Bindings::IsVehicleBlown( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleBlown", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GetVehicleHeadLightColor( lua_State* pLuaVM, PVOID pUserData, SharedUtil::Color& outColor )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleHeadLightColor", 3 ) )
	{
		outColor.R = LuaArgument( pLuaVM, -3 ).GetNumber< unsigned char >();
		outColor.G = LuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		outColor.B = LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetVehicleDoorOpenRatio( lua_State* pLuaVM, PVOID pUserData, unsigned char ucDoor, float& fRatio )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucDoor );

	if( pLuaArguments.Call( pLuaVM, "getVehicleDoorOpenRatio", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fRatio = pLuaArgument.GetNumber< float >();

		return true;
	}

	return false;
}

bool Bindings::IsVehicleTaxiLightOn( lua_State* pLuaVM, PVOID pUserData, bool& bLightOn )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleTaxiLightOn", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bLightOn = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

// Vehicle set functions

bool Bindings::FixVehicle( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "fixVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::BlowVehicle( lua_State* pLuaVM, PVOID pUserData, bool bExplode )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bExplode );

	if( pLuaArguments.Call( pLuaVM, "blowVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleTurnVelocity( lua_State* pLuaVM, PVOID pUserData, float fX, float fY, float fZ )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );

	if( pLuaArguments.Call( pLuaVM, "setVehicleTurnVelocity", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleColor( lua_State* pLuaVM, PVOID pUserData, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue, unsigned char ucRed2, unsigned char ucGreen2, unsigned char ucBlue2, unsigned char ucRed3, unsigned char ucGreen3, unsigned char ucBlue3, unsigned char ucRed4, unsigned char ucGreen4, unsigned char ucBlue4 )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	pLuaArguments.PushNumber( ucRed2 );
	pLuaArguments.PushNumber( ucGreen2 );
	pLuaArguments.PushNumber( ucBlue2 );

	pLuaArguments.PushNumber( ucRed3 );
	pLuaArguments.PushNumber( ucGreen3 );
	pLuaArguments.PushNumber( ucBlue3 );

	pLuaArguments.PushNumber( ucRed4 );
	pLuaArguments.PushNumber( ucGreen4 );
	pLuaArguments.PushNumber( ucBlue4 );

	if( pLuaArguments.Call( pLuaVM, "setVehicleColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleLandingGearDown( lua_State* pLuaVM, PVOID pUserData, bool bLandingGearDown )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bLandingGearDown );

	if( pLuaArguments.Call( pLuaVM, "setVehicleLandingGearDown", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleLocked( lua_State* pLuaVM, PVOID pUserData, bool bLocked )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bLocked );

	if( pLuaArguments.Call( pLuaVM, "setVehicleLocked", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleDoorsUndamageable( lua_State* pLuaVM, PVOID pUserData, bool bDoorsUndamageable )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDoorsUndamageable );

	if( pLuaArguments.Call( pLuaVM, "setVehicleDoorsUndamageable", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleSirensOn( lua_State* pLuaVM, PVOID pUserData, bool bSirensOn )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bSirensOn );

	if( pLuaArguments.Call( pLuaVM, "setVehicleSirensOn", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleTaxiLightOn( lua_State* pLuaVM, PVOID pUserData, bool bTaxiLightState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bTaxiLightState );

	if( pLuaArguments.Call( pLuaVM, "setVehicleTaxiLightOn", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::AddVehicleUpgrade( lua_State* pLuaVM, PVOID pUserData, unsigned short usUpgrade )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usUpgrade );

	if( pLuaArguments.Call( pLuaVM, "addVehicleUpgrade", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RemoveVehicleUpgrade( lua_State* pLuaVM, PVOID pUserData, unsigned short usUpgrade )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usUpgrade );

	if( pLuaArguments.Call( pLuaVM, "removeVehicleUpgrade", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleDoorState( lua_State* pLuaVM, PVOID pUserData, unsigned char ucDoor, unsigned char ucState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucDoor );
	pLuaArguments.PushNumber( ucState );

	if( pLuaArguments.Call( pLuaVM, "setVehicleDoorState", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleWheelStates( lua_State* pLuaVM, PVOID pUserData, int iFrontLeft, int iRearLeft, int iFrontRight, int iRearRight )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iFrontLeft );
	pLuaArguments.PushNumber( iRearLeft );
	pLuaArguments.PushNumber( iFrontRight );
	pLuaArguments.PushNumber( iRearRight );

	if( pLuaArguments.Call( pLuaVM, "setVehicleWheelStates", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleLightState( lua_State* pLuaVM, PVOID pUserData, unsigned char ucLight, unsigned char ucState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucLight );
	pLuaArguments.PushNumber( ucState );

	if( pLuaArguments.Call( pLuaVM, "setVehicleLightState", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehiclePanelState( lua_State* pLuaVM, PVOID pUserData, unsigned char ucPanel, unsigned char ucState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucPanel );
	pLuaArguments.PushNumber( ucState );

	if( pLuaArguments.Call( pLuaVM, "setVehiclePanelState", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleIdleRespawnDelay( lua_State* pLuaVM, PVOID pUserData, unsigned long ulTime )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ulTime );

	if( pLuaArguments.Call( pLuaVM, "setVehicleIdleRespawnDelay", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleRespawnDelay( lua_State* pLuaVM, PVOID pUserData, unsigned long ulTime )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ulTime );

	if( pLuaArguments.Call( pLuaVM, "setVehicleRespawnDelay", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleRespawnPosition( lua_State* pLuaVM, PVOID pUserData, float fX, float fY, float fZ, float fRX, float fRY, float fRZ )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRX );
	pLuaArguments.PushNumber( fRY );
	pLuaArguments.PushNumber( fRZ );

	if( pLuaArguments.Call( pLuaVM, "setVehicleRespawnPosition", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ToggleVehicleRespawn( lua_State* pLuaVM, PVOID pUserData, bool bRespawn )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( bRespawn );

	if( pLuaArguments.Call( pLuaVM, "toggleVehicleRespawn", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetVehicleExplosionTime( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "resetVehicleExplosionTime", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetVehicleIdleTime( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "resetVehicleIdleTime", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SpawnVehicle( lua_State* pLuaVM, PVOID pUserData, float fX, float fY, float fZ, float fRX, float fRY, float fRZ )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRX );
	pLuaArguments.PushNumber( fRY );
	pLuaArguments.PushNumber( fRZ );

	if( pLuaArguments.Call( pLuaVM, "spawnVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RespawnVehicle( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "respawnVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleOverrideLights( lua_State* pLuaVM, PVOID pUserData, unsigned char ucLights )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucLights );

	if( pLuaArguments.Call( pLuaVM, "setVehicleOverrideLights", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::AttachTrailerToVehicle( lua_State* pLuaVM, PVOID pUserData, PVOID pTrailer )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pTrailer );

	if( pLuaArguments.Call( pLuaVM, "attachTrailerToVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::DetachTrailerFromVehicle( lua_State* pLuaVM, PVOID pUserData, PVOID pTrailer )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pTrailer )
	{
		pLuaArguments.PushUserData( pTrailer );
	}

	if( pLuaArguments.Call( pLuaVM, "detachTrailerFromVehicle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleEngineState( lua_State* pLuaVM, PVOID pUserData, bool bState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bState );

	if( pLuaArguments.Call( pLuaVM, "setVehicleEngineState", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleDirtLevel( lua_State* pLuaVM, PVOID pUserData, float fDirtLevel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fDirtLevel );

	if( pLuaArguments.Call( pLuaVM, "setVehicleDirtLevel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleDamageProof( lua_State* pLuaVM, PVOID pUserData, bool bDamageProof )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDamageProof );

	if( pLuaArguments.Call( pLuaVM, "setVehicleDamageProof", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehiclePaintjob( lua_State* pLuaVM, PVOID pUserData, unsigned char ucPaintjob )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucPaintjob );

	if( pLuaArguments.Call( pLuaVM, "setVehiclePaintjob", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleFuelTankExplodable( lua_State* pLuaVM, PVOID pUserData, bool bExplodable )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bExplodable );

	if( pLuaArguments.Call( pLuaVM, "setVehicleFuelTankExplodable", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleFrozen( lua_State* pLuaVM, PVOID pUserData, bool bFrozen )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bFrozen );

	if( pLuaArguments.Call( pLuaVM, "setVehicleFrozen", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetTrainDerailed( lua_State* pLuaVM, PVOID pUserData, bool bDerailed )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDerailed );

	if( pLuaArguments.Call( pLuaVM, "setTrainDerailed", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetTrainDerailable( lua_State* pLuaVM, PVOID pUserData, bool bDerailable )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDerailable );

	if( pLuaArguments.Call( pLuaVM, "setTrainDerailable", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetTrainDirection( lua_State* pLuaVM, PVOID pUserData, bool bDireciton )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDireciton );

	if( pLuaArguments.Call( pLuaVM, "setTrainDirection", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetTrainSpeed( lua_State* pLuaVM, PVOID pUserData, float fSpeed )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fSpeed );

	if( pLuaArguments.Call( pLuaVM, "setTrainDirection", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleHeadLightColor( lua_State* pLuaVM, PVOID pUserData, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	if( pLuaArguments.Call( pLuaVM, "setVehicleHeadLightColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleTurretPosition( lua_State* pLuaVM, PVOID pUserData, float fHorizontal, float fVertical )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fHorizontal );
	pLuaArguments.PushNumber( fVertical );

	if( pLuaArguments.Call( pLuaVM, "setVehicleTurretPosition", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleDoorOpenRatio( lua_State* pLuaVM, PVOID pUserData, unsigned char ucDoor, float fRatio, unsigned long ulTime )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucDoor );
	pLuaArguments.PushNumber( fRatio );
	pLuaArguments.PushNumber( ulTime );

	if( pLuaArguments.Call( pLuaVM, "setVehicleDoorOpenRatio", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleVariant( lua_State* pLuaVM, PVOID pUserData, unsigned char ucVariant, unsigned char ucVariant2 )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucVariant );
	pLuaArguments.PushNumber( ucVariant2 );

	if( pLuaArguments.Call( pLuaVM, "setVehicleVariant", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GiveVehicleSirens( lua_State* pLuaVM, PVOID pUserData, unsigned char ucSirenType, unsigned char ucSirenCount, bool bFlag360, bool bCheckLosFlag, bool bUseRandomiserFlag, bool bSilentFlag )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucSirenType );
	pLuaArguments.PushNumber( ucSirenCount );
	pLuaArguments.PushBoolean( bFlag360 );
	pLuaArguments.PushBoolean( bCheckLosFlag );
	pLuaArguments.PushBoolean( bUseRandomiserFlag );
	pLuaArguments.PushBoolean( bSilentFlag );

	if( pLuaArguments.Call( pLuaVM, "addVehicleSirens", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RemoveVehicleSirens( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "removeVehicleSirens", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehicleSirens( lua_State* pLuaVM, PVOID pUserData, unsigned char ucSirenID, float fX, float fY, float fZ, float fRed, float fGreen, float fBlue, float fAlpha, float fMinAlpha )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucSirenID );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRed );
	pLuaArguments.PushNumber( fGreen );
	pLuaArguments.PushNumber( fBlue );
	pLuaArguments.PushNumber( fAlpha );
	pLuaArguments.PushNumber( fMinAlpha );

	if( pLuaArguments.Call( pLuaVM, "setVehicleSirens", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetVehiclePlateText( lua_State* pLuaVM, PVOID pUserData, const char* szName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szName );

	if( pLuaArguments.Call( pLuaVM, "setVehiclePlateText", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Marker create/destroy functions

PVOID Bindings::CreateMarker( lua_State* pLuaVM, const Math::Vector3& vecPosition, const char* szType, float fSize, const SharedUtil::Color color, PVOID pVisibleTo )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushString( szType );
	pLuaArguments.PushNumber( fSize );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );
	pLuaArguments.PushUserData( pVisibleTo );

	if( pLuaArguments.Call( pLuaVM, "createMarker", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

// Marker get functions

bool Bindings::GetMarkerCount( lua_State* pLuaVM, unsigned int& uiCount )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getMarkerCount", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		uiCount = static_cast< unsigned int >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetMarkerType( lua_State* pLuaVM, PVOID pUserData, char* szType )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerType", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		strncpy( szType, pLuaArgument.GetString(), strlen( szType ) );

		return true;
	}

	return false;
}

bool Bindings::GetMarkerSize( lua_State* pLuaVM, PVOID pUserData, float& fSize )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fSize = static_cast< float >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetMarkerColor( lua_State* pLuaVM, PVOID pUserData, SharedUtil::Color& outColor )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerColor", 4 ) )
	{
		outColor.R	= static_cast< unsigned char >( LuaArgument( pLuaVM, -4 ).GetNumber() );
		outColor.G	= static_cast< unsigned char >( LuaArgument( pLuaVM, -3 ).GetNumber() );
		outColor.B	= static_cast< unsigned char >( LuaArgument( pLuaVM, -2 ).GetNumber() );
		outColor.A	= static_cast< unsigned char >( LuaArgument( pLuaVM, -1 ).GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetMarkerTarget( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecTarget )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerTarget", 3 ) )
	{
		vecTarget.fX	= static_cast< unsigned char >( LuaArgument( pLuaVM, -3 ).GetNumber() );
		vecTarget.fY	= static_cast< unsigned char >( LuaArgument( pLuaVM, -2 ).GetNumber() );
		vecTarget.fZ	= static_cast< unsigned char >( LuaArgument( pLuaVM, -1 ).GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetMarkerIcon( lua_State* pLuaVM, PVOID pUserData, char* szIcon )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerIcon", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		strncpy( szIcon, pLuaArgument.GetString(), strlen( szIcon ) );

		return true;
	}

	return false;
}

// Marker set functions

bool Bindings::SetMarkerType( lua_State* pLuaVM, PVOID pUserData, const char* szType )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szType );

	if( pLuaArguments.Call( pLuaVM, "setMarkerType", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetMarkerSize( lua_State* pLuaVM, PVOID pUserData, float fSize )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fSize );

	if( pLuaArguments.Call( pLuaVM, "setMarkerSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetMarkerColor( lua_State* pLuaVM, PVOID pUserData, const SharedUtil::Color color )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );

	if( pLuaArguments.Call( pLuaVM, "setMarkerColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetMarkerTarget( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& pTarget )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( pTarget.fX );
	pLuaArguments.PushNumber( pTarget.fY );
	pLuaArguments.PushNumber( pTarget.fZ );

	if( pLuaArguments.Call( pLuaVM, "setMarkerTarget", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetMarkerIcon( lua_State* pLuaVM, PVOID pUserData, const char* szIcon )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szIcon );

	if( pLuaArguments.Call( pLuaVM, "setMarkerIcon", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Blip create/destroy functions

PVOID Bindings::CreateBlip( lua_State* pLuaVM, const Math::Vector3& vecPosition, unsigned char ucIcon, unsigned char ucSize, const SharedUtil::Color color, short sOrdering, unsigned short usVisibleDistance, PVOID pVisibleTo )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( ucIcon );
	pLuaArguments.PushNumber( ucSize );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );
	pLuaArguments.PushNumber( sOrdering );
	pLuaArguments.PushNumber( usVisibleDistance );

	if( pVisibleTo )
	{
		pLuaArguments.PushUserData( pVisibleTo );
	}

	if( pLuaArguments.Call( pLuaVM, "createBlip", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::CreateBlipAttachedTo( lua_State* pLuaVM, PVOID pTarget, unsigned char ucIcon, unsigned char ucSize, const SharedUtil::Color color, short sOrdering, unsigned short usVisibleDistance, PVOID pVisibleTo )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTarget );
	pLuaArguments.PushNumber( ucIcon );
	pLuaArguments.PushNumber( ucSize );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );
	pLuaArguments.PushNumber( sOrdering );
	pLuaArguments.PushNumber( usVisibleDistance );

	if( pVisibleTo )
	{
		pLuaArguments.PushUserData( pVisibleTo );
	}

	if( pLuaArguments.Call( pLuaVM, "createBlip", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

// Blip get functions

bool Bindings::GetBlipIcon( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucIcon )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getBlipIcon", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		ucIcon = static_cast< unsigned char >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetBlipSize( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucSize )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getBlipSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		ucSize = static_cast< unsigned char >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetBlipColor( lua_State* pLuaVM, PVOID pUserData, SharedUtil::Color& outColor )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getBlipColor", 4 ) )
	{
		outColor.R	= static_cast< unsigned char >( LuaArgument( pLuaVM, -4 ).GetNumber() );
		outColor.G	= static_cast< unsigned char >( LuaArgument( pLuaVM, -3 ).GetNumber() );
		outColor.B	= static_cast< unsigned char >( LuaArgument( pLuaVM, -2 ).GetNumber() );
		outColor.A	= static_cast< unsigned char >( LuaArgument( pLuaVM, -1 ).GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetBlipOrdering( lua_State* pLuaVM, PVOID pUserData, short& sOrdering )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getBlipOrdering", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		sOrdering = static_cast< short >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetBlipVisibleDistance( lua_State* pLuaVM, PVOID pUserData, unsigned short& usVisibleDistance )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getBlipVisibleDistance", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		usVisibleDistance = static_cast< unsigned short >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

// Blip set functions

bool Bindings::SetBlipIcon( lua_State* pLuaVM, PVOID pUserData, unsigned char ucIcon )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucIcon );

	if( pLuaArguments.Call( pLuaVM, "setBlipIcon", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetBlipSize( lua_State* pLuaVM, PVOID pUserData, unsigned char ucSize )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucSize );

	if( pLuaArguments.Call( pLuaVM, "setBlipSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetBlipColor( lua_State* pLuaVM, PVOID pUserData, const SharedUtil::Color color )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );

	if( pLuaArguments.Call( pLuaVM, "setBlipColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetBlipOrdering( lua_State* pLuaVM, PVOID pUserData, short sOrdering )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( sOrdering );

	if( pLuaArguments.Call( pLuaVM, "setBlipOrdering", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetBlipVisibleDistance( lua_State* pLuaVM, PVOID pUserData, unsigned short usVisibleDistance )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usVisibleDistance );

	if( pLuaArguments.Call( pLuaVM, "setBlipVisibleDistance", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Object create/destroy functions

PVOID Bindings::CreateObject( lua_State* pLuaVM, unsigned short usModelID, const Math::Vector3& vecPosition, const Math::Vector3& vecRotation, bool bIsLowLod )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( vecRotation.fX );
	pLuaArguments.PushNumber( vecRotation.fY );
	pLuaArguments.PushNumber( vecRotation.fZ );

	pLuaArguments.PushBoolean( bIsLowLod );

	if( pLuaArguments.Call( pLuaVM, "createObject", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

// Object get functions

bool Bindings::GetObjectScale( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecScale )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getObjectScale", 3 ) )
	{
		vecScale.fX = static_cast< float >( LuaArgument( pLuaVM, -3 ).GetNumber() );
		vecScale.fY = static_cast< float >( LuaArgument( pLuaVM, -2 ).GetNumber() );
		vecScale.fZ = static_cast< float >( LuaArgument( pLuaVM, -1 ).GetNumber() );

		return true;
	}

	return false;
}

// Object set functions

bool Bindings::SetObjectScale( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& vecScale )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	pLuaArguments.PushNumber( vecScale.fX );
	pLuaArguments.PushNumber( vecScale.fY );
	pLuaArguments.PushNumber( vecScale.fZ );

	if( pLuaArguments.Call( pLuaVM, "setObjectScale", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::MoveObject( lua_State* pLuaVM, PVOID pUserData, unsigned long ulTime, const Math::Vector3& vecPosition, const Math::Vector3& vecRotation, const char* szEasingType, float fEasingPeriod, float fEasingAmplitude, float fEasingOvershoot )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ulTime );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( vecRotation.fX );
	pLuaArguments.PushNumber( vecRotation.fY );
	pLuaArguments.PushNumber( vecRotation.fZ );
	pLuaArguments.PushString( szEasingType );
	pLuaArguments.PushNumber( fEasingPeriod );
	pLuaArguments.PushNumber( fEasingAmplitude );
	pLuaArguments.PushNumber( fEasingOvershoot );

	if( pLuaArguments.Call( pLuaVM, "moveObject", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::StopObject( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "stopObject", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Radar area create/destroy funcs

PVOID Bindings::CreateRadarArea( lua_State* pLuaVM, const Math::Vector2& vecPosition, const Math::Vector2& vecSize, const SharedUtil::Color color, PVOID pVisibleTo )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );

	pLuaArguments.PushNumber( vecSize.fX );
	pLuaArguments.PushNumber( vecSize.fY );

	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );

	if( pVisibleTo )
	{
		pLuaArguments.PushUserData( pVisibleTo );
	}

	if( pLuaArguments.Call( pLuaVM, "createRadarArea", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

// Radar area get funcs

bool Bindings::GetRadarAreaSize( lua_State* pLuaVM, PVOID pUserData, Math::Vector2& vecSize )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getRadarAreaSize", 2 ) )
	{
		vecSize.fX = LuaArgument( pLuaVM, -2 ).GetNumber< float >();
		vecSize.fY = LuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

bool Bindings::GetRadarAreaColor( lua_State* pLuaVM, PVOID pUserData, SharedUtil::Color& outColor )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getRadarAreaColor", 4 ) )
	{
		outColor.R	= LuaArgument( pLuaVM, -4 ).GetNumber< unsigned char >();
		outColor.G	= LuaArgument( pLuaVM, -3 ).GetNumber< unsigned char >();
		outColor.B	= LuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		outColor.A	= LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::IsRadarAreaFlashing( lua_State* pLuaVM, PVOID pUserData )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isRadarAreaFlashing", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::IsInsideRadarArea( lua_State* pLuaVM, PVOID pUserData, const Math::Vector2& vecPosition, bool& bInside )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isInsideRadarArea", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Radar area set funcs

bool Bindings::SetRadarAreaSize( lua_State* pLuaVM, PVOID pUserData, const Math::Vector2& vecSize )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecSize.fX );
	pLuaArguments.PushNumber( vecSize.fY );

	if( pLuaArguments.Call( pLuaVM, "setRadarAreaSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetRadarAreaColor( lua_State* pLuaVM, PVOID pUserData, const SharedUtil::Color color )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );

	if( pLuaArguments.Call( pLuaVM, "setRadarAreaColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetRadarAreaFlashing( lua_State* pLuaVM, PVOID pUserData, bool bFlashing )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bFlashing );

	if( pLuaArguments.Call( pLuaVM, "setRadarAreaFlashing", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Pickup create/destroy funcs

PVOID Bindings::CreatePickup( lua_State* pLuaVM, const Math::Vector3& vecPosition, unsigned char ucType, double dFive, unsigned long ulRespawnInterval, double dSix )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( ucType );
	pLuaArguments.PushNumber( dFive );

	pLuaArguments.PushNumber( ulRespawnInterval );
	pLuaArguments.PushNumber( dSix );

	if( pLuaArguments.Call( pLuaVM, "createPickup", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

// Pickup get funcs

bool Bindings::GetPickupType( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucType )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPickupType", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		ucType = static_cast< unsigned char >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetPickupWeapon( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucWeapon )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPickupWeapon", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		ucWeapon = static_cast< unsigned char >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetPickupAmount( lua_State* pLuaVM, PVOID pUserData, float& fAmount )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPickupAmount", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fAmount = static_cast< float >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetPickupAmmo( lua_State* pLuaVM, PVOID pUserData, unsigned short& ucAmmo )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPickupAmmo", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		ucAmmo = static_cast< unsigned short >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetPickupRespawnInterval( lua_State* pLuaVM, PVOID pUserData, unsigned long& ulInterval )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPickupRespawnInterval", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		ulInterval = static_cast< unsigned long >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::IsPickupSpawned( lua_State* pLuaVM, PVOID pUserData, bool& bSpawned )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPickupSpawned", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bSpawned = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

// Pickup set funcs

bool Bindings::SetPickupType( lua_State* pLuaVM, PVOID pUserData, unsigned char ucType, double dThree, double dFour )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucType );
	pLuaArguments.PushNumber( dThree );
	pLuaArguments.PushNumber( dFour );

	if( pLuaArguments.Call( pLuaVM, "setPickupType", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPickupRespawnInterval( lua_State* pLuaVM, PVOID pUserData, unsigned long ulInterval )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ulInterval );

	if( pLuaArguments.Call( pLuaVM, "setPickupRespawnInterval", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::UsePickup( lua_State* pLuaVM, PVOID pUserData, PVOID pPlayer )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pPlayer );

	if( pLuaArguments.Call( pLuaVM, "usePickup", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Shape create funcs

PVOID Bindings::CreateColCircle( lua_State* pLuaVM, const Math::Vector2& vecPosition, float fRadius )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( fRadius );

	if( pLuaArguments.Call( pLuaVM, "createColCircle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::CreateColCuboid( lua_State* pLuaVM, const Math::Vector3& vecPosition, const Math::Vector3& vecSize )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( vecSize.fX );
	pLuaArguments.PushNumber( vecSize.fY );
	pLuaArguments.PushNumber( vecSize.fZ );

	if( pLuaArguments.Call( pLuaVM, "createColCuboid", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::CreateColSphere( lua_State* pLuaVM, const Math::Vector3& vecPosition, float fRadius )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( fRadius );

	if( pLuaArguments.Call( pLuaVM, "createColSphere", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::CreateColRectangle( lua_State* pLuaVM, const Math::Vector2& vecPosition, const Math::Vector2& vecSize )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );

	pLuaArguments.PushNumber( vecSize.fX );
	pLuaArguments.PushNumber( vecSize.fY );

	if( pLuaArguments.Call( pLuaVM, "createColRectangle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::CreateColPolygon( lua_State* pLuaVM, const vector< Math::Vector2 >& vecPointList )
{
	if( vecPointList.size() < 4 )
	{
		return nullptr;
	}

	LuaArguments pLuaArguments;

	for( unsigned int i = 0; i < vecPointList.size(); i++ )
    {
        pLuaArguments.PushNumber( vecPointList[ i ].fX );
        pLuaArguments.PushNumber( vecPointList[ i ].fY );
    }

	if( pLuaArguments.Call( pLuaVM, "createColRectangle", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::CreateColTube( lua_State* pLuaVM, const Math::Vector3& vecPosition, float fRadius, float fHeight )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( fRadius );
	pLuaArguments.PushNumber( fHeight );

	if( pLuaArguments.Call( pLuaVM, "createColTube", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

// Explosion funcs

bool Bindings::CreateExplosion( lua_State* pLuaVM, const Math::Vector3& vecPosition, unsigned char ucType, PVOID pCreator )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( ucType );

	if( pCreator )
	{
		pLuaArguments.PushUserData( pCreator );
	}

	if( pLuaArguments.Call( pLuaVM, "createExplosion", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Audio funcs

bool Bindings::PlaySoundFrontEnd( lua_State* pLuaVM, PVOID pElement, unsigned char ucSound )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushNumber( ucSound );

	if( pLuaArguments.Call( pLuaVM, "playSoundFrontEnd", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::PlayMissionAudio( lua_State* pLuaVM, PVOID pElement, Math::Vector3& vecPosition, unsigned short usSlot )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );

	pLuaArguments.PushNumber( usSlot );

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	if( pLuaArguments.Call( pLuaVM, "playMissionAudio", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Ped body?

bool Bindings::GetBodyPartName( lua_State* pLuaVM, unsigned char ucID, char* szName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucID );

	if( pLuaArguments.Call( pLuaVM, "getBodyPartName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		strncpy( szName, pLuaArgument.GetString(), strlen( pLuaArgument.GetString() ) );

		return true;
	}

	return false;
}

bool Bindings::GetClothesByTypeIndex( lua_State* pLuaVM, unsigned char ucType, unsigned char ucIndex, char* szTextureReturn, char* szModelReturn )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucType );
	pLuaArguments.PushNumber( ucIndex );

	if( pLuaArguments.Call( pLuaVM, "getClothesByTypeIndex", 2 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -2 );

		strncpy( szTextureReturn, pLuaArgument.GetString(), strlen( pLuaArgument.GetString() ) );

		LuaArgument pLuaArgument2( pLuaVM, -1 );

		strncpy( szModelReturn, pLuaArgument2.GetString(), strlen( pLuaArgument2.GetString() ) );

		return true;
	}

	return false;
}

bool Bindings::GetTypeIndexFromClothes( lua_State* pLuaVM, const char* szTexture, const char* szModel, unsigned char& ucTypeReturn, unsigned char& ucIndexReturn )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szTexture );
	pLuaArguments.PushString( szModel );

	if( pLuaArguments.Call( pLuaVM, "getTypeIndexFromClothes", 2 ) )
	{
		ucTypeReturn	= LuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		ucIndexReturn	= LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetClothesTypeName( lua_State* pLuaVM, unsigned char ucType, char* szNameReturn )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucType );

	if( pLuaArguments.Call( pLuaVM, "getClothesTypeName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		strncpy( szNameReturn, pLuaArgument.GetString(), strlen( pLuaArgument.GetString() ) );

		return true;
	}

	return false;
}

// Input funcs

bool Bindings::BindKey( lua_State* pLuaVM, PVOID pPlayer, const char* szKey, const char* szHitState, const char* szCommandName, const char* szArguments )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szKey );
	pLuaArguments.PushString( szHitState );
	pLuaArguments.PushString( szCommandName );

	if( szArguments )
	{
		pLuaArguments.PushString( szArguments );
	}

	if( pLuaArguments.Call( pLuaVM, "bindKey", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::UnbindKey( lua_State* pLuaVM, PVOID pPlayer, const char* szKey, const char* szHitState, const char* szCommandName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szKey );
	pLuaArguments.PushString( szHitState );
	pLuaArguments.PushString( szCommandName );

	if( pLuaArguments.Call( pLuaVM, "unbindKey", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GetControlState( lua_State* pLuaVM, PVOID pPlayer, const char* szControl, bool& bState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szControl );

	if( pLuaArguments.Call( pLuaVM, "getControlState", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bState = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::IsControlEnabled( lua_State* pLuaVM, PVOID pPlayer, const char* szControl, bool& bEnabled )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szControl );

	if( pLuaArguments.Call( pLuaVM, "isControlEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bEnabled = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::SetControlState( lua_State* pLuaVM, PVOID pPlayer, const char* szControl, bool bState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szControl );
	pLuaArguments.PushBoolean( bState );

	if( pLuaArguments.Call( pLuaVM, "setControlState", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ToggleControl( lua_State* pLuaVM, PVOID pPlayer, const char* szControl, bool bEnabled )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szControl );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "toggleControl", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ToggleAllControls( lua_State* pLuaVM, PVOID pPlayer, bool bGTAControls, bool bMTAControls, bool bEnabled )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushBoolean( bGTAControls );
	pLuaArguments.PushBoolean( bMTAControls );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "toggleAllControls", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Team get funcs

PVOID Bindings::CreateTeam( lua_State* pLuaVM, const char* szTeamName, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szTeamName );
	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	if( pLuaArguments.Call( pLuaVM, "createTeam", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::GetTeamFromName( lua_State* pLuaVM, const char* szTeamName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szTeamName );

	if( pLuaArguments.Call( pLuaVM, "getTeamFromName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetTeamName( lua_State* pLuaVM, PVOID pTeam, string& strOutName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );

	if( pLuaArguments.Call( pLuaVM, "getTeamName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		strOutName = pLuaArgument.GetString();

		return true;
	}

	return false;
}

bool Bindings::GetTeamColor( lua_State* pLuaVM, PVOID pTeam, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );

	if( pLuaArguments.Call( pLuaVM, "getTeamColor", 3 ) )
	{
		ucRed	= LuaArgument( pLuaVM, -3 ).GetNumber< unsigned char >();
		ucGreen	= LuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		ucBlue	= LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::CountPlayersInTeam( lua_State* pLuaVM, PVOID pTeam, unsigned int& uiCount )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );

	if( pLuaArguments.Call( pLuaVM, "countPlayersInTeam", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		uiCount = static_cast< unsigned int >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetTeamFriendlyFire( lua_State* pLuaVM, PVOID pTeam, bool& bFriendlyFire )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );

	if( pLuaArguments.Call( pLuaVM, "getTeamFriendlyFire", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bFriendlyFire = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

// Team set funcs

bool Bindings::SetTeamName( lua_State* pLuaVM, PVOID pTeam, const char* szTeamName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );
	pLuaArguments.PushString( szTeamName );

	if( pLuaArguments.Call( pLuaVM, "setTeamName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetTeamColor( lua_State* pLuaVM, PVOID pTeam, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );
	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	if( pLuaArguments.Call( pLuaVM, "setTeamColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPlayerTeam( lua_State* pLuaVM, PVOID pPlayer, PVOID pTeam )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushUserData( pTeam );

	if( pLuaArguments.Call( pLuaVM, "setPlayerTeam", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetTeamFriendlyFire( lua_State* pLuaVM, PVOID pTeam, bool bFriendlyFire )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );
	pLuaArguments.PushBoolean( bFriendlyFire );

	if( pLuaArguments.Call( pLuaVM, "setTeamFriendlyFire", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Water funcs

PVOID Bindings::CreateWater( lua_State* pLuaVM, Math::Vector3* pV1, Math::Vector3* pV2, Math::Vector3* pV3, Math::Vector3* pV4, bool bShallow )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( pV1->fX );
	pLuaArguments.PushNumber( pV1->fY );
	pLuaArguments.PushNumber( pV1->fZ );

	pLuaArguments.PushNumber( pV2->fX );
	pLuaArguments.PushNumber( pV2->fY );
	pLuaArguments.PushNumber( pV2->fZ );

	pLuaArguments.PushNumber( pV3->fX );
	pLuaArguments.PushNumber( pV3->fY );
	pLuaArguments.PushNumber( pV3->fZ );

	if( pV4 )
	{
		pLuaArguments.PushNumber( pV4->fX );
		pLuaArguments.PushNumber( pV4->fY );
		pLuaArguments.PushNumber( pV4->fZ );
	}

	pLuaArguments.PushBoolean( bShallow );

	if( pLuaArguments.Call( pLuaVM, "createWater", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::SetElementWaterLevel( lua_State* pLuaVM, PVOID pWater, float fLevel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pWater );
	pLuaArguments.PushNumber( fLevel );

	if( pLuaArguments.Call( pLuaVM, "setElementWaterLevel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetAllElementWaterLevel( lua_State* pLuaVM, float fLevel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fLevel );

	if( pLuaArguments.Call( pLuaVM, "setAllElementWaterLevel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetWorldWaterLevel( lua_State* pLuaVM, float fLevel, bool bIncludeWorldNonSeaLevel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fLevel );
	pLuaArguments.PushBoolean( bIncludeWorldNonSeaLevel );

	if( pLuaArguments.Call( pLuaVM, "setWorldWaterLevel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetWorldWaterLevel( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetWorldWaterLevel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GetWaterVertexPosition( lua_State* pLuaVM, PVOID pWater, int iVertexIndex, Math::Vector3& vecPosition )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pWater );
	pLuaArguments.PushNumber( iVertexIndex );

	if( pLuaArguments.Call( pLuaVM, "getWaterVertexPosition", 3 ) )
	{
		vecPosition.fX = LuaArgument( pLuaVM, -3 ).GetNumber< float >();
		vecPosition.fY = LuaArgument( pLuaVM, -2 ).GetNumber< float >();
		vecPosition.fZ = LuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

bool Bindings::SetWaterVertexPosition( lua_State* pLuaVM, PVOID pWater, int iVertexIndex, Math::Vector3& vecPosition )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pWater );
	pLuaArguments.PushNumber( iVertexIndex );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	if( pLuaArguments.Call( pLuaVM, "setWaterVertexPosition", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GetWaterColor( lua_State* pLuaVM, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue, unsigned char& ucAlpha )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getWaterColor", 4 ) )
	{
		ucRed	= LuaArgument( pLuaVM, -4 ).GetNumber< unsigned char >();
		ucGreen	= LuaArgument( pLuaVM, -3 ).GetNumber< unsigned char >();
		ucBlue	= LuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		ucAlpha	= LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::SetWaterColor( lua_State* pLuaVM, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue, unsigned char ucAlpha )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );
	pLuaArguments.PushNumber( ucAlpha );

	if( pLuaArguments.Call( pLuaVM, "setWaterColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetWaterColor( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetWaterColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Standard server functions
unsigned int Bindings::GetMaxPlayers( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getMaxPlayers", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetMaxPlayers( lua_State* pLuaVM, unsigned int uiMax )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( uiMax );

	if( pLuaArguments.Call( pLuaVM, "setMaxPlayers", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::OutputChatBox( lua_State* pLuaVM, const char* szText, PVOID pElement, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue, bool bColorCoded )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szText );

	if( pElement )
		pLuaArguments.PushUserData( pElement );
	else
		pLuaArguments.PushUserData( NULL );
	
	if( ucRed )
	{
		pLuaArguments.PushNumber( ucRed );
		pLuaArguments.PushNumber( ucGreen );
		pLuaArguments.PushNumber( ucBlue );

		pLuaArguments.PushNumber( bColorCoded );
	}

	if( pLuaArguments.Call( pLuaVM, "outputChatBox", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::OutputConsole( lua_State* pLuaVM, const char* szText, PVOID pElement )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szText );

	if( pElement )
	{
		pLuaArguments.PushUserData( pElement );
	}

	if( pLuaArguments.Call( pLuaVM, "outputConsole", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetServerPassword( lua_State* pLuaVM, const string& strPassword, bool bSave )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( strPassword.c_str() );
	pLuaArguments.PushBoolean( bSave );

	if( pLuaArguments.Call( pLuaVM, "setServerPassword", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// General world get funcs

bool Bindings::GetTime( lua_State* pLuaVM, unsigned char& ucHour, unsigned char& ucMinute )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getTime", 2 ) )
	{
		ucHour		= LuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		ucMinute	= LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetWeather( lua_State* pLuaVM, unsigned char& ucWeather, unsigned char& ucWeatherBlendingTo )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getWeather", 2 ) )
	{
		ucWeather			= LuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		ucWeatherBlendingTo	= LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetZoneName( lua_State* pLuaVM, Math::Vector3& vecPosition, string& strOutName, bool bCitiesOnly )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushBoolean( bCitiesOnly );

	if( pLuaArguments.Call( pLuaVM, "getZoneName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		strOutName = pLuaArgument.GetString();
		
		return true;
	}

	return false;
}

bool Bindings::GetGravity( lua_State* pLuaVM, float& fGravity )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getGravity", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fGravity = pLuaArgument.GetNumber< float >();
		
		return true;
	}

	return false;
}

bool Bindings::GetGameSpeed( lua_State* pLuaVM, float& fSpeed )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getGameSpeed", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fSpeed = pLuaArgument.GetNumber< float >();
		
		return true;
	}

	return false;
}

bool Bindings::GetWaveHeight( lua_State* pLuaVM, float& fHeight )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getWaveHeight", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fHeight = pLuaArgument.GetNumber< float >();
		
		return true;
	}

	return false;
}

bool Bindings::GetFPSLimit( lua_State* pLuaVM, unsigned short& usLimit )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getFPSLimit", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		usLimit = pLuaArgument.GetNumber< unsigned short >();
		
		return true;
	}

	return false;
}

bool Bindings::GetMinuteDuration( lua_State* pLuaVM, unsigned long& ulDuration )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getMinuteDuration", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		ulDuration = pLuaArgument.GetNumber< unsigned long >();
		
		return true;
	}

	return false;
}

bool Bindings::IsGarageOpen( lua_State* pLuaVM, unsigned char ucGarageID, bool& bIsOpen )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "isGarageOpen", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bIsOpen = pLuaArgument.GetBoolean();
		
		return true;
	}

	return false;
}

bool Bindings::GetTrafficLightState( lua_State* pLuaVM, unsigned char& ucState )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getTrafficLightState", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		ucState = pLuaArgument.GetNumber< unsigned char >();
		
		return true;
	}

	return false;
}

bool Bindings::GetTrafficLightsLocked( lua_State* pLuaVM, bool& bLocked )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getTrafficLightsLocked", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bLocked = pLuaArgument.GetBoolean();
		
		return true;
	}

	return false;
}

bool Bindings::GetJetpackMaxHeight( lua_State* pLuaVM, float& fMaxHeight )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getJetpackMaxHeight", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fMaxHeight = pLuaArgument.GetNumber< float >();
		
		return true;
	}

	return false;
}

bool Bindings::GetAircraftMaxVelocity( lua_State* pLuaVM, float& fVelocity )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getAircraftMaxVelocity", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fVelocity = pLuaArgument.GetNumber< float >();
		
		return true;
	}

	return false;
}

bool Bindings::GetInteriorSoundsEnabled( lua_State* pLuaVM, bool& bEnabled )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getInteriorSoundsEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bEnabled = pLuaArgument.GetBoolean();
		
		return true;
	}

	return false;
}

bool Bindings::GetRainLevel( lua_State* pLuaVM, float& fRainLevel )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getRainLevel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fRainLevel = pLuaArgument.GetNumber< float >();
		
		return true;
	}

	return false;
}

bool Bindings::GetSunSize( lua_State* pLuaVM, float& fSunSize )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getSunSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fSunSize = pLuaArgument.GetNumber< float >();
		
		return true;
	}

	return false;
}

bool Bindings::GetSunColor( lua_State* pLuaVM, unsigned char& ucCoreR, unsigned char& ucCoreG, unsigned char& ucCoreB, unsigned char& ucCoronaR, unsigned char& ucCoronaG, unsigned char& ucCoronaB )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getSunColor", 6 ) )
	{
		ucCoreR		= LuaArgument( pLuaVM, -6 ).GetNumber< unsigned char >();
		ucCoreG		= LuaArgument( pLuaVM, -5 ).GetNumber< unsigned char >();
		ucCoreB		= LuaArgument( pLuaVM, -4 ).GetNumber< unsigned char >();

		ucCoronaR	= LuaArgument( pLuaVM, -3 ).GetNumber< unsigned char >();
		ucCoronaG	= LuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		ucCoronaB	= LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::GetWindVelocity( lua_State* pLuaVM, float& fVelX, float& fVelY, float& fVelZ )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getWindVelocity", 3 ) )
	{
		fVelX	= LuaArgument( pLuaVM, -3 ).GetNumber< float >();
		fVelY	= LuaArgument( pLuaVM, -2 ).GetNumber< float >();
		fVelZ	= LuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

bool Bindings::GetFarClipDistance( lua_State* pLuaVM, float& fFarClip )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getFarClipDistance", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fFarClip = pLuaArgument.GetNumber< float >();
		
		return true;
	}

	return false;
}

bool Bindings::GetFogDistance( lua_State* pLuaVM, float& fFogDist )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getFogDistance", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fFogDist = pLuaArgument.GetNumber< float >();
		
		return true;
	}

	return false;
}

bool Bindings::GetAircraftMaxHeight( lua_State* pLuaVM, float& fMaxHeight )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getAircraftMaxHeight", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		fMaxHeight = pLuaArgument.GetNumber< float >();
		
		return true;
	}

	return false;
}

bool Bindings::GetOcclusionsEnabled( lua_State* pLuaVM, bool& bEnabled )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getOcclusionsEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bEnabled = pLuaArgument.GetBoolean();
		
		return true;
	}

	return false;
}

bool Bindings::GetMoonSize( lua_State* pLuaVM, int& iSize )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getMoonSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		iSize = pLuaArgument.GetNumber< int >();
		
		return true;
	}

	return false;
}

// General world set funcs

bool Bindings::SetTime( lua_State* pLuaVM, unsigned char ucHour, unsigned char ucMinute )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucHour );
	pLuaArguments.PushNumber( ucMinute );

	if( pLuaArguments.Call( pLuaVM, "setTime", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetWeather( lua_State* pLuaVM, unsigned char ucWeather )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucWeather );

	if( pLuaArguments.Call( pLuaVM, "setWeather", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetWeatherBlended( lua_State* pLuaVM, unsigned char ucWeather )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucWeather );

	if( pLuaArguments.Call( pLuaVM, "setWeatherBlended", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetGravity( lua_State* pLuaVM, float fGravity )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fGravity );

	if( pLuaArguments.Call( pLuaVM, "setGravity", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetGameSpeed( lua_State* pLuaVM, float fSpeed )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fSpeed );

	if( pLuaArguments.Call( pLuaVM, "setGameSpeed", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetWaveHeight( lua_State* pLuaVM, float fHeight )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fHeight );

	if( pLuaArguments.Call( pLuaVM, "setWaveHeight", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GetSkyGradient( lua_State* pLuaVM, unsigned char& ucTopRed, unsigned char& ucTopGreen, unsigned char& ucTopBlue, unsigned char& ucBottomRed, unsigned char& ucBottomGreen, unsigned char& ucBottomBlue )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getSkyGradient", 6 ) )
	{
		ucTopRed		= LuaArgument( pLuaVM, -6 ).GetNumber< unsigned char >();
		ucTopGreen		= LuaArgument( pLuaVM, -5 ).GetNumber< unsigned char >();
		ucTopBlue		= LuaArgument( pLuaVM, -4 ).GetNumber< unsigned char >();

		ucBottomRed		= LuaArgument( pLuaVM, -3 ).GetNumber< unsigned char >();
		ucBottomGreen	= LuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		ucBottomBlue	= LuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool Bindings::SetSkyGradient( lua_State* pLuaVM, unsigned char ucTopRed, unsigned char ucTopGreen, unsigned char ucTopBlue, unsigned char ucBottomRed, unsigned char ucBottomGreen, unsigned char ucBottomBlue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucTopRed );
	pLuaArguments.PushNumber( ucTopGreen );
	pLuaArguments.PushNumber( ucTopBlue );

	pLuaArguments.PushNumber( ucBottomRed );
	pLuaArguments.PushNumber( ucBottomGreen );
	pLuaArguments.PushNumber( ucBottomBlue );

	if( pLuaArguments.Call( pLuaVM, "setSkyGradient", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetSkyGradient( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetSkyGradient", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GetHeatHaze( lua_State* pLuaVM, SharedUtil::HeatHazeSettings& heatHazeSettings )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getHeatHaze", 9 ) )
	{
		heatHazeSettings.ucIntensity		= LuaArgument( pLuaVM, -9 ).GetNumber< unsigned char >();
		heatHazeSettings.ucRandomShift		= LuaArgument( pLuaVM, -8 ).GetNumber< unsigned char >();
		heatHazeSettings.usSpeedMin			= LuaArgument( pLuaVM, -7 ).GetNumber< unsigned short >();
		heatHazeSettings.usSpeedMax			= LuaArgument( pLuaVM, -6 ).GetNumber< unsigned short >();
		heatHazeSettings.sScanSizeX			= LuaArgument( pLuaVM, -5 ).GetNumber< short >();
		heatHazeSettings.sScanSizeY			= LuaArgument( pLuaVM, -4 ).GetNumber< short >();
		heatHazeSettings.usRenderSizeX		= LuaArgument( pLuaVM, -3 ).GetNumber< unsigned short >();
		heatHazeSettings.usRenderSizeY		= LuaArgument( pLuaVM, -2 ).GetNumber< unsigned short >();
		heatHazeSettings.bInsideBuilding	= LuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool Bindings::SetHeatHaze( lua_State* pLuaVM, const SharedUtil::HeatHazeSettings& heatHazeSettings )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( heatHazeSettings.ucIntensity );
	pLuaArguments.PushNumber( heatHazeSettings.ucRandomShift );
	pLuaArguments.PushNumber( heatHazeSettings.usSpeedMin );
	pLuaArguments.PushNumber( heatHazeSettings.usSpeedMax );
	pLuaArguments.PushNumber( heatHazeSettings.sScanSizeX );
	pLuaArguments.PushNumber( heatHazeSettings.sScanSizeY );
	pLuaArguments.PushNumber( heatHazeSettings.usRenderSizeX );
	pLuaArguments.PushNumber( heatHazeSettings.usRenderSizeY );
	pLuaArguments.PushBoolean( heatHazeSettings.bInsideBuilding );

	if( pLuaArguments.Call( pLuaVM, "setHeatHaze", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetHeatHaze( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetHeatHaze", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetFPSLimit( lua_State* pLuaVM, unsigned short usLimit, bool bSave )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usLimit );
	pLuaArguments.PushBoolean( bSave );

	if( pLuaArguments.Call( pLuaVM, "setFPSLimit", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetMinuteDuration( lua_State* pLuaVM, unsigned long ulDuration )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ulDuration );

	if( pLuaArguments.Call( pLuaVM, "setMinuteDuration", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetGarageOpen( lua_State* pLuaVM, unsigned char ucGarageID, bool bIsOpen )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucGarageID );
	pLuaArguments.PushBoolean( bIsOpen );

	if( pLuaArguments.Call( pLuaVM, "setGarageOpen", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetGlitchEnabled( lua_State* pLuaVM, const string& strGlitchName, bool bEnabled )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( strGlitchName.c_str() );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setGlitchEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::IsGlitchEnabled( lua_State* pLuaVM, const string& strGlitchName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( strGlitchName.c_str() );

	if( pLuaArguments.Call( pLuaVM, "isGlitchEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GetJetpackWeaponEnabled( lua_State* pLuaVM, SharedUtil::WeaponType weaponType )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( weaponType );

	if( pLuaArguments.Call( pLuaVM, "getJetpackWeaponEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetJetpackWeaponEnabled( lua_State* pLuaVM, SharedUtil::WeaponType weaponType, bool bEnabled )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( weaponType );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setJetpackWeaponEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetCloudsEnabled( lua_State* pLuaVM, bool bEnabled )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setCloudsEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GetCloudsEnabled( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getCloudsEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetTrafficLightState( lua_State* pLuaVM, unsigned char ucState, bool bForced )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucState );
	pLuaArguments.PushBoolean( bForced );

	if( pLuaArguments.Call( pLuaVM, "setTrafficLightState", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetTrafficLightsLocked( lua_State* pLuaVM, bool bLocked )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bLocked );

	if( pLuaArguments.Call( pLuaVM, "setTrafficLightsLocked", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetJetpackMaxHeight( lua_State* pLuaVM, float fMaxHeight )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fMaxHeight );

	if( pLuaArguments.Call( pLuaVM, "setJetpackMaxHeight", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetInteriorSoundsEnabled( lua_State* pLuaVM, bool bEnable )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bEnable );

	if( pLuaArguments.Call( pLuaVM, "setInteriorSoundsEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetRainLevel( lua_State* pLuaVM, float fRainLevel )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fRainLevel );

	if( pLuaArguments.Call( pLuaVM, "setRainLevel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetSunSize( lua_State* pLuaVM, float fSunSize )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fSunSize );

	if( pLuaArguments.Call( pLuaVM, "setSunSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetSunColor( lua_State* pLuaVM, unsigned char ucCoreR, unsigned char ucCoreG, unsigned char ucCoreB, unsigned char ucCoronaR, unsigned char ucCoronaG, unsigned char ucCoronaB )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucCoreR );
	pLuaArguments.PushNumber( ucCoreG );
	pLuaArguments.PushNumber( ucCoreB );

	pLuaArguments.PushNumber( ucCoronaR );
	pLuaArguments.PushNumber( ucCoronaG );
	pLuaArguments.PushNumber( ucCoronaB );

	if( pLuaArguments.Call( pLuaVM, "setSunColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetWindVelocity( lua_State* pLuaVM, float fVelX, float fVelY, float fVelZ )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fVelX );
	pLuaArguments.PushNumber( fVelY );
	pLuaArguments.PushNumber( fVelZ );

	if( pLuaArguments.Call( pLuaVM, "setWindVelocity", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetFarClipDistance( lua_State* pLuaVM, float fFarClip )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fFarClip );

	if( pLuaArguments.Call( pLuaVM, "setFarClipDistance", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetFogDistance( lua_State* pLuaVM, float fFogDist )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fFogDist );

	if( pLuaArguments.Call( pLuaVM, "setFogDistance", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetAircraftMaxHeight( lua_State* pLuaVM, float fMaxHeight )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fMaxHeight );

	if( pLuaArguments.Call( pLuaVM, "setAircraftMaxHeight", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetAircraftMaxVelocity( lua_State* pLuaVM, float fVelocity )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fVelocity );

	if( pLuaArguments.Call( pLuaVM, "setAircraftMaxVelocity", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetOcclusionsEnabled( lua_State* pLuaVM, bool bEnabled )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setOcclusionsEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetRainLevel( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetRainLevel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetSunSize( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetSunSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetSunColor( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetSunColor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetWindVelocity( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetWindVelocity", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetFarClipDistance( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetFarClipDistance", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetFogDistance( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetFogDistance", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RemoveWorldModel( lua_State* pLuaVM, unsigned short usModel, float fRadius, const Math::Vector3& vecPosition, char cInterior )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usModel );
	pLuaArguments.PushNumber( fRadius );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( cInterior );

	if( pLuaArguments.Call( pLuaVM, "removeWorldModel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RestoreWorldModel( lua_State* pLuaVM, unsigned short usModel, float fRadius, const Math::Vector3& vecPosition, char cInterior )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usModel );
	pLuaArguments.PushNumber( fRadius );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( cInterior );

	if( pLuaArguments.Call( pLuaVM, "restoreWorldModel", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RestoreAllWorldModels( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "restoreAllWorldModels", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SendSyncIntervals( lua_State* pLuaVM, PVOID pPlayer )
{
	LuaArguments pLuaArguments;

	if( pPlayer )
	{
		pLuaArguments.PushUserData( pPlayer );
	}

	if( pLuaArguments.Call( pLuaVM, "sendSyncIntervals", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetPedTargetingMarkerEnabled( lua_State* pLuaVM, bool bEnabled )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setPedTargetingMarkerEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::IsPedTargetingMarkerEnabled( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "isPedTargetingMarkerEnabled", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetMoonSize( lua_State* pLuaVM, int iMoonSize )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushNumber( iMoonSize );

	if( pLuaArguments.Call( pLuaVM, "setMoonSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::ResetMoonSize( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetMoonSize", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Loaded Map Functions

PVOID Bindings::GetRootElement( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getRootElement", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

//PVOID Bindings::LoadMapData( lua_State* pLuaVM, PVOID pParent, CXMLNode* pNode )
//PVOID Bindings::SaveMapData( lua_State* pLuaVM, PVOID pElement, CXMLNode* pNode, bool bChildren )
	
// Account get funcs

PVOID Bindings::GetAccount( lua_State* pLuaVM, const char* szName, const char* szPassword )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushString( szPassword );

	if( pLuaArguments.Call( pLuaVM, "getAccount", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

ArgumentsVector Bindings::GetAccounts( lua_State* pLuaVM )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getAccounts", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

PVOID Bindings::GetAccountPlayer( lua_State* pLuaVM, PVOID pAccount )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );

	if( pLuaArguments.Call( pLuaVM, "getAccountPlayer", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::IsGuestAccount( lua_State* pLuaVM, PVOID pAccount, bool& bGuest )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );

	if( pLuaArguments.Call( pLuaVM, "isGuestAccount", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		bGuest = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

LuaArgument Bindings::GetAccountData( lua_State* pLuaVM, PVOID pAccount, const char* szKey )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );
	pLuaArguments.PushString( szKey );

	if( pLuaArguments.Call( pLuaVM, "getAccountData", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument;
}

bool Bindings::GetAllAccountData( lua_State* pLuaVM, PVOID pAccount )
{
	return false;
}

bool Bindings::GetAccountSerial( lua_State* pLuaVM, PVOID pAccount, string& strSerial )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );

	if( pLuaArguments.Call( pLuaVM, "getAccountSerial", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strSerial = pLuaArgument.GetString();
			
			return true;
		}
	}

	return false;
}

ArgumentsVector Bindings::GetAccountsBySerial( lua_State* pLuaVM, const string& strSerial )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( strSerial.c_str() );

	if( pLuaArguments.Call( pLuaVM, "getAccountsBySerial", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

// Account set funcs

PVOID Bindings::AddAccount( lua_State* pLuaVM, const char* szName, const char* szPassword )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushString( szPassword );

	if( pLuaArguments.Call( pLuaVM, "addAccount", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::RemoveAccount( lua_State* pLuaVM, PVOID pAccount )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );

	if( pLuaArguments.Call( pLuaVM, "removeAccount", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetAccountPassword( lua_State* pLuaVM, PVOID pAccount, const char* szPassword )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );
	pLuaArguments.PushString( szPassword );

	if( pLuaArguments.Call( pLuaVM, "setAccountPassword", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetAccountData( lua_State* pLuaVM, PVOID pAccount, const char* szKey, LuaArgument* pArgument )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );
	pLuaArguments.PushString( szKey );
	pLuaArguments.PushArgument( pArgument );

	if( pLuaArguments.Call( pLuaVM, "setAccountData", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::CopyAccountData( lua_State* pLuaVM, PVOID pAccount, PVOID pFromAccount )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );
	pLuaArguments.PushUserData( pFromAccount );

	if( pLuaArguments.Call( pLuaVM, "copyAccountData", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Log in/out funcs

bool Bindings::LogIn( lua_State* pLuaVM, PVOID pPlayer, PVOID pAccount, const char* szPassword )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushUserData( pAccount );
	pLuaArguments.PushString( szPassword );

	if( pLuaArguments.Call( pLuaVM, "logIn", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::LogOut( lua_State* pLuaVM, PVOID pPlayer )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );

	if( pLuaArguments.Call( pLuaVM, "logOut", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Admin funcs

bool Bindings::KickPlayer( lua_State* pLuaVM, PVOID pPlayer, string strResponsible, string strReason )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( strResponsible.c_str() );
	pLuaArguments.PushString( strReason.c_str() );

	if( pLuaArguments.Call( pLuaVM, "kickPlayer", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

PVOID Bindings::BanPlayer( lua_State* pLuaVM, PVOID pPlayer, bool bIP, bool bUsername, bool bSerial, PVOID pResponsible, string strResponsible, string strReason, time_t tUnban )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushBoolean( bIP );
	pLuaArguments.PushBoolean( bUsername );
	pLuaArguments.PushBoolean( bSerial );

	if( pResponsible )
	{
		pLuaArguments.PushUserData( pResponsible );
		pLuaArguments.PushString( strResponsible.c_str() );
		pLuaArguments.PushString( strReason.c_str() );
		pLuaArguments.PushNumber( static_cast< double >( tUnban ) );
	}

	if( pLuaArguments.Call( pLuaVM, "banPlayer", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::AddBan( lua_State* pLuaVM, string strIP, string strUsername, string strSerial, PVOID pResponsible, string strReason, time_t tUnban )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( strIP.c_str() );
	pLuaArguments.PushString( strUsername.c_str() );
	pLuaArguments.PushString( strSerial.c_str() );

	if( pResponsible )
	{
		pLuaArguments.PushUserData( pResponsible );
	}
	else
	{
		pLuaArguments.PushNil();
	}

	pLuaArguments.PushString( strReason.c_str() );
	pLuaArguments.PushNumber( static_cast< double >( tUnban ) );

	if( pLuaArguments.Call( pLuaVM, "addBan", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::RemoveBan( lua_State* pLuaVM, PVOID pBan, PVOID pResponsible )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pResponsible )
	{
		pLuaArguments.PushUserData( pResponsible );
	}

	if( pLuaArguments.Call( pLuaVM, "removeBan", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

ArgumentsVector Bindings::GetBans( lua_State* pLuaVM )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getBans", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

bool Bindings::ReloadBanList( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "reloadBanList", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::GetBanIP( lua_State* pLuaVM, PVOID pBan, string& strOutIP )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanIP", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutIP = pLuaArgument.GetString();
			
			return true;
		}
	}

	return false;
}

bool Bindings::GetBanSerial( lua_State* pLuaVM, PVOID pBan, string& strOutSerial )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanSerial", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutSerial = pLuaArgument.GetString();

			return true;
		}
	}

	return false;
}

bool Bindings::GetBanUsername( lua_State* pLuaVM, PVOID pBan, string& strOutUsername )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanUsername", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutUsername = pLuaArgument.GetString();

			return true;
		}
	}

	return false;
}

bool Bindings::GetBanNick( lua_State* pLuaVM, PVOID pBan, string& strOutNick )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanNick", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutNick = pLuaArgument.GetString();

			return true;
		}
	}

	return false;
}

bool Bindings::GetBanReason( lua_State* pLuaVM, PVOID pBan, string& strOutReason )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanReason", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutReason = pLuaArgument.GetString();

			return true;
		}
	}

	return false;
}

bool Bindings::GetBanAdmin( lua_State* pLuaVM, PVOID pBan, string& strOutAdmin )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanAdmin", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strOutAdmin = pLuaArgument.GetString();

			return true;
		}
	}

	return false;
}

bool Bindings::GetBanTime( lua_State* pLuaVM, PVOID pBan, time_t& time )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanTime", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		time = static_cast< time_t >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::GetUnbanTime( lua_State* pLuaVM, PVOID pBan, time_t& time )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getUnbanTime", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		time = static_cast< time_t >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool Bindings::SetUnbanTime( lua_State* pLuaVM, PVOID pBan, time_t time )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );
	pLuaArguments.PushNumber( static_cast< double >( time ) );

	if( pLuaArguments.Call( pLuaVM, "setUnbanTime", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetBanReason( lua_State* pLuaVM, PVOID pBan, const string& strReason )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );
	pLuaArguments.PushString( strReason.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setBanReason", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetBanAdmin( lua_State* pLuaVM, PVOID pBan, const string& strAdminName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );
	pLuaArguments.PushString( strAdminName.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setBanAdmin", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Cursor get funcs

bool Bindings::IsCursorShowing( lua_State* pLuaVM, PVOID pPlayer, bool& bShowing )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );

	if( pLuaArguments.Call( pLuaVM, "isCursorShowing", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return bShowing = pLuaArgument.GetBoolean();
	}

	return false;
}

// Cursor set funcs

bool Bindings::ShowCursor( lua_State* pLuaVM, PVOID pElement, bool bShow, bool bToggleControls )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushBoolean( bShow );
	pLuaArguments.PushBoolean( bToggleControls );

	if( pLuaArguments.Call( pLuaVM, "showCursor", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Chat funcs

bool Bindings::ShowChat( lua_State* pLuaVM, PVOID pElement, bool bShow )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushBoolean( bShow );

	if( pLuaArguments.Call( pLuaVM, "showChat", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Misc funcs

bool Bindings::ResetMapInfo( lua_State* pLuaVM, PVOID pElement )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );

	if( pLuaArguments.Call( pLuaVM, "resetMapInfo", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Resource funcs

PVOID Bindings::CreateResource( lua_State* pLuaVM, const char* szResourceName, const char* szOrganizationalDir )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szResourceName );
	pLuaArguments.PushString( szOrganizationalDir );

	if( pLuaArguments.Call( pLuaVM, "createResource", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::CopyResource( lua_State* pLuaVM, PVOID pResource, const char* szNewResourceName, const char* szOrganizationalDir )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szNewResourceName );
	pLuaArguments.PushString( szOrganizationalDir );

	if( pLuaArguments.Call( pLuaVM, "copyResource", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::GetResourceRootElement( lua_State* pLuaVM, PVOID pResource )
{
	LuaArguments pLuaArguments;

	if( pResource )
	{
		pLuaArguments.PushUserData( pResource );
	}

	if( pLuaArguments.Call( pLuaVM, "getResourceRootElement", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::GetResourceMapRootElement( lua_State* pLuaVM, PVOID pResource, const char* szMap )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szMap );

	if( pLuaArguments.Call( pLuaVM, "getResourceMapRootElement", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

PVOID Bindings::GetResourceDynamicElementRoot( lua_State* pLuaVM, PVOID pResource )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceDynamicElementRoot", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::RemoveResourceFile( lua_State* pLuaVM, PVOID pResource, const char* szFilename )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szFilename );

	if( pLuaArguments.Call( pLuaVM, "removeResourceFile", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

ArgumentsVector Bindings::GetResourceExportedFunctions( lua_State* pLuaVM, PVOID pResource )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceExportedFunctions", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

PVOID Bindings::GetResourceFromName( lua_State* pLuaVM, const char* szResourceName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szResourceName );

	if( pLuaArguments.Call( pLuaVM, "getResourceFromName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetResourceInfo( lua_State* pLuaVM, PVOID pResource, const char* szAttribute, string& strInfo )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szAttribute );

	if( pLuaArguments.Call( pLuaVM, "getResourceInfo", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strInfo = pLuaArgument.GetString();
		}

		return true;
	}

	return false;
}

bool Bindings::GetResourceLastStartTime( lua_State* pLuaVM, PVOID pResource, unsigned int& uiTime )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceLastStartTime", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		uiTime = pLuaArgument.GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool Bindings::GetResourceLoadFailureReason( lua_State* pLuaVM, PVOID pResource, string& strReason )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceLoadFailureReason", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strReason = pLuaArgument.GetString();
		}

		return true;
	}

	return false;
}

bool Bindings::GetResourceLoadTime( lua_State* pLuaVM, PVOID pResource, unsigned int& uiTime )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceLoadTime", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		uiTime = pLuaArgument.GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool Bindings::GetResourceName( lua_State* pLuaVM, PVOID pResource, string& strName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceName", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strName = pLuaArgument.GetString();
		}

		return true;
	}

	return false;
}

ArgumentsVector Bindings::GetResources( lua_State* pLuaVM )
{
	LuaArgument pLuaArgument;
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getResources", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetArray();
}

bool Bindings::GetResourceState( lua_State* pLuaVM, PVOID pResource, string& strState )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceState", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::String )
		{
			strState = pLuaArgument.GetString();

			return true;
		}
	}

	return false;
}

PVOID Bindings::GetThisResource( lua_State* pLuaVM )
{
	LuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getThisResource", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::RefreshResources( lua_State* pLuaVM, bool refreshAll )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( refreshAll );

	if( pLuaArguments.Call( pLuaVM, "refreshResources", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RemoveResourceDefaultSetting( lua_State* pLuaVM, PVOID pResource, const char* szSettingName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szSettingName );

	if( pLuaArguments.Call( pLuaVM, "removeResourceDefaultSetting", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::StartResource( lua_State* pLuaVM, PVOID pResource, bool persistent, bool startIncludedResources, bool loadServerConfigs, bool loadMaps, bool loadServerScripts, bool loadHTML, bool loadClientConfigs, bool loadClientScripts, bool loadFiles )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushBoolean( persistent );
	pLuaArguments.PushBoolean( startIncludedResources );
	pLuaArguments.PushBoolean( loadServerConfigs );
	pLuaArguments.PushBoolean( loadMaps );
	pLuaArguments.PushBoolean( loadServerScripts );
	pLuaArguments.PushBoolean( loadHTML );
	pLuaArguments.PushBoolean( loadClientConfigs );
	pLuaArguments.PushBoolean( loadClientScripts );
	pLuaArguments.PushBoolean( loadFiles );

	if( pLuaArguments.Call( pLuaVM, "startResource", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RestartResource( lua_State* pLuaVM, PVOID pResource )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "restartResource", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::StopResource( lua_State* pLuaVM, PVOID pResource )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "stopResource", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetResourceDefaultSetting( lua_State* pLuaVM, PVOID pResource, const char* szSettingName, const char* szSettingValue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szSettingName );
	pLuaArguments.PushString( szSettingValue );

	if( pLuaArguments.Call( pLuaVM, "setResourceDefaultSetting", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetResourceDefaultSetting( lua_State* pLuaVM, PVOID pResource, const char* szSettingName, int iSettingValue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szSettingName );
	pLuaArguments.PushNumber( iSettingValue );

	if( pLuaArguments.Call( pLuaVM, "setResourceDefaultSetting", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetResourceDefaultSetting( lua_State* pLuaVM, PVOID pResource, const char* szSettingName, float fSettingValue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szSettingName );
	pLuaArguments.PushNumber( fSettingValue );

	if( pLuaArguments.Call( pLuaVM, "setResourceDefaultSetting", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::SetResourceInfo( lua_State* pLuaVM, PVOID pResource, const char* szAttribute, const char* szValue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szAttribute );
	pLuaArguments.PushString( szValue );

	if( pLuaArguments.Call( pLuaVM, "setResourceInfo", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::RenameResource( lua_State* pLuaVM, const char* szResourceName, const char* szNewResourceName, const char* szOrganizationalPath )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szResourceName );
	pLuaArguments.PushString( szNewResourceName );
	pLuaArguments.PushString( szOrganizationalPath );

	if( pLuaArguments.Call( pLuaVM, "renameResource", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::DeleteResource( lua_State* pLuaVM, const char* szResourceName )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushString( szResourceName );

	if( pLuaArguments.Call( pLuaVM, "deleteResource", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool Bindings::UpdateResourceACLRequest( lua_State* pLuaVM, PVOID pResource, const char* szRightName, bool bAccess, const char* szByWho )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szRightName );
	pLuaArguments.PushBoolean( bAccess );
	pLuaArguments.PushString( szByWho );

	if( pLuaArguments.Call( pLuaVM, "updateResourceACLRequest", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Version funcs

ArgumentsMap Bindings::GetVersion( lua_State* pLuaVM )
{
	LuaArgument pLuaArgument;

	if( LuaArguments().Call( pLuaVM, "getVersion", 1 ) )
	{
		pLuaArgument.Read( pLuaVM, -1 );
	}

	return pLuaArgument.GetTable();
}

// Camera get functions
bool Bindings::GetCameraMatrix( lua_State* pLuaVM, PVOID pPlayer, Math::Vector3& vecPosition, Math::Vector3& vecLookAt, float& fRoll, float& fFOV )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	
	int iArgumentsCount = 8;

	if( pLuaArguments.Call( pLuaVM, "getCameraMatrix", iArgumentsCount ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}

		LuaArguments pLuaArgs;

		pLuaArgs.ReadArguments( pLuaVM );

		uint i = 0;

		for( const auto& iter : pLuaArgs.GetArguments() )
		{
			if( iter->GetType() != LuaType::Number )
			{
				return false;
			}

			float fValue = iter->GetNumber< float >();

			switch( i )
			{
				case 0: vecPosition.fX  = fValue; break;
				case 1: vecPosition.fY  = fValue; break;
				case 2: vecPosition.fZ  = fValue; break;

				case 3: vecLookAt.fX    = fValue; break;
				case 4: vecLookAt.fY    = fValue; break;
				case 5: vecLookAt.fZ    = fValue; break;

				case 6: fRoll           = fValue; break;
				case 7: fFOV            = fValue; break;
			}

			i++;
		}

		return true;
	}

	return false;
}

PVOID Bindings::GetCameraTarget( lua_State* pLuaVM, PVOID pPlayer )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	
	if( pLuaArguments.Call( pLuaVM, "getCameraTarget", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::LightUserdata )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return nullptr;
}

bool Bindings::GetCameraInterior( lua_State* pLuaVM, PVOID pPlayer, unsigned char& ucInterior )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	
	if( pLuaArguments.Call( pLuaVM, "getCameraInterior", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Number )
		{
			ucInterior = pLuaArgument.GetNumber< unsigned char >();

			return true;
		}
	}

	return false;
}

// Camera set functions

bool Bindings::SetCameraMatrix( lua_State* pLuaVM, PVOID pElement, const Math::Vector3& vecPosition, Math::Vector3& pvecLookAt, float fRoll, float fFOV )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( pvecLookAt.fX );
	pLuaArguments.PushNumber( pvecLookAt.fY );
	pLuaArguments.PushNumber( pvecLookAt.fZ );

	pLuaArguments.PushNumber( fRoll );
	pLuaArguments.PushNumber( fFOV );
	
	if( pLuaArguments.Call( pLuaVM, "setCameraMatrix", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::SetCameraTarget( lua_State* pLuaVM, PVOID pElement, PVOID pTarget )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushUserData( pTarget );

	if( pLuaArguments.Call( pLuaVM, "setCameraTarget", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::SetCameraInterior( lua_State* pLuaVM, PVOID pElement, unsigned char ucInterior )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushNumber( ucInterior );

	if( pLuaArguments.Call( pLuaVM, "setCameraInterior", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool Bindings::FadeCamera( lua_State* pLuaVM, PVOID pElement, bool bFadeIn, float fFadeTime, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushBoolean( bFadeIn );
	pLuaArguments.PushNumber( fFadeTime );
	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	if( pLuaArguments.Call( pLuaVM, "fadeCamera", 1 ) )
	{
		LuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LuaType::Boolean )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

// Weapon give/take functions

bool Bindings::GiveWeapon( lua_State* pLuaVM, PVOID pElement, unsigned char ucWeaponID, unsigned short usAmmo, bool bSetAsCurrent )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushNumber( usAmmo );
	pLuaArguments.PushBoolean( bSetAsCurrent );

	if( pLuaArguments.Call( pLuaVM, "giveWeapon", 1 ) )
	{
		return LuaArgument( pLuaVM, -1 ).GetBoolean();
	}

	return false;
}

bool Bindings::TakeWeapon( lua_State* pLuaVM, PVOID pElement, unsigned char ucWeaponID, unsigned short usAmmo )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushNumber( usAmmo );

	if( pLuaArguments.Call( pLuaVM, "takeWeapon", 1 ) )
	{
		return LuaArgument( pLuaVM, -1 ).GetBoolean();
	}

	return false;
}

bool Bindings::TakeAllWeapons( lua_State* pLuaVM, PVOID pElement )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );

	if( pLuaArguments.Call( pLuaVM, "takeAllWeapons", 1 ) )
	{
		return LuaArgument( pLuaVM, -1 ).GetBoolean();
	}

	return false;
}

bool Bindings::SetWeaponAmmo( lua_State* pLuaVM, PVOID pElement, unsigned char ucWeaponID, unsigned short usAmmo, unsigned short usAmmoInClip )
{
	LuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushNumber( usAmmo );
	pLuaArguments.PushNumber( usAmmoInClip );

	if( pLuaArguments.Call( pLuaVM, "setWeaponAmmo", 1 ) )
	{
		return LuaArgument( pLuaVM, -1 ).GetBoolean();
	}

	return false;
}
