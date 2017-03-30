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

using namespace std;

string strtolower( string copy )
{
	transform( copy.begin(), copy.end(), copy.begin(), ::tolower );

	return copy;
}

string strtoupper( string copy )
{
	transform( copy.begin(), copy.end(), copy.begin(), ::toupper );

	return copy;
}

string VectorJoin( const vector< string >& vector, const string& delimiter )
{
	string result;

	int i = 0;

	for( const string& str : vector )
	{
		if( i > 0 )
		{
			result += delimiter;
		}

		result += str;

		++i;
	}

	return result;
}

vector< string > StringSplit( const string& str, const string& delimiter )
{
	vector< string > v;
	string buffer;

	size_t len = delimiter.length();

	for( size_t i = 0; i < str.length(); ++i )
	{
		string s = str.substr( i, len );

		if( s == delimiter )
		{
			v.push_back( buffer );
			buffer.clear();

			i += len - 1;

			continue;
		}

		buffer.push_back( str[ i ] );
	}

	v.push_back( buffer );

	return v;
}

string str_replace( const string& search, const string& replace, const string& subject )
{
	string str = subject;
	size_t pos = 0;

	while( ( pos = str.find( search, pos ) ) != string::npos )
	{
		str.replace( pos, search.length(), replace );
		pos += replace.length();
	}

	return str;
}
