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

class MySQL;

#ifndef __MYSQL_H
#define __MYSQL_H

#include <mysql.h>
#include "MySQLResult.h"

class MySQL
{
public:
	MySQL( const string& hostname, const string& username, const string& password, const string& database, unsigned int port = 3306, const string& unixSocket = "", unsigned long clientFlags = NULL );
	~MySQL();

	void               Close               ();
	bool               Ping                () const;
	bool               SelectDB            ( const string& db );
	string             EscapeString        ( const string& str );
	unsigned long      AffectedRows        ();
	bool               ChangeUser          ( const string& username, const string& password, const string& database );
	void               GetCharacterSetInfo ( MY_CHARSET_INFO* cs ) const;
	string             GetHostInfo         () const;
	unsigned long      GetProtoInfo        () const;
	string             GetServerInfo       () const;
	unsigned long      GetServerVersion    () const;
	string             Info                () const;
	unsigned long long InsertID            () const;
	MySQLResult*       Query               ( const string& query );
	MySQLResult*       UnbufferedQuery     ( const string& query );
	bool               SetCharacterSet     ( const string& csname );
	string             Stat                ();
	unsigned long      WarningCount        ();

	unsigned int       Errno() const;
	string             Error() const;

private:
	MYSQL* Handle;
};

#endif