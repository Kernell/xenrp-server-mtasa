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

#include "EventArgs.h"

#include "EventArgs/AccountDataChangeEventArgs.h"
#include "EventArgs/BanEventArgs.h"
#include "EventArgs/ChatMessageEventArgs.h"
#include "EventArgs/ColShapeEventArgs.h"
#include "EventArgs/ConsoleEventArgs.h"
#include "EventArgs/DebugMessageEventArgs.h"
#include "EventArgs/ElementClickedEventArgs.h"
#include "EventArgs/ElementColShapeEventArgs.h"
#include "EventArgs/ElementDataChangeEventArgs.h"
#include "EventArgs/ElementModelChangeEventArgs.h"
#include "EventArgs/MarkerEventArgs.h"
#include "EventArgs/PedEventArgs.h"
#include "EventArgs/PedWastedEventArgs.h"
#include "EventArgs/PedWeaponSwitchEventArgs.h"
#include "EventArgs/PlayerBanEventArgs.h"
#include "EventArgs/PlayerChangeNickEventArgs.h"
#include "EventArgs/PlayerChatEventArgs.h"
#include "EventArgs/PlayerClickEventArgs.h"
#include "EventArgs/PlayerCommandEventArgs.h"
#include "EventArgs/PlayerConnectEventArgs.h"
#include "EventArgs/PlayerContactEventArgs.h"
#include "EventArgs/PlayerDamageEvetArgs.h"
#include "EventArgs/PlayerEventArgs.h"
#include "EventArgs/PlayerLoginEventArgs.h"
#include "EventArgs/PlayerLogoutEventArgs.h"
#include "EventArgs/PlayerMarkerEventArgs.h"
#include "EventArgs/PlayerModInfoEventArgs.h"
#include "EventArgs/PlayerPickupHitEventArgs.h"
#include "EventArgs/PlayerPickupUseEventArgs.h"
#include "EventArgs/PlayerPrivateMessageEventArgs.h"
#include "EventArgs/PlayerQuitEventArgs.h"
#include "EventArgs/PlayerScreenShotEventArgs.h"
#include "EventArgs/PlayerSpawnEventArgs.h"
#include "EventArgs/PlayerTargetEventArgs.h"
#include "EventArgs/PlayerVehicleEnterEventArgs.h"
#include "EventArgs/ResourceEventArgs.h"
#include "EventArgs/SettingChangeEventArgs.h"
#include "EventArgs/UnbanEventArgs.h"
#include "EventArgs/VehicleDamageEventArgs.h"
#include "EventArgs/VehicleEnterEventArgs.h"
#include "EventArgs/VehicleEventArgs.h"
#include "EventArgs/VehicleRespawnEventArgs.h"
#include "EventArgs/VehicleStartEnterEventArgs.h"

#ifndef __EVENT_H
#define __EVENT_H

#include "EventHandler.h"
#include "EventRaisers.h"

template< typename T >
class Event
{
public:
	Event()
	{
	}

	virtual ~Event()
	{
		list< IEventHandler* >::iterator iter = EventHandlers.begin();

		for( ; iter != EventHandlers.end(); ++iter )
		{
			IEventHandler* handler = *iter;

			if( handler )
			{
				delete handler;
				handler = nullptr;
			}
		}

		EventHandlers.clear();
	}

	virtual void operator()( T* e )
	{
		for( const auto& handler : EventHandlers )
		{
			handler->OnEvent( e );
		}

		delete e;
	}

	Event& operator += ( IEventHandler* handler )
	{
		if( handler )
		{
			EventHandlers.push_back( handler );
		}

		return *this;
	}

	Event& operator -= ( IEventHandler* handler )
	{
		if( !handler )
		{
			return *this;
		}

		list< IEventHandler* >::iterator iter = EventHandlers.begin();

		for( ; iter != EventHandlers.end(); ++iter )
		{
			IEventHandler* _handler = *iter;

			if( handler == _handler )
			{
				delete _handler;
				_handler = nullptr;

				EventHandlers.erase( iter );

				break;
			}
		}

		if( handler )
		{
			delete handler;
			handler = nullptr;
		}

		return *this;
	}

private:
	Event( const Event& );
	Event& operator = ( const Event& );

protected:
	list< IEventHandler* > EventHandlers;
};

#endif