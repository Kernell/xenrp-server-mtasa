#include "StdInc.h"
#include "Color.h"

using namespace SharedUtil;

Color::Color( void )
{
}

Color::Color( unsigned long ulValue )
{
	this->ulARGB = ulValue;
}

Color::operator unsigned long( void ) const
{
	return this->ulARGB;
}

ColorARGB::ColorARGB( unsigned char ucA, unsigned char ucR, unsigned char ucG, unsigned char ucB )
{
	this->A = ucA;
	this->R = ucR;
	this->G = ucG;
	this->B = ucB;
}

ColorRGBA::ColorRGBA( unsigned char ucR, unsigned char ucG, unsigned char ucB, unsigned char ucA )
{
	this->R = ucR;
	this->G = ucG;
	this->B = ucB;
	this->A = ucA;
}
