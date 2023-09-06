#pragma once

namespace bebr
{
	namespace math
	{
		template<typename T>
		struct Vector4
		{
			T x, y, z, w;

			Vector4();
			Vector4( T x, T y, T z, T w );

			Vector4<T> operator+( const Vector4<T>& other ) const;
			Vector4<T> operator-( const Vector4<T>& other ) const;
			Vector4<T> operator*( T scalar ) const;
			Vector4<T> operator/( T scalar ) const;

			Vector4<T>& operator+=( const Vector4<T>& other );
			Vector4<T>& operator-=( const Vector4<T>& other );
			Vector4<T>& operator*=( T scalar );
			Vector4<T>& operator/=( T scalar );

			bool operator==( const Vector4<T>& other ) const;
			bool operator!=( const Vector4<T>& other ) const;
		};

		typedef Vector4<int> Vector4i;
		typedef Vector4<float> Vector4f;
		typedef Vector4<double> Vector4d;
		typedef Vector4<unsigned int> Vector4u;
	}
}
