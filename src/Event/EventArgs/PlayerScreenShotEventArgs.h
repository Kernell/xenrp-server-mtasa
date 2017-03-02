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

class PlayerScreenShotEventArgs;

#ifndef __PLAYERSCREENSHOTEVENTARGS_H
#define __PLAYERSCREENSHOTEVENTARGS_H

class PlayerScreenShotEventArgs : public EventArgs
{
public:
	PlayerScreenShotEventArgs( Element* sender, Element* _this, Resource* resource, string status, string imageData, int timestamp, string tag )
		: EventArgs( sender, _this )
	{
		this->Resource  = resource;
		this->Status    = status;
		this->ImageData = imageData;
		this->Timestamp = timestamp;
		this->Tag       = tag;
	}

	Resource* Resource;
	string    Status;
	string    ImageData;
	int       Timestamp;
	string    Tag;
};

#endif