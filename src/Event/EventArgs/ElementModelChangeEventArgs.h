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

class ElementModelChangeEventArgs;

#ifndef __ELEMENTMODELCHANGEEVENTARGS_H
#define __ELEMENTMODELCHANGEEVENTARGS_H

class ElementModelChangeEventArgs : public EventArgs
{
public:
	ElementModelChangeEventArgs( Element* sender, Element* _this, int oldModel, int newModel )
		: EventArgs( sender, _this )
	{
		this->OldModel = oldModel;
		this->NewModel = newModel;
	}

	int OldModel;
	int NewModel;
};

#endif
