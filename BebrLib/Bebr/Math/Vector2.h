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
			template<typename M>
			Vector2( const Vector2<M>& other );

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

template<typename T>
template<typename M>
bebr::math::Vector2<T>::Vector2( const Vector2<M>& other ) :
	x( static_cast<T>(other.x) ),
	y( static_cast<T>(other.y) ) {}
