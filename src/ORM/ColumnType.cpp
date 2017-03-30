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
#include "ColumnType.h"
#include "ColumnTypeArray.h"
#include "ColumnTypeDateTime.h"
#include "ColumnTypeInteger.h"
#include "ColumnTypeText.h"
#include "ColumnTypeBigInt.h"
#include "ColumnTypeDateTimeTz.h"
#include "ColumnTypeJsonArray.h"
#include "ColumnTypeTime.h"
#include "ColumnTypeBinary.h"
#include "ColumnTypeDate.h"
#include "ColumnTypeObject.h"
#include "ColumnTypeBlob.h"
#include "ColumnTypeDecimal.h"
#include "ColumnTypeSimpleArray.h"
#include "ColumnTypeBoolean.h"
#include "ColumnTypeFloat.h"
#include "ColumnTypeSmallInt.h"
#include "ColumnTypeGuid.h"
#include "ColumnTypeString.h"

map< ColumnType::ID, ColumnType* > ColumnType::TypesMap
{
	{ ARRAY       , new ColumnTypeArray      ( "array" )        },
	{ SIMPLE_ARRAY, new ColumnTypeSimpleArray( "simple_array" ) },
	{ JSON_ARRAY  , new ColumnTypeJsonArray  ( "json_array" )   },
	{ BIGINT	  , new ColumnTypeBigInt     ( "bigint" )       },
	{ BOOLEAN	  , new ColumnTypeBoolean    ( "boolean" )      },
	{ DATETIME	  , new ColumnTypeDateTime   ( "datetime" )     },
	{ DATETIMETZ  , new ColumnTypeDateTimeTz ( "datetimetz" )   },
	{ DATE		  , new ColumnTypeDate       ( "date" )         },
	{ TIME		  , new ColumnTypeTime       ( "time" )         },
	{ DECIMAL	  , new ColumnTypeDecimal    ( "decimal" )      },
	{ INTEGER	  , new ColumnTypeInteger    ( "integer" )      },
	{ OBJECT	  , new ColumnTypeObject     ( "object" )       },
	{ SMALLINT	  , new ColumnTypeSmallInt   ( "smallint" )     },
	{ STRING	  , new ColumnTypeString     ( "string" )       },
	{ TEXT		  , new ColumnTypeText       ( "text" )         },
	{ BINARY	  , new ColumnTypeBinary     ( "binary" )       },
	{ BLOB		  , new ColumnTypeBlob       ( "blob" )         },
	{ FLOAT		  , new ColumnTypeFloat      ( "float" )        },
	{ GUID		  , new ColumnTypeGuid       ( "guid" )         },
};

ColumnType::ColumnType( const string& name )
{
	this->Name = name;
}

ColumnType* ColumnType::GetType( ID id )
{
	if( TypesMap.count( id ) == 0 )
	{
		throw new exception( "unknown column type" );
	}

	return TypesMap[ id ];
}

ColumnType* ColumnType::GetType( const string& name )
{
	for( const auto& iter : TypesMap )
	{
		if( iter.second->GetName() == name )
		{
			return iter.second;
		}
	}

	throw new exception( ( "unknown column type'" + name + "'" ).c_str() );

	return nullptr;
}

string ColumnType::ConvertToDatabaseValue( const string& value, AbstractPlatform* platform )
{
	return value;
}

string ColumnType::ConvertFromDatabaseValue( const string& value, AbstractPlatform* platform )
{
	return value;
}
