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

class Team;

#ifndef __TEAM_H
#define __TEAM_H

#include "Element.h"

class Team : public Element
{
public:
									Team                     ( PVOID luaUserdata );
	                                Team                     ( const string& teamName, const Color& color = 0xFFFFFFFF );
	virtual                         ~Team                    ();

///	static Team*                    GetFromName		         ( const string& teamName );
	virtual string                  GetName			         () const;
	virtual Color                   GetColor		         () const;
	virtual uint                    CountPlayers             () const;
	virtual bool                    GetFriendlyFire          () const;

	virtual bool                    SetName			         ( const string& teamName );
	virtual bool                    SetColor		         ( const Color& color );
	virtual bool                    SetFriendlyFire	         ( bool friendlyFire );

};

#endif