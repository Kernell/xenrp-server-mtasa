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

MySQLResult::MySQLResult( MYSQL_RES* result )
{
	if( mysql_num_rows( result ) > 0 )
	{
		MYSQL_ROW row = nullptr;

		while( row = mysql_fetch_row( result ) )
		{
			mysql_field_seek( result, 0 );

			MYSQL_FIELD* field = mysql_fetch_field( result );

			MySQLRow resultRow;

			for( size_t i = 0; field != nullptr; ++i )
			{
				resultRow[ field->name ] = row[ i ] ? row[ i ] : "(null)";
				
				field = mysql_fetch_field( result );
			}

			this->Rows.push_back( MySQLRow( resultRow ) );
		}
	}

	mysql_free_result( result );
}

MySQLResult::~MySQLResult()
{
	this->Free();
}

void MySQLResult::Free()
{
	this->Rows.clear();
}

size_t MySQLResult::NumRows() const
{
	return this->Rows.size();
}

MySQLResult::const_iterator MySQLResult::begin() const
{
	return this->Rows.begin();
}

MySQLResult::const_iterator MySQLResult::end() const
{
	return this->Rows.end();
}

MySQLRow MySQLResult::operator[]( size_t index ) const
{
	return this->Rows.at( index );
}
