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

class LuaArguments;

#ifndef __LUAARGUMENTS_H
#define __LUAARGUMENTS_H

#include <vector>
#include "LuaArgument.h"

using namespace std;

class LuaArguments
{
public:
	inline                                              LuaArguments        ()                {};
														LuaArguments        ( const LuaArguments& arguments );
	inline                                              ~LuaArguments       ()                { DeleteArguments (); };

	const LuaArguments&                                 operator =          ( const LuaArguments& arguments );

	void                                                ReadArguments       ( lua_State* luaVM, unsigned int uiIndexBegin = 1 );
	void                                                PushArguments       ( lua_State* luaVM ) const;
	void                                                PushArguments       ( LuaArguments& Arguments );
	bool                                                Call                ( lua_State* luaVM, const char* szFunction, int iResults = 0, int iErrorFunc = 0 ) const;

	LuaArgument*                                        PushNil             ( void );
	LuaArgument*                                        PushBoolean         ( bool bBool );
	LuaArgument*                                        PushNumber          ( double dNumber );
	LuaArgument*                                        PushString          ( const char* szString );
	LuaArgument*                                        PushUserData        ( void* userData );
	LuaArgument*                                        PushFunction        ( lua_CFunction iFunction );
	LuaArgument*                                        PushArgument        ( const LuaArgument& argument );

	void                                                DeleteArguments     ( void );

	inline vector < LuaArgument* >                      GetArguments        ()                { return m_Arguments; }
	inline unsigned int                                 Count               () const          { return static_cast < unsigned int > ( m_Arguments.size () ); };
	inline vector < LuaArgument* >  ::const_iterator    IterBegin           ()                { return m_Arguments.begin (); };
	inline vector < LuaArgument* >  ::const_iterator    IterEnd             ()                { return m_Arguments.end (); };

private:
	vector < LuaArgument* >                             m_Arguments;
};

#endif
