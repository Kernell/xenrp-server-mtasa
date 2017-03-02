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
#include "LuaArgument.h"
#include <assert.h>
#include <cstring>

using namespace std;

LuaArgument::LuaArgument()
{
	this->m_iType             = LuaType::Nil;
	this->m_szString          = nullptr;
	this->m_pLightUserData    = nullptr;
	this->m_Function          = nullptr;
	this->m_bBoolean          = false;
	this->m_Number            = 0;
}

LuaArgument::LuaArgument( bool bBool ) : LuaArgument()
{
	this->m_iType    = LuaType::Boolean;
	this->m_bBoolean = bBool;
}

LuaArgument::LuaArgument( double dNumber ) : LuaArgument()
{
	this->m_iType  = LuaType::Number;
	this->m_Number = dNumber;
}

LuaArgument::LuaArgument( const char* szString ) : LuaArgument()
{
	assert( szString );

	this->m_iType    = LuaType::String;
	this->m_szString = new char[ strlen( szString ) + 1 ];

	strcpy( this->m_szString, szString );
}

LuaArgument::LuaArgument( void* pUserData ) : LuaArgument()
{
	this->m_iType          = LuaType::LightUserdata;
	this->m_pLightUserData = pUserData;
}

LuaArgument::LuaArgument( lua_CFunction Function ) : LuaArgument()
{
	this->m_szString = NULL;
	this->m_iType    = LuaType::Function;
	this->m_Function = Function;
}

LuaArgument::LuaArgument( const LuaArgument& Argument ) : LuaArgument()
{
	operator = ( Argument );
}

LuaArgument::LuaArgument( lua_State* luaVM, unsigned int uiArgument ) : LuaArgument()
{
	this->Read( luaVM, uiArgument );
}

LuaArgument::~LuaArgument( void )
{
	if( this->m_szString )
	{
		delete[] this->m_szString;
	}

	this->m_pArray.clear();
	this->m_pTable.clear();
}

const LuaArgument& LuaArgument::operator = ( const LuaArgument& argument )
{
	if( this->m_szString )
	{
		delete[] this->m_szString;
		this->m_szString = nullptr;
	}

	this->m_pArray.clear();
	this->m_pTable.clear();

	this->m_iType = argument.m_iType;

	switch( this->m_iType )
	{
		case LuaType::Boolean:
		{
			this->m_bBoolean = argument.m_bBoolean;

			break;
		}
		case LuaType::LightUserdata:
		{
			this->m_pLightUserData = argument.m_pLightUserData;

			break;
		}
		case LuaType::Number:
		{
			this->m_Number = argument.m_Number;

			break;
		}
		case LuaType::String:
		{
			if( argument.m_szString )
			{
				this->m_szString = new char[ strlen( argument.m_szString ) + 1 ];

				strcpy( this->m_szString, argument.m_szString );
			}

			break;
		}
		case LuaType::Function:
		{
			this->m_Function = argument.m_Function;

			break;
		}
		case LuaType::Table:
		{
			if( argument.m_pArray.size() > 0 )
			{
				for( const auto& _item : argument.m_pArray )
				{
					LuaArgument* item = new LuaArgument( _item );

					this->m_pArray.push_back( item );
				}
			}

			if( argument.m_pTable.size() > 0 )
			{
				for( const auto& iter : argument.m_pTable )
				{
					this->m_pTable[ iter.first ] = iter.second;
				}
			}

			break;
		}

		default: break;
	}

	return argument;
}

