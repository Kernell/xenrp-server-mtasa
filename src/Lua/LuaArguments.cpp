/*********************************************************
*
*  Multi Theft Auto: San Andreas - Deathmatch
*
*  External lua add-on module
*
*  Copyright © 2003-2008 MTA.  All Rights Reserved.
*
*  Grand Theft Auto is © 2002-2003 Rockstar North
*
*  THE FOLLOWING SOURCES ARE PART OF THE MULTI THEFT
*  AUTO SOFTWARE DEVELOPMENT KIT AND ARE RELEASED AS
*  OPEN SOURCE FILES. THESE FILES MAY BE USED AS LONG
*  AS THE DEVELOPER AGREES TO THE LICENSE THAT IS
*  PROVIDED WITH THIS PACKAGE.
*
*********************************************************/

#include "StdInc.h"
#include "LuaArguments.h"

LuaArguments::LuaArguments( const LuaArguments& arguments )
{
	for( const auto& iter : arguments.m_Arguments )
	{
		LuaArgument* pArgument = new LuaArgument( *iter );

		this->m_Arguments.push_back( pArgument );
	}
}

const LuaArguments& LuaArguments::operator = ( const LuaArguments& arguments )
{
	this->DeleteArguments();

	for( const auto& iter : arguments.m_Arguments )
	{
		LuaArgument* pArgument = new LuaArgument( *iter );

		this->m_Arguments.push_back( pArgument );
	}

	return arguments;
}

void LuaArguments::ReadArguments( lua_State* luaVM, unsigned int uiIndexBegin )
{
	this->DeleteArguments();

	while( lua_type( luaVM, uiIndexBegin ) != LUA_TNONE )
	{
		LuaArgument* pArgument = new LuaArgument( luaVM, uiIndexBegin++ );

		this->m_Arguments.push_back( pArgument );
	}
}

void LuaArguments::PushArguments( lua_State* luaVM ) const
{
	for( const auto& pArg : this->m_Arguments )
	{
		pArg->Push( luaVM );
	}
}

void LuaArguments::PushArguments( LuaArguments& Arguments )
{
	for( const auto& iter : Arguments.m_Arguments )
	{
		LuaArgument* pArgument = new LuaArgument( *iter );

		this->m_Arguments.push_back( pArgument );
	}
}

bool LuaArguments::Call( lua_State* luaVM, const char* szFunction, int iResults, int iErrorFunc ) const
{
	ASSERT( szFunction );
	ASSERT( luaVM );

	lua_pushstring( luaVM, szFunction );
	lua_gettable( luaVM, LUA_GLOBALSINDEX );

	this->PushArguments( luaVM );

	int iret = lua_pcall( luaVM, this->m_Arguments.size(), iResults, iErrorFunc );

	return iret != LUA_ERRRUN && iret != LUA_ERRMEM;
}

LuaArgument* LuaArguments::PushNil( void )
{
	LuaArgument* pArgument = new LuaArgument;

	this->m_Arguments.push_back( pArgument );

	return pArgument;
}

LuaArgument* LuaArguments::PushBoolean( bool bBool )
{
	LuaArgument* pArgument = new LuaArgument( bBool );

	this->m_Arguments.push_back( pArgument );

	return pArgument;
}

LuaArgument* LuaArguments::PushNumber( double dNumber )
{
	LuaArgument* pArgument = new LuaArgument( dNumber );
	
	this->m_Arguments.push_back( pArgument );

	return pArgument;
}

LuaArgument* LuaArguments::PushString( const char* szString )
{
	LuaArgument* pArgument = new LuaArgument( szString );
	
	this->m_Arguments.push_back( pArgument );
	
	return pArgument;
}

LuaArgument* LuaArguments::PushUserData( void* pUserData )
{
	LuaArgument* pArgument = new LuaArgument( pUserData );
	
	this->m_Arguments.push_back( pArgument );
	
	return pArgument;
}

LuaArgument* LuaArguments::PushFunction( lua_CFunction iFunction )
{
	LuaArgument* pArgument = new LuaArgument( iFunction );

	this->m_Arguments.push_back( pArgument );

	return pArgument;
}

LuaArgument* LuaArguments::PushArgument( const LuaArgument& argument )
{
	LuaArgument* pArgument = new LuaArgument( argument ); // create a copy
	
	this->m_Arguments.push_back( pArgument );
	
	return pArgument;
}

void LuaArguments::DeleteArguments( void )
{
	for( auto pArg : this->m_Arguments )
	{
		delete pArg;
	}

	this->m_Arguments.clear();
}