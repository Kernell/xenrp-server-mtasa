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

class PlayerClickEventArgs;

#ifndef __PLAYERCLICKEVENTARGS_H
#define __PLAYERCLICKEVENTARGS_H

class PlayerClickEventArgs : public EventArgs
{
public:
	PlayerClickEventArgs( Element* sender, Element* _this, string mouseButton, string buttonState, Element* clickedElement, Math::Vector3 world, Math::Vector2 screen )
		: EventArgs( sender, _this )
	{
		this->MouseButton	 = mouseButton;
		this->ButtonState	 = buttonState;
		this->ClickedElement = clickedElement;
		this->WorldPosition	 = world;
		this->ScreenPosition = screen;
	}

	string        MouseButton;
	string        ButtonState;
	Element*      ClickedElement;
	Math::Vector3 WorldPosition;
	Math::Vector2 ScreenPosition;
};

#endif