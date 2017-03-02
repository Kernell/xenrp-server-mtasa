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

class PlayerPickupUseEventArgs;

#ifndef __PLAYERPICKUPUSEEVENTARGS_H
#define __PLAYERPICKUPUSEEVENTARGS_H

class PlayerPickupUseEventArgs : public EventArgs
{
public:
	PlayerPickupUseEventArgs( Element* sender, Element* _this, Pickup* pickup )
		: EventArgs( sender, _this )
	{
		this->Pickup = pickup;
	}

	Pickup* Pickup;
};

#endif