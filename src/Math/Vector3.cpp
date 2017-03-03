#include "StdInc.h"
#include "Vector3.h"

using namespace Math;

Vector3::Vector3() :
	X( 0 ), Y( 0 ), Z( 0 )
{
};

Vector3::Vector3( float x, float y, float z ) :
	X( x ), Y( y ), Z( z )
{
}

float Vector3::Normalize()
{
	float t = sqrt( this->X * this->X + this->Y * this->Y + this->Z * this->Z );

	if( t > FLOAT_EPSILON )
	{
		float fRcpt = 1 / t;

		this->X *= fRcpt;
		this->Y *= fRcpt;
		this->Z *= fRcpt;
	}
	else
	{
		t = 0;
	}
		
	return t;
}

float Vector3::Length() const
{
	return sqrt( ( X * X ) + ( Y * Y ) + ( Z * Z ) );
}

float Vector3::LengthSquared() const
{
	return ( X * X ) + ( Y * Y ) + ( Z * Z );
}

float Vector3::DotProduct( const Vector3* param ) const
{
	return X * param->X + Y * param->Y + Z * param->Z;
}

void Vector3::CrossProduct( const Vector3* param )
{
	float _X = X, _Y = Y, _Z = Z;

	X = _Y * param->Z - param->Y * _Z;
	Y = _Z * param->X - param->Z * _X;
	Z = _X * param->Y - param->X * _Y;
}

Vector3 Vector3::ToRotation() const
{
	Vector3 vecRotation;

	vecRotation.Z = atan2( Y, X );

	Vector3 vecTemp( sqrt( X * X + Y * Y ), Z, 0 );

	vecTemp.Normalize();

	vecRotation.Y = atan2( vecTemp.X, vecTemp.Y ) - PI / 2;

	return vecRotation;
}

Vector3 Vector3::GetOtherAxis() const
{
	Vector3 vecResult;

	if( abs( X ) > abs( Y ) )
	{
		vecResult = Vector3( Z, 0, -X );
	}
	else
	{
		vecResult = Vector3( 0, -Z, Y );
	}

	vecResult.Normalize();

	return vecResult;
}

Vector3 Vector3::operator + ( const Vector3& vecRight ) const
{
	return Vector3( X + vecRight.X, Y + vecRight.Y, Z + vecRight.Z );
}

Vector3 Vector3::operator - ( const Vector3& vecRight ) const
{
	return Vector3( X - vecRight.X, Y - vecRight.Y, Z - vecRight.Z );
}

Vector3 Vector3::operator * ( const Vector3& vecRight ) const
{
	return Vector3( X * vecRight.X, Y * vecRight.Y, Z * vecRight.Z );
}

Vector3 Vector3::operator * ( float fRight ) const
{
	return Vector3( X * fRight, Y * fRight, Z * fRight );
}

Vector3 Vector3::operator / ( const Vector3& vecRight ) const
{
	return Vector3( X / vecRight.X, Y / vecRight.Y, Z / vecRight.Z );
}

Vector3 Vector3::operator / ( float fRight ) const
{
	float fRcpValue = 1 / fRight;

	return Vector3( X * fRcpValue, Y * fRcpValue, Z * fRcpValue );
}

Vector3 Vector3::operator - ( ) const
{
	return Vector3( -X, -Y, -Z );
}

void Vector3::operator += ( float fRight )
{
	X += fRight;
	Y += fRight;
	Z += fRight;
}

void Vector3::operator += ( const Vector3& vecRight )
{
	X += vecRight.X;
	Y += vecRight.Y;
	Z += vecRight.Z;
}

void Vector3::operator -= ( float fRight )
{
	X -= fRight;
	Y -= fRight;
	Z -= fRight;
}

void Vector3::operator -= ( const Vector3& vecRight )
{
	X -= vecRight.X;
	Y -= vecRight.Y;
	Z -= vecRight.Z;
}

void Vector3::operator *= ( float fRight )
{
	X *= fRight;
	Y *= fRight;
	Z *= fRight;
}

void Vector3::operator *= ( const Vector3& vecRight )
{
	X *= vecRight.X;
	Y *= vecRight.Y;
	Z *= vecRight.Z;
}

void Vector3::operator /= ( float fRight )
{
	float fRcpValue = 1 / fRight;
	X *= fRcpValue;
	Y *= fRcpValue;
	Z *= fRcpValue;
}

void Vector3::operator /= ( const Vector3& vecRight )
{
	X /= vecRight.X;
	Y /= vecRight.Y;
	Z /= vecRight.Z;
}

bool Vector3::operator == ( const Vector3& param ) const
{
	return ( ( fabs( X - param.X ) < FLOAT_EPSILON ) && ( fabs( Y - param.Y ) < FLOAT_EPSILON ) && ( fabs( Z - param.Z ) < FLOAT_EPSILON ) );
}

bool Vector3::operator != ( const Vector3& param ) const
{
	return ( ( fabs( X - param.X ) >= FLOAT_EPSILON ) || ( fabs( Y - param.Y ) >= FLOAT_EPSILON ) || ( fabs( Z - param.Z ) >= FLOAT_EPSILON ) );
}
