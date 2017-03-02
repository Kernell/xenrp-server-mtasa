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

class PlayerPrivateMessageEventArgs;

#ifndef __PLAYERPRIVATEMESSAGEEVENTARGS_H
#define __PLAYERPRIVATEMESSAGEEVENTARGS_H

class PlayerPrivateMessageEventArgs : public PlayerEventArgs
{
public:
	PlayerPrivateMessageEventArgs( Element* sender, Element* _this, string message, ::Player* recipient )
		: PlayerEventArgs( sender, _this, recipient )
	{
		this->Message = message;
	}

	string Message;
};

#endif