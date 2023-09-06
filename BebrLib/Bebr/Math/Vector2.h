#pragma once

namespace bebr
{
	namespace math
	{
		template<typename T>
		struct Vector2
		{
			T x, y;

			Vector2();
			Vector2( T x, T y );

			Vector2<T> operator+( const Vector2<T>& other ) const;
			Vector2<T> operator-( const Vector2<T>& other ) const;
			Vector2<T> operator*( T scalar ) const;
			Vector2<T> operator/( T scalar ) const;

			Vector2<T>& operator+=( const Vector2<T>& other );
			Vector2<T>& operator-=( const Vector2<T>& other );
			Vector2<T>& operator*=( T scalar );
			Vector2<T>& operator/=( T scalar );

			bool operator==( const Vector2<T>& other ) const;
			bool operator!=( const Vector2<T>& other ) const;
		};

		typedef Vector2<int> Vector2i;
		typedef Vector2<float> Vector2f;
		typedef Vector2<double> Vector2d;
		typedef Vector2<unsigned int> Vector2u;
	}
}
