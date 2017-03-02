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

class ElementClickedEventArgs;

#ifndef __ELEMENTCLICKEDEVENTARGS_H
#define __ELEMENTCLICKEDEVENTARGS_H

class ElementClickedEventArgs : public EventArgs
{
public:
	ElementClickedEventArgs( Element* sender, Element* _this, string mouseButton, string buttonState, Player* whoClicked, Math::Vector3 clickPos )
		: EventArgs( sender, _this )
	{
		this->MouseButton	= mouseButton;
		this->ButtonState	= buttonState;
		this->WhoClicked	= whoClicked;
		this->ClickPosition	= clickPos;
	}

	string        MouseButton;
	string        ButtonState;
	Player*       WhoClicked;
	Math::Vector3 ClickPosition;
};

#endif
