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

#include <StdInc.h>

namespace SchemaException
{
	class Exception : public exception
	{
	public:
		Exception( const string& msg ) : message( msg )
		{
		}

		Exception( const char* msg ) : message( msg )
		{
		}

		virtual ~Exception() throw ()
		{
		}

		virtual const char* what() const throw ()
		{
			return message.c_str();
		}

	protected:
		string message;
	};

	class ColumnDoesNotExist : public Exception
	{
	public:
		ColumnDoesNotExist( const string& columnName, const string& tableName ) :
			Exception( "There is no column with name '" + columnName + "' on table '" + tableName + "'" )
		{
		}
	};

	class IndexDoesNotExist : public Exception
	{
	public:
		IndexDoesNotExist( const string& indexName, const string& tableName ) :
			Exception( "Index '" + indexName + "' does not exist on table '" + tableName + "'" )
		{
		}
	};

	class IndexAlreadyExists : public Exception
	{
	public:
		IndexAlreadyExists( const string& indexName, const string& tableName ) :
			Exception( "An index with name '" + indexName + "' was already defined on table '" + tableName + "'" )
		{
		}
	};

	class ColumnAlreadyExists : public Exception
	{
	public:
		ColumnAlreadyExists( const string& tableName, const string& columnName ) :
			Exception( "The column '" + columnName + "' on table '" + tableName + "' already exists." )
		{
		}
	};

	class TableAlreadyExists : public Exception
	{
	public:
		TableAlreadyExists( const string& tableName ) :
			Exception( "The table with name '" + tableName + "' already exists" )
		{
		}
	};

	class SequenceAlreadyExists : public Exception
	{
	public:
		SequenceAlreadyExists( const string& sequenceName ) :
			Exception( "The sequence '" + sequenceName + "' already exists" )
		{
		}
	};

	class TableDoesNotExist : public Exception
	{
	public:
		TableDoesNotExist( const string& tableName ) :
			Exception( "There is no table with name '" + tableName + "' in the schema." )
		{
		}
	};
};
