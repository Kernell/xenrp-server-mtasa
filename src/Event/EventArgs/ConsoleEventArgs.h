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

class ConsoleEventArgs;

#ifndef __CONSOLEEVENTARGS_H
#define __CONSOLEEVENTARGS_H

class ConsoleEventArgs : public EventArgs
{
public:
	ConsoleEventArgs( Element* sender, Element* _this, const string& message )
		: EventArgs( sender, _this )
	{
		this->Message = message;
	}

	string Message;
};

#endif

