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

		Color           GetRGBColor                 ( uint uiSlot );
		uchar			GetPaletteColor             ( uint uiSlot );

		int             GetNumColorsUsed            ( void );

		static uchar    GetPaletteIndexFromRGB      ( Color color );
		static Color    GetRGBFromPaletteIndex      ( uchar ucColor );

	protected:
		void            InvalidatePaletteColors     ( void );
		void            ValidatePaletteColors       ( void );
		void            InvalidateRGBColors         ( void );
		void            ValidateRGBColors           ( void );

		Color           m_RGBColors[ 4 ];
		uchar		    m_ucPaletteColors[ 4 ];
		bool            m_bPaletteColorsWrong;
		bool            m_bRGBColorsWrong;
	};
};
#endif
