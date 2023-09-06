#pragma once

namespace bebr
{
	namespace core
	{
		struct Coloru;

		struct Colorf
		{
			float r, g, b, a;

			static const Colorf White, Black;
			static const Colorf Red, Green, Blue;
			static const Colorf DarkRed, DarkGreen, DarkBlue;
			static const Colorf Orange, Purple, Yellow, Cyan, Magenta, Pink, Teal, Lime, Brown, Gold;

			Colorf();
			Colorf( const Colorf& copyColor );
			Colorf( const Coloru& copyColor );
			Colorf( float r, float g, float b, float a = 1.f );

			Colorf operator+( const Colorf& other ) const;
			Colorf operator-( const Colorf& other ) const;
			Colorf operator*( float scalar ) const;
			Colorf operator/( float scalar ) const;

			Colorf& operator+=( const Colorf& other );
			Colorf& operator-=( const Colorf& other );
			Colorf& operator*=( float scalar );
			Colorf& operator/=( float scalar );

			bool operator==( const Colorf& other ) const;
			bool operator!=( const Colorf& other ) const;
		};
	}
}
