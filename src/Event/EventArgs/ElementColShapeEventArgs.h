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

class ElementColShapeEventArgs;

#ifndef __ELEMENTCOLSHAPEEVENTARGS_H
#define __ELEMENTCOLSHAPEEVENTARGS_H

class ElementColShapeEventArgs : public EventArgs
{
public:
	ElementColShapeEventArgs( Element* sender, Element* _this, ColShape* colShape, bool matchingDimension )
		: EventArgs( sender, _this )
	{
		this->ColShape          = colShape;
		this->MatchingDimension	= matchingDimension;
	}

	ColShape* ColShape;
	bool      MatchingDimension;
};

#endif
