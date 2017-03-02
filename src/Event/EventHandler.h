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

#ifndef __EVEHTHANDLER_H
#define __EVEHTHANDLER_H

#include "Event/EventArgs.h"

class IEventHandler
{
public:
	virtual void OnEvent( EventArgs* e ) = 0;
};

template< typename U >
class EventHandler : public IEventHandler
{
public:
	EventHandler( void (U::*functionPointer)( EventArgs* ), U* instance )
		: FunctionPointer( functionPointer ),
		InstancePointer( instance )
	{
	}

	virtual void OnEvent( EventArgs* e )
	{
		if( InstancePointer )
		{
			(InstancePointer->*FunctionPointer)( e );
		}
	}

private:
	void (U::*FunctionPointer)( EventArgs* );
	U* InstancePointer;
};

#endif
