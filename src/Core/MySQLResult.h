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

class MySQLResult;

typedef std::map< string, string > MySQLRow;

#ifndef __MYSQLRESULT_H
#define __MYSQLRESULT_H

#include <mysql.h>

class MySQLResult
{
public:
	MySQLResult( MYSQL_RES* res );
	~MySQLResult();

	void               Free         ();
	bool               IsEmpty      () const;
	void               DataSeek     ( unsigned long long offset );
	MYSQL_FIELD*       FetchField   ();
	unsigned long*     FetchLengths ();
	MYSQL_ROW          FetchRow     ();
	MySQLRow           FetchRowAssoc();
	unsigned int       FieldSeek    ( unsigned int offset );
	unsigned int       FieldTell    ();
	unsigned int       NumFields    () const;
	unsigned long long NumRows      () const;

private:
	MYSQL_RES*         Result;
};

#endif
