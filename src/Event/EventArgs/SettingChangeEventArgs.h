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

class SettingChangeEventArgs;

#ifndef __SETTINGCHANGEEVENTARGS_H
#define __SETTINGCHANGEEVENTARGS_H

class SettingChangeEventArgs : public EventArgs
{
public:
	SettingChangeEventArgs( Element* sender, Element* _this, string setting, string oldValue, string newValue )
		: EventArgs( sender, _this )
	{
		this->Setting  = setting;
		this->OldValue = oldValue;
		this->NewValue = newValue;
	}

	string Setting;
	string OldValue;
	string NewValue;
};

#endif