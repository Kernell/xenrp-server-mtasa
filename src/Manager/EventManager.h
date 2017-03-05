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

class EventManager;

#ifndef __EVENTMANAGER_H
#define __EVENTMANAGER_H

#include "Event/Event.h"

typedef void( *RaiseMethod )( Element*, Element*, vector< LuaArgument* > );

class EventManager
{
public:
								EventManager            ( Module* module );
								~EventManager           ();

	void                        Connect                 ( const string& name, const string& handlerElement, RaiseMethod method );
	void                        Disconnect              ( const string& name, const string& handlerElement, RaiseMethod method = nullptr );

	bool                        Call                    ( vector< LuaArgument* > arguments );

	inline Module*              GetModule               () const { return this->Module; }

private:
	Module*                     Module;
	map< string, RaiseMethod >  Events;
};

#endif
