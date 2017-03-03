#include "StdInc.h"
#include "Vector2.h"

using namespace Math;

Vector2::Vector2() : X( 0 ), Y( 0 )
{
}

Vector2::Vector2( float x, float y ) : X( x ), Y( y )
{
}

float Vector2::DotProduct( Vector2& other ) const
{
	return X * other.X + Y * other.Y;
}

float Vector2::Length() const
{
	return sqrt( X * X + Y * Y );
}

float Vector2::LengthSquared() const
{
	return ( X * X ) + ( Y * Y );
}

void Vector2::Normalize()
{
	float fLength = Length();

	if( fLength > 0.0f )
	{
		X /= fLength;
		Y /= fLength;
	}
}

Vector2 Vector2::operator * ( float fRight ) const
{
	return Vector2( X * fRight, Y * fRight );
}

Vector2 Vector2::operator / ( float fRight ) const
{
	float fRcpValue = 1 / fRight;

	return Vector2( X * fRcpValue, Y * fRcpValue );
}

Vector2 Vector2::operator + ( const Vector2& vecRight ) const
{
	return Vector2( X + vecRight.X, Y + vecRight.Y );
}

Vector2 Vector2::operator - ( const Vector2& vecRight ) const
{
	return Vector2( X - vecRight.X, Y - vecRight.Y );
}

Vector2 Vector2::operator * ( const Vector2& vecRight ) const
{
	return Vector2( X * vecRight.X, Y * vecRight.Y );
}

Vector2 Vector2::operator / ( const Vector2& vecRight ) const
{
	return Vector2( X / vecRight.X, Y / vecRight.Y );
}

void Vector2::operator += ( float fRight )
{
	X += fRight;
	Y += fRight;
}

void Vector2::operator += ( const Vector2& vecRight )
{
	X += vecRight.X;
	Y += vecRight.Y;
}

void Vector2::operator -= ( float fRight )
{
	X -= fRight;
	Y -= fRight;
}

void Vector2::operator -= ( const Vector2& vecRight )
{
	X -= vecRight.X;
	Y -= vecRight.Y;
}

void Vector2::operator *= ( float fRight )
{
	X *= fRight;
	Y *= fRight;
}

void Vector2::operator *= ( const Vector2& vecRight )
{
	X *= vecRight.X;
	Y *= vecRight.Y;
}

void Vector2::operator /= ( float fRight )
{
	X /= fRight;
	Y /= fRight;
}

void Vector2::operator /= ( const Vector2& vecRight )
{
	X /= vecRight.X;
	Y /= vecRight.Y;
}

bool Vector2::operator == ( const Vector2& param ) const
{
	return ( ( fabs( X - param.X ) < FLOAT_EPSILON ) && ( fabs( Y - param.Y ) < FLOAT_EPSILON ) );
}

bool Vector2::operator != ( const Vector2& param ) const
{
	return ( ( fabs( X - param.X ) >= FLOAT_EPSILON ) || ( fabs( Y - param.Y ) >= FLOAT_EPSILON ) );
}