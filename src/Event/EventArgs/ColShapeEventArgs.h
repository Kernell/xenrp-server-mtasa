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

class ColShapeEventArgs;

#ifndef __COLSHAPEEVENTARGS_H
#define __COLSHAPEEVENTARGS_H

class ColShapeEventArgs : public EventArgs
{
public:
	ColShapeEventArgs( Element* sender, Element* _this, Element* hitElement, bool matchingDimension )
		: EventArgs( sender, _this )
	{
		this->HitElement        = hitElement;
		this->MatchingDimension	= matchingDimension;
	}

	Element* HitElement;
	bool     MatchingDimension;
};

#endif
