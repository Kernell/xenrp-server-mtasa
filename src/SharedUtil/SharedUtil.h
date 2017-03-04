#ifndef __SHAREDUTIL_H
#define __SHAREDUTIL_H

namespace SharedUtil
{
	template< typename T >
	T Min( const T& a, const T& b )
	{
		return a < b ? a : b;
	}

	template< typename T >
	T Max( const T& a, const T& b )
	{
		return a > b ? a : b;
	}

	template< typename T >
	T Clamp( const T& min, const T& a, const T& max )
	{
		return a < min ? min : a > max ? max : a;
	}

	template< typename T >
	T Lerp( const T& from, float fAlpha, const T& to )
	{
		return (T)( ( to - from ) * fAlpha + from );
	}

	inline const float Unlerp( const double dFrom, const double dPos, const double dTo )
	{
		if( dFrom == dTo )
		{
			return 1.0f;
		}

		return static_cast<float>( ( dPos - dFrom ) / ( dTo - dFrom ) );
	}

	inline const float UnlerpClamped( const double dFrom, const double dPos, const double dTo )
	{
		return Clamp( 0.0f, Unlerp( dFrom, dPos, dTo ), 1.0f );
	}

	template < typename T >
	int Round( T value )
	{
		return static_cast<int>( floor( value + 0.5f ) );
	}

	template < typename T > T
		WrapAround( T fLow, T fValue, T fHigh )
	{
		const T fSize = fHigh - fLow;

		return fValue - ( fSize * floor( ( fValue - fLow ) / fSize ) );
	}

	struct HeatHazeSettings
	{
		HeatHazeSettings( void )
			: ucIntensity( 0 ),
			ucRandomShift( 0 ),
			usSpeedMin( 1 ),
			usSpeedMax( 1 ),
			sScanSizeX( 1 ),
			sScanSizeY( 1 ),
			usRenderSizeX( 1 ),
			usRenderSizeY( 1 ),
			bInsideBuilding( false )
		{
		}

		unsigned char		ucIntensity;        //     0 to 255
		unsigned char		ucRandomShift;      //     0 to 255
		unsigned short		usSpeedMin;         //     0 to 1000
		unsigned short		usSpeedMax;         //     0 to 1000
		short				sScanSizeX;         // -1000 to 1000
		short				sScanSizeY;         // -1000 to 1000
		unsigned short		usRenderSizeX;      //     0 to 1000
		unsigned short		usRenderSizeY;      //     0 to 1000
		bool				bInsideBuilding;
	};
};
#endif
