/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        sdk/CVector2D.h
*  PURPOSE:     2D vector class
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __Vector2D_H
#define __Vector2D_H

#include <cmath>
#include "Vector3.h"

namespace Math
{
	class Vector2
	{
	public:
		float X;
		float Y;

		Vector2();
		Vector2( float x, float y );

		float		DotProduct		( Vector2& other ) const;
		float		Length			() const;
		float		LengthSquared	() const;
		void		Normalize		();

		Vector2 operator * ( float fRight ) const;
		Vector2 operator / ( float fRight ) const;
		Vector2 operator + ( const Vector2& vecRight ) const;
		Vector2 operator - ( const Vector2& vecRight ) const;
		Vector2 operator * ( const Vector2& vecRight ) const;
		Vector2 operator / ( const Vector2& vecRight ) const;

		void operator += ( float fRight );
		void operator += ( const Vector2& vecRight );
		void operator -= ( float fRight );
		void operator -= ( const Vector2& vecRight );
		void operator *= ( float fRight );
		void operator *= ( const Vector2& vecRight );
		void operator /= ( float fRight );
		void operator /= ( const Vector2& vecRight );
		bool operator == ( const Vector2& param ) const;
		bool operator != ( const Vector2& param ) const;
	};
};

#endif
