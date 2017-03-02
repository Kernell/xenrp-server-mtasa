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

class PlayerChatEventArgs;

#ifndef __PLAYERCHATEVENTARGS_H
#define __PLAYERCHATEVENTARGS_H

class PlayerChatEventArgs : public EventArgs
{
public:
	PlayerChatEventArgs( Element* sender, Element* _this, string message, int messageType )
		: EventArgs( sender, _this )
	{
		this->Message	= message;
		this->Type		= messageType;
	}

	string Message;
	int    Type;
};

#endif
