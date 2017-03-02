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

class PlayerQuitEventArgs;

#ifndef __PLAYERQUITEVENTARGS_H
#define __PLAYERQUITEVENTARGS_H

class PlayerQuitEventArgs : public EventArgs
{
public:
	PlayerQuitEventArgs( Element* sender, Element* _this, string type, string reason, Player* responsePlayer )
		: EventArgs( sender, _this )
	{
		this->Type           = type;
		this->Reason         = reason;
		this->ResponsePlayer = responsePlayer;
	}

	string Type;
	string Reason;
	Player* ResponsePlayer;
};

#endif
