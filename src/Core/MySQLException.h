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

#pragma once

#include "MySQL.h"

class MySQLException : public exception
{
public:
	MySQLException( const MySQL* connection );
	MySQLException( const char* msg );

	virtual ~MySQLException() throw ()
	{
	}
};
