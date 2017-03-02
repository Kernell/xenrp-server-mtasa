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

class ChatMessageEventArgs;

#ifndef __CHATMESSAGEEVENTARGS_H
#define __CHATMESSAGEEVENTARGS_H

class ChatMessageEventArgs : public EventArgs
{
public:
	ChatMessageEventArgs( Element* sender, Element* _this, const string& message, Element* element )
		: EventArgs( sender, _this )
	{
		this->Message = message;
		this->Element = element;
	}

	string Message;
	Element* Element;
};

#endif
