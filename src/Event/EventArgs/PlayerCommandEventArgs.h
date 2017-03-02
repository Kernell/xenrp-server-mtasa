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

class PlayerCommandEventArgs;

#ifndef __PLAYERCOMMANDEVENTARGS_H
#define __PLAYERCOMMANDEVENTARGS_H

class PlayerCommandEventArgs : public EventArgs
{
public:
	PlayerCommandEventArgs( Element* sender, Element* _this, string command )
		: EventArgs( sender, _this )
	{
		this->Command = command;
	}

	string Command;
};

#endif
