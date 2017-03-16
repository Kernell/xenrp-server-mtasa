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
#include "MySQLResult.h"

MySQLResult::MySQLResult( MYSQL_RES* res ) :
	Result( res )
{
}

MySQLResult::~MySQLResult()
{
	if( this->Result )
	{
		mysql_free_result( this->Result );
	}
}

bool MySQLResult::IsEmpty() const
{
	return this->Result == nullptr;
}

void MySQLResult::DataSeek( unsigned long long offset )
{
	mysql_data_seek( this->Result, offset );
}

MYSQL_FIELD* MySQLResult::FetchField()
{
	return mysql_fetch_field( this->Result );
}

unsigned long* MySQLResult::FetchLengths()
{
	return mysql_fetch_lengths( this->Result );
}

MYSQL_ROW MySQLResult::FetchRow()
{
	return this->Result ? mysql_fetch_row( this->Result ) : nullptr;
}

MySQLRow MySQLResult::FetchRowAssoc()
{
	MySQLRow result;

	MYSQL_ROW row = this->FetchRow();

	if( row )
	{
		this->FieldSeek( 0 );

		MYSQL_FIELD* field = this->FetchField();
		unsigned int i     = 0;

		for( ; field != NULL; ++i )
		{
			result[ field->name ] = row[ i ] ? row[ i ] : "(null)";

			field = this->FetchField();
		}
	}

	return result;
}

unsigned int MySQLResult::FieldSeek( unsigned int offset )
{
	return mysql_field_seek( this->Result, offset );
}

unsigned int MySQLResult::FieldTell()
{
	return mysql_field_tell( this->Result );
}

unsigned int MySQLResult::NumFields() const
{
	return mysql_num_fields( this->Result );
}

unsigned long long MySQLResult::NumRows() const
{
	return mysql_num_rows( this->Result );
}