bool LuaArgument::operator == ( const LuaArgument& argument )
{
	if( argument.m_iType != this->m_iType )
	{
		return false;
	}

	switch( this->m_iType )
	{
		case LuaType::Boolean:
		{
			return this->m_bBoolean == argument.m_bBoolean;
		}
		case LuaType::LightUserdata:
		{
			return this->m_pLightUserData == argument.m_pLightUserData;
		}
		case LuaType::Number:
		{
			return this->m_Number == argument.m_Number;
		}
		case LuaType::String:
		{
			if( this->m_szString )
			{
				if( argument.m_szString )
				{
					return strcmp( this->m_szString, argument.m_szString ) == 0;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return argument.m_szString == NULL;
			}
		}
		case LuaType::Function:
		{
			return this->m_Function == argument.m_Function;
		}
	}

	return true;
}

bool LuaArgument::operator != ( const LuaArgument& argument )
{
	return !( operator == ( argument ) );
}

void LuaArgument::Read( lua_State* luaVM, signed int uiArgument )
{
	if( this->m_szString )
	{
		delete [] this->m_szString;
	}

	this->m_szString          = nullptr;
	this->m_pLightUserData    = nullptr;
	this->m_Function          = nullptr;

	this->m_pArray.clear();
	this->m_pTable.clear();

	this->m_iType = static_cast< LuaType >( lua_type( luaVM, uiArgument ) );

	if( this->m_iType != LuaType::None )
	{
		switch( this->m_iType )
		{
			case LuaType::Nil:
			{
				break;
			}
			case LuaType::Boolean:
			{
				this->m_bBoolean = lua_toboolean( luaVM, uiArgument ) != 0;

				break;
			}
			case LuaType::LightUserdata:
			{
				this->m_pLightUserData = lua_touserdata( luaVM, uiArgument );

				break;
			}
			case LuaType::Number:
			{
				this->m_Number = lua_tonumber( luaVM, uiArgument );

				break;
			}
			case LuaType::String:
			{
				const char* szLuaString = lua_tostring( luaVM, uiArgument );

				this->m_szString = new char[ strlen( szLuaString ) + 1 ];

				strcpy( this->m_szString, szLuaString );

				break;
			}
			case LuaType::Function:
			{
				this->m_Function = lua_tocfunction( luaVM, uiArgument );

				break;
			}
			case LuaType::Table:
			{
				lua_pushnil( luaVM );

				--uiArgument;

				while( lua_next( luaVM, uiArgument ) != 0 )
				{
					LuaArgument pKey( luaVM, -2 );
					LuaArgument pValue( luaVM, -1 );

					if( pKey.GetType() == LuaType::String )
					{
						this->m_pTable[ pKey.GetString() ] = pValue;
					}

					this->m_pArray.push_back( pValue );

					lua_pop( luaVM, 1 );
				}

				break;
			}
			default:
			{
				this->m_iType = LuaType::None;

				break;
			}
		}
	}
}

void LuaArgument::Push( lua_State* luaVM ) const
{
	if( this->m_iType != LuaType::None )
	{
		switch( this->m_iType )
		{
			case LuaType::Nil:
			{
				lua_pushnil( luaVM );

				break;
			}
			case LuaType::Boolean:
			{
				lua_pushboolean( luaVM, this->m_bBoolean );
				break;
			}
			case LuaType::LightUserdata:
			{
				lua_pushlightuserdata( luaVM, this->m_pLightUserData );

				break;
			}
			case LuaType::Number:
			{
				lua_pushnumber( luaVM, this->m_Number );

				break;
			}
			case LuaType::String:
			{
				lua_pushstring( luaVM, this->m_szString ? this->m_szString : "" );

				break;
			}
			case LuaType::Function:
			{
				lua_pushcfunction( luaVM, this->m_Function );

				break;
			}
		}
	}
}

ArgumentsVector LuaArgument::GetArray() const
{
	ArgumentsVector pArray;

	for( const auto& arg : this->m_pArray )
	{
		LuaArgument argument( arg );

		pArray.push_back( argument );
	}

	return pArray;
}

ArgumentsMap LuaArgument::GetTable() const
{
	ArgumentsMap pMap;

	for( const auto& iter : this->m_pTable )
	{
		LuaArgument argument( iter.second );

		pMap[ iter.first.c_str() ] = argument;
	}

	return pMap;
}
