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
#include "MySQL.h"

MySQL::MySQL( const string& hostname, const string& username, const string& password, const string& database, unsigned int port, const string& unixSocket, unsigned long clientFlags )
{
	this->Handle = mysql_init( nullptr );

	if( this->Handle )
	{
		my_bool reconnect = true;

		mysql_options( this->Handle, MYSQL_OPT_RECONNECT, &reconnect );

		if( !mysql_real_connect( this->Handle, hostname.c_str(), username.c_str(), password.c_str(), database.c_str(), port, unixSocket.length() ? unixSocket.c_str() : nullptr, clientFlags ) )
		{
			throw new exception( "mysql_real_connect failed" );
		}
	}
}

MySQL::~MySQL()
{
	this->Close();
}

void MySQL::Close()
{
	if( this->Handle )
	{
		mysql_close( this->Handle );

		this->Handle = nullptr;
	}
}

bool MySQL::Ping() const
{
	return mysql_ping( this->Handle ) == 0;
}

bool MySQL::SelectDB( const string& db )
{
	return mysql_select_db( this->Handle, db.c_str() ) == 0;
}

string MySQL::EscapeString( const string& str )
{
	size_t len = str.length();
	char* dest = new char[ ( len << 1 ) + 1 ];

	mysql_real_escape_string( this->Handle, dest, str.c_str(), static_cast< unsigned long >( len ) );

	string result( dest );

	delete [] dest;

	return result;
}

unsigned long MySQL::AffectedRows()
{
	return static_cast< unsigned long >( mysql_affected_rows( this->Handle ) );
}

bool MySQL::ChangeUser( const string& username, const string& password, const string & database )
{
	return mysql_change_user( this->Handle, username.c_str(), password.c_str(), database.c_str() );
}

void MySQL::GetCharacterSetInfo( MY_CHARSET_INFO* cs ) const
{
	mysql_get_character_set_info( this->Handle, cs );
}

string MySQL::GetHostInfo() const
{
	return string( mysql_get_host_info( this->Handle ) );
}

unsigned long MySQL::GetProtoInfo() const
{
	return mysql_get_proto_info( this->Handle );
}

string MySQL::GetServerInfo() const
{
	return string( mysql_get_server_info( this->Handle ) );
}

unsigned long MySQL::GetServerVersion() const
{
	return mysql_get_server_version( this->Handle );
}

string MySQL::Info() const
{
	return string( mysql_info( this->Handle ) );
}

unsigned long long MySQL::InsertID() const
{
	return mysql_insert_id( this->Handle );
}

MySQLResult* MySQL::Query( const string& query )
{
	MYSQL_RES* res = nullptr;

	if( mysql_real_query( this->Handle, query.c_str(), static_cast< unsigned long >( query.length() ) ) )
	{
		return nullptr;
	}

	res = mysql_store_result( this->Handle );

	if( res == nullptr && mysql_field_count( this->Handle ) > 0 )
	{
		return nullptr;
	}

	return new MySQLResult( res );
}

MySQLResult* MySQL::UnbufferedQuery( const string& query )
{
	MYSQL_RES* res;

	if( mysql_real_query( this->Handle, query.c_str(), static_cast< unsigned long >( query.length() ) ) )
	{
		return nullptr;
	}

	res = mysql_use_result( this->Handle );

	if( res == nullptr && mysql_field_count( this->Handle ) > 0 )
	{
		return nullptr;
	}

	return new MySQLResult( res );
}

bool MySQL::SetCharacterSet( const string& csname )
{
	return mysql_set_character_set( this->Handle, csname.c_str() );
}

string MySQL::Stat()
{
	return string( mysql_stat( this->Handle ) );
}

unsigned long MySQL::WarningCount()
{
	return mysql_warning_count( this->Handle );
}

unsigned int MySQL::Errno() const
{
	return mysql_errno( this->Handle );
}

string MySQL::Error() const
{
	return string( mysql_error( this->Handle ) );
}
