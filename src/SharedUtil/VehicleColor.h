#ifndef __VEHICLECOLOR_H
#define __VEHICLECOLOR_H

#include "Color.h"

namespace SharedUtil
{
	class VehicleColor
	{
	public:
						VehicleColor                ();

		void            SetRGBColors                ( Color color1, Color color2, Color color3, Color color4 );
		void            SetPaletteColors            ( uchar ucColor1, uchar ucColor2, uchar ucColor3, uchar ucColor4 );

		void            SetRGBColor                 ( uint uiSlot, Color color );
		void            SetPaletteColor             ( uint uiSlot, uchar ucColor );

		Color           GetRGBColor                 ( uint uiSlot ) const;
		uchar			GetPaletteColor             ( uint uiSlot ) const;

		int             GetNumColorsUsed            ( void ) const;

		static uchar    GetPaletteIndexFromRGB      ( Color color );
		static Color    GetRGBFromPaletteIndex      ( uchar ucColor );

	protected:
		void            InvalidatePaletteColors     () const;
		void            ValidatePaletteColors       () const;
		void            InvalidateRGBColors         () const;
		void            ValidateRGBColors           () const;

		mutable Color   m_RGBColors[ 4 ];
		mutable uchar	m_ucPaletteColors[ 4 ];
		mutable bool    m_bPaletteColorsWrong;
		mutable bool    m_bRGBColorsWrong;
	};
};
#endif
