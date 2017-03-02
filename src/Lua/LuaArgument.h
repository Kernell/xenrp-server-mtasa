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

extern "C"
{
    #include <lua.h>
}

class LuaArgument;

#ifndef __LUAARGUMENT_H
#define __LUAARGUMENT_H

#include "LuaArguments.h"

typedef vector< LuaArgument >       ArgumentsVector;
typedef list< LuaArgument >         ArgumentsList;
typedef map< string, LuaArgument >  ArgumentsMap;

enum class LuaType
{
	None			= LUA_TNONE,
	
	Nil				= LUA_TNIL,
	Boolean			= LUA_TBOOLEAN,
	LightUserdata	= LUA_TLIGHTUSERDATA,
	Number			= LUA_TNUMBER,
	String			= LUA_TSTRING,
	Table			= LUA_TTABLE,
	Function		= LUA_TFUNCTION,
	Userdata		= LUA_TUSERDATA,
	Thread			= LUA_TTHREAD,
};

class LuaArgument
{
public:
								LuaArgument         ();
								LuaArgument         ( bool bBool );
								LuaArgument         ( double dNumber );
								LuaArgument         ( const char* szString );
								LuaArgument         ( void* pUserData );
								LuaArgument         ( lua_CFunction Function );
								LuaArgument         ( const LuaArgument& Argument );
								LuaArgument         ( lua_State* luaVM, unsigned int uiArgument );
								~LuaArgument        ();

	const LuaArgument&          operator =          ( const LuaArgument& argument );
	bool                        operator ==         ( const LuaArgument& argument );
	bool                        operator !=         ( const LuaArgument& argument );

	void                        Read                ( lua_State* luaVM, signed int uiArgument );
	void                        Push                ( lua_State* luaVM ) const;

	inline LuaType              GetType             () const      { return m_iType; };

	inline bool                 GetBoolean          () const      { return m_bBoolean; };
	inline lua_Number           GetNumber           () const      { return m_Number; };
	inline const char*          GetString           () const      { return m_szString; };
	inline PVOID                GetLightUserData    () const      { return m_pLightUserData; };

	ArgumentsVector             GetArray            () const;
	ArgumentsMap                GetTable            () const;

	template< class Type >
	inline Type					GetNumber			()
	{
		return static_cast< Type >( m_Number );
	}

private:
	LuaType                     m_iType;
	bool                        m_bBoolean;
	lua_Number                  m_Number;
	char*                       m_szString;
	PVOID                       m_pLightUserData;
	lua_CFunction               m_Function;
	ArgumentsVector             m_pArray;
	ArgumentsMap                m_pTable;
};

#endif
