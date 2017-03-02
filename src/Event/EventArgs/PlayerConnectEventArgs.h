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

class PlayerConnectEventArgs;

#ifndef __PLAYERCONNECTEVENTARGS_H
#define __PLAYERCONNECTEVENTARGS_H

class PlayerConnectEventArgs : public EventArgs
{
public:
	PlayerConnectEventArgs( Element* sender, Element* _this, string nick, string ip, string username, string serial, int versionNumber, string versionString )
		: EventArgs( sender, _this )
	{
		this->Nick          = nick;
		this->IP            = ip;
		this->Username      = username;
		this->Serial        = serial;
		this->VersionNumber = versionNumber;
		this->VersionString = versionString;
	}

	string Nick;
	string IP;
	string Username;
	string Serial;
	int    VersionNumber;
	string VersionString;
};

#endif
