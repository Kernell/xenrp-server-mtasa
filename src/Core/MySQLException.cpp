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

#include "StdInc.h"
#include "MySQLException.h"

MySQLException::MySQLException( const MySQL* connection )
{
 	stringstream message;

	message << "#" << connection->Errno() << ": " << connection->Error();

	new ( this ) MySQLException( message.str().c_str() );
}

MySQLException::MySQLException( const char* msg ) :
	exception( msg )
{
}
