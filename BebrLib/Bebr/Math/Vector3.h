#pragma once

namespace bebr
{
	namespace math
	{
		template<typename T>
		struct Vector3
		{
			T x, y, z;

			Vector3();
			Vector3( T x, T y, T z );

			Vector3<T> operator+( const Vector3<T>& other ) const;
			Vector3<T> operator-( const Vector3<T>& other ) const;
			Vector3<T> operator*( T scalar ) const;
			Vector3<T> operator/( T scalar ) const;

			Vector3<T>& operator+=( const Vector3<T>& other );
			Vector3<T>& operator-=( const Vector3<T>& other );
			Vector3<T>& operator*=( T scalar );
			Vector3<T>& operator/=( T scalar );

			bool operator==( const Vector3<T>& other ) const;
			bool operator!=( const Vector3<T>& other ) const;
		};

		typedef Vector3<int> Vector3i;
		typedef Vector3<float> Vector3f;
		typedef Vector3<double> Vector3d;
		typedef Vector3<unsigned int> Vector3u;
	}
}
