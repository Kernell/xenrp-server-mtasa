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

class Resource;

#ifndef __RESOURCE_H
#define __RESOURCE_H

#include "Element.h"

enum class ResourceState
{
	UNKNOWN,
	LOADED,
	RUNNING,
	STARTING,
	STOPPING,
	FAILED_TO_LOAD,
};

enum class ResourceParams
{
	PERSISTENT               = 1 << 0,
	START_INCLUDED_RESOURCES = 1 << 1,
	LOAD_SERVER_CONFIGS      = 1 << 2,
	LOAD_MAPS                = 1 << 3,
	LOAD_SERVER_SCRIPTS      = 1 << 4,
	LOAD_HTML                = 1 << 5,
	LOAD_CLIENT_CONFIGS      = 1 << 6,
	LOAD_CLIENT_SCRIPTS      = 1 << 7,
	LOAD_FILES               = 1 << 8,

	DEFAULT = START_INCLUDED_RESOURCES | LOAD_SERVER_CONFIGS | LOAD_MAPS | LOAD_SERVER_SCRIPTS | LOAD_HTML | LOAD_CLIENT_CONFIGS | LOAD_CLIENT_SCRIPTS | LOAD_FILES,
};

inline ResourceParams operator|( ResourceParams a, ResourceParams b )
{
	return static_cast< ResourceParams >( static_cast< int >( a ) | static_cast< int >( b ) );
}

inline bool operator&( ResourceParams a, ResourceParams b )
{
	return static_cast< ResourceParams >( static_cast< int >( a ) & static_cast< int >( b ) ) == b;
}

class Resource : public Element
{
public:
	                                Resource                        ( PVOID luaUserdata );
	                                Resource                        ( const string& resourceName, const char* organizationalDir = nullptr );
	virtual                         ~Resource                       ();
	virtual void                    Destroy                         () override;

	virtual Resource*               Copy                            ( const string& newResourceName, const char* organizationalDir = nullptr ) const;
	virtual Element*                GetRoot                         () const;
	virtual Element*                GetMapRoot                      ( const string& map ) const;
	virtual Element*                GetDynamicRoot                  () const;
	virtual ArgumentsVector         GetExportedFunctions	        () const;
	virtual string                  GetInfo                         ( const string& attribute ) const;
	virtual uint                    GetLastStartTime                () const;
	virtual string                  GetLoadFailureReason            () const;
	virtual uint                    GetLoadTime                     () const;
	virtual string                  GetName                         () const;
	virtual ResourceState           GetState                        () const;

	virtual bool                    RemoveFile				        ( const string& filename );
	virtual bool                    RemoveDefaultSetting            ( const string& settingName );
	virtual bool                    Start                           ( ResourceParams params = ResourceParams::DEFAULT );
	virtual bool                    Restart                         ();
	virtual bool                    Stop                            ();
	virtual bool                    SetDefaultSetting               ( const string& settingName, const string& settingValue );
	virtual bool                    SetDefaultSetting               ( const string& settingName, int settingValue );
	virtual bool                    SetDefaultSetting               ( const string& settingName, float settingValue );
	virtual bool                    SetInfo                         ( const string& attribute, const string& value );
///	virtual CLuaArguments*          GetACLRequests                  () const;
	virtual bool                    UpdateACLRequest                ( const string& rightName, bool access, const char* byWho = nullptr );

	static bool                     Refresh                         ( bool refreshAll = false );
	static bool                     Delete                          ( const string& resourceName );
	static bool                     Rename                          ( const string& resourceName, const string& newResourceName, const char* organizationalDir = nullptr );
	static Resource*                GetFromName                     ( const string& resourceName );
	static vector< Resource* >      GetAll                          ();
	static Resource*                GetCurrent                      ();

///	virtual CXMLNode*               AddMap					        ( lua_State* pLuaVM, const string& strFilePath, const std::string& strMapName, int iDimension );
///	virtual CXMLNode*               AddConfig				        ( lua_State* pLuaVM, const string& strFilePath, const std::string& strConfigName, int iType );
///	virtual CXMLNode                AddConfig				        ( lua_State* pLuaVM, const char* szFilePath, const char* szFileType = "server" );
///	virtual CXMLNode                AddMap					        ( lua_State* pLuaVM, const char* szFilePath, unsigned int uiDimension = 0 );
///	virtual CXMLNode                GetConfig				        ( lua_State* pLuaVM, const char* szFilePath );
};

#endif