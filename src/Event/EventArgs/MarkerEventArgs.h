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

class MarkerEventArgs;

#ifndef __MARKEREVENTARGS_H
#define __MARKEREVENTARGS_H

class MarkerEventArgs : public EventArgs
{
public:
	MarkerEventArgs( Element* sender, Element* _this, Element* element, bool matchingDimension )
		: EventArgs( sender, _this )
	{
		this->Element           = element;
		this->MatchingDimension = matchingDimension;
	}

	Element* Element;
	bool     MatchingDimension;
};

#endif
