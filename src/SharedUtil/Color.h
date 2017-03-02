#ifndef __COLOR_H
#define __COLOR_H

namespace SharedUtil
{
	//
	// SColor
	//
	// Encapsulates the most common usage of 4 byte color storage.
	// Casts to and from a DWORD as 0xAARRGGBB
	//
	class Color
	{
		// No shifting allowed to access the color channel information
		void operator >> ( int ) const;
		void operator << ( int ) const;
		void operator >>= ( int );
		void operator <<= ( int );

	public:
		union
		{
			struct
			{
				unsigned char B, G, R, A;
			};

			unsigned long ulARGB;
		};

		Color( void );

		Color( unsigned long ulValue );

		operator unsigned long( void ) const;
	};


	//
	// SColorARGB
	//
	// Make an SColor from A,R,G,B
	//
	class ColorARGB : public Color
	{
	public:
		ColorARGB( unsigned char ucA, unsigned char ucR, unsigned char ucG, unsigned char ucB );

		template< class T, class U, class V, class W >
		ColorARGB( T a, U r, V g, W b )
		{
			this->A = Clamp< unsigned char >( 0, static_cast< unsigned char >( a ), 255 );
			this->R = Clamp< unsigned char >( 0, static_cast< unsigned char >( r ), 255 );
			this->G = Clamp< unsigned char >( 0, static_cast< unsigned char >( g ), 255 );
			this->B = Clamp< unsigned char >( 0, static_cast< unsigned char >( b ), 255 );
		}
	};


	//
	// SColorRGBA
	//
	// Make an SColor from R,G,B,A
	//
	class ColorRGBA : public Color
	{
	public:
		ColorRGBA( unsigned char ucR, unsigned char ucG, unsigned char ucB, unsigned char ucA );

		template< class T, class U, class V, class W >
		ColorRGBA( T r, U g, V b, W a )
		{
			this->R = Clamp< unsigned char >( 0, static_cast< unsigned char >( r ), 255 );
			this->G = Clamp< unsigned char >( 0, static_cast< unsigned char >( g ), 255 );
			this->B = Clamp< unsigned char >( 0, static_cast< unsigned char >( b ), 255 );
			this->A = Clamp< unsigned char >( 0, static_cast< unsigned char >( a ), 255 );
		}
	};
};
#endif
