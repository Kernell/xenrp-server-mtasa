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

class PlayerChangeNickEventArgs;

#ifndef __PLAYERCHANGENICKEVENTARGS_H
#define __PLAYERCHANGENICKEVENTARGS_H

class PlayerChangeNickEventArgs : public EventArgs
{
public:
	PlayerChangeNickEventArgs( Element* sender, Element* _this, string oldNick, string newNick )
		: EventArgs( sender, _this )
	{
		this->Old = oldNick;
		this->New = newNick;
	}

	string Old;
	string New;
};

#endif