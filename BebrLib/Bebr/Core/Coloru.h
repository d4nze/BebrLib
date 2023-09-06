#pragma once

namespace bebr
{
	namespace core
	{
		typedef unsigned __int8 uint8_t;
		struct Colorf;

		struct Coloru
		{
			uint8_t r, g, b, a;

			static const Coloru White, Black;
			static const Coloru Red, Green, Blue;
			static const Coloru Orange, Purple, Yellow, Cyan, Magenta, Pink, Teal, Lime, Brown, Gold;

			Coloru();
			Coloru( const Coloru& copyColor );
			Coloru( const Colorf& copyColor );
			Coloru( uint8_t r, uint8_t g, uint8_t b, uint8_t a = 1.f );

			Coloru operator+( const Coloru& other ) const;
			Coloru operator-( const Coloru& other ) const;
			Coloru operator*( uint8_t scalar ) const;
			Coloru operator/( uint8_t scalar ) const;

			Coloru& operator+=( const Coloru& other );
			Coloru& operator-=( const Coloru& other );
			Coloru& operator*=( uint8_t scalar );
			Coloru& operator/=( uint8_t scalar );

			bool operator==( const Coloru& other ) const;
			bool operator!=( const Coloru& other ) const;
		};
	}
}
