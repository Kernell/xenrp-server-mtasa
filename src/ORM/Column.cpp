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
#include "Column.h"

Column::Column( AbstractAsset* parent, const string& columnName, ColumnType* type ) :
	AbstractAsset( parent )
{
	this->SetName( columnName );

	this->Type           = type;
//	this->Default;
	this->NotNull        = false;
	this->Length         = 0;
	this->Precision      = 0;
	this->Scale          = 0;
	this->Fixed          = false;
	this->Unsigned       = false;
	this->AutoIncrement  = false;
//	this->ColumnDefinition;
//	this->Comment;
//	this->Version;

	this->Charset        = "utf8mb4";
	this->Collation      = "utf8mb4_unicode_ci";
	this->Primary        = false;
	this->Unique         = false;
}

void Column::SetType( ColumnType* type )
{
	this->Type = type;
}

void Column::SetLength( size_t length )
{
	this->Length = length;
}

void Column::SetPrecision( int precision )
{
	this->Precision = precision;
}

void Column::SetScale( int scale )
{
	this->Scale = scale;
}

void Column::SetUnsigned( bool __unsigned )
{
	this->Unsigned = __unsigned;
}

void Column::SetFixed( bool fixed )
{
	this->Fixed = fixed;
}

void Column::SetNotNull( bool notnull )
{
	this->NotNull = notnull;
}

void Column::SetDefault( const string& default )
{
	this->Default = default;
}

void Column::SetColumnDefinition( const string& value )
{
	this->ColumnDefinition = value;
}

ColumnType* Column::GetType() const
{
	return this->Type;
}

size_t Column::GetLength() const
{
	return this->Length;
}

int Column::GetPrecision() const
{
	return this->Precision;
}

int Column::GetScale() const
{
	return this->Scale;
}

bool Column::GetUnsigned() const
{
	return this->Unsigned;
}

bool Column::GetFixed() const
{
	return this->Fixed;
}

bool Column::GetNotNull() const
{
	return this->NotNull;
}

string Column::GetDefault() const
{
	return this->Default;
}

string Column::GetColumnDefinition() const
{
	return this->ColumnDefinition;
}

bool Column::GetAutoincrement() const
{
	return this->AutoIncrement;
}

void Column::SetAutoincrement( bool flag )
{
	this->AutoIncrement = flag;
}

void Column::SetComment( const string& comment )
{
	this->Comment = comment;
}

string Column::GetComment() const
{
	return this->Comment;
}
