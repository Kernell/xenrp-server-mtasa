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
	typedef vector< MySQLRow >::iterator       iterator;
	typedef vector< MySQLRow >::const_iterator const_iterator;

public:
	MySQLResult( MYSQL_RES* res );
	~MySQLResult();

	void                Free         ();
	vector< MySQLRow >  FetchAll     () const;
	size_t              NumRows      () const;
	const_iterator      begin        () const;
	const_iterator      end          () const;

	MySQLRow            operator[]   ( size_t index ) const;

private:
	vector< MySQLRow >  Rows;
};

#endif
