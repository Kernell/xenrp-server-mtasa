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

class PlayerMarkerEventArgs;

#ifndef __PLAYERMARKEREVENTARGS_H
#define __PLAYERMARKEREVENTARGS_H

class PlayerMarkerEventArgs : public EventArgs
{
public:
	PlayerMarkerEventArgs( Element* sender, Element* _this, Marker* marker, bool matchingDimension )
		: EventArgs( sender, _this )
	{
		this->Marker            = marker;
		this->MatchingDimension = matchingDimension;
	}

	Marker* Marker;
	bool    MatchingDimension;
};

#endif