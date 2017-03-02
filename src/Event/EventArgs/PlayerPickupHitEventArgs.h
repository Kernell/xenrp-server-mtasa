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

class PlayerPickupHitEventArgs;

#ifndef __PLAYERPICKUPHITEVENTARGS_H
#define __PLAYERPICKUPHITEVENTARGS_H

class PlayerPickupHitEventArgs : public EventArgs
{
public:
	PlayerPickupHitEventArgs( Element* sender, Element* _this, Pickup* pickup, bool matchingDimension )
		: EventArgs( sender, _this )
	{
		this->Pickup = pickup;
		this->MatchingDimension = matchingDimension;
	}

	Pickup* Pickup;
	bool    MatchingDimension;
};

#endif