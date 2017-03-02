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

class PlayerEventArgs;

#ifndef __PLAYEREVENTARGS_H
#define __PLAYEREVENTARGS_H

class PlayerEventArgs : public EventArgs
{
public:
	PlayerEventArgs( Element* sender, Element* _this, Player* player )
		: EventArgs( sender, _this )
	{
		this->Player = player;
	}

	Player* Player;
};

#endif