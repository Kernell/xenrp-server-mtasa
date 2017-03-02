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

class DebugMessageEventArgs;

#ifndef __DEBUGMESSAGEEVENTARGS_H
#define __DEBUGMESSAGEEVENTARGS_H

class DebugMessageEventArgs : public EventArgs
{
public:
	DebugMessageEventArgs( Element* sender, Element* _this, const string& message, int level, const string& file, int line )
		: EventArgs( sender, _this )
	{
		this->Message	= message;
		this->Level		= level;
		this->File		= file;
		this->Line		= line;
	}

	string Message;
	int    Level;
	string File;
	int    Line;
};

#endif
