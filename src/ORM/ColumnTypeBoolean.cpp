/*********************************************************
*
*  Copyright � 2017, Xen Roleplay.
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

#include "StdInc.h"
#include "ColumnTypeBoolean.h"

string ColumnTypeBoolean::GetSQLDeclaration( Column * column, AbstractPlatform * platform )
{
	return platform->GetBooleanTypeDeclarationSQL( column );
}
