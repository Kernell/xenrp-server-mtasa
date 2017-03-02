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

class Element;

#ifndef __ELEMENT_H
#define __ELEMENT_H

class Element
{
public:
												Element                     ( PVOID luaUserdata );
	virtual                                     ~Element                    ();

	inline PVOID                                GetLuaUserdata              () const                  { return this->LuaUserdata; }

	virtual void                                DoPulse                     ();
	virtual void                                Save                        () const;

private:
	PVOID                                       LuaUserdata;
};

#endif
