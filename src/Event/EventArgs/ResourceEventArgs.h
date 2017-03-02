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

class ResourceEventArgs;

#ifndef __RESOURCEEVENTARGS_U
#define __RESOURCEEVENTARGS_U

class ResourceEventArgs : public EventArgs
{
public:
	ResourceEventArgs( Element* sender, Element* _this, Resource* resource )
		: EventArgs( sender, _this )
	{
		this->Resource = resource;
	}

	Resource* Resource;
};

#endif