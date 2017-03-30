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
#include "ColumnTypeBigInt.h"

string ColumnTypeBigInt::GetSQLDeclaration( Column * column, AbstractPlatform * platform )
{
	return platform->GetBigIntTypeDeclarationSQL( column );
}
