#pragma once

namespace bebr
{
	namespace math
	{
		template<unsigned int width, unsigned int height>
		class Matrix
		{
		public:
			Matrix();
			Matrix( float value );

			float* operator[]( unsigned int index );

			Matrix<width, height> operator+( const Matrix<width, height>& other ) const;
			Matrix<width, height>& operator+=( const Matrix<width, height>& other );
			Matrix<width, height> operator-( const Matrix<width, height>& other ) const;
			Matrix<width, height>& operator-=( const Matrix<width, height>& other );

			Matrix<width, height> operator*( float scalar ) const;
			Matrix<width, height>& operator*=( float scalar );
			Matrix<width, height> operator/( float scalar ) const;
			Matrix<width, height>& operator/=( float scalar );

			template<unsigned int pWidth>
			Matrix<pWidth, height> operator*( const Matrix<pWidth, width>& other ) const;
			template<unsigned int pWidth>
			Matrix<width, height>& operator*=( const Matrix<pWidth, width>& other );

			bool operator==( const Matrix<width, height>& other ) const;
			bool operator!=( const Matrix<width, height>& other ) const;

		private:
			float m_data[ width ][ height ];
		};

		typedef Matrix<2, 2> Mat2;
		typedef Matrix<2, 3> Mat2x3;
		typedef Matrix<2, 4> Mat2x4;
		typedef Matrix<3, 3> Mat3;
		typedef Matrix<3, 2> Mat3x2;
		typedef Matrix<3, 4> Mat3x4;
		typedef Matrix<4, 4> Mat4;
		typedef Matrix<4, 2> Mat4x2;
		typedef Matrix<4, 3> Mat4x3;

		template<unsigned int width, unsigned int height>
		float* getMatrixData(Matrix<width, height>& matrix)
		{
			unsigned int size = width * height;
			float* result = new float[size];
			for (unsigned int i = 0; i < size; i++)
			{
				result[i] = matrix[i % width][i / height];
			}
			return result;
		}
	}
}

template<unsigned int width, unsigned int height>
bebr::math::Matrix<width, height>::Matrix()
{
	for (unsigned int i = 0; i < width; i++)
	{
		for (unsigned int j = 0; j < height; j++)
		{
			m_data[ i ][ j ] = static_cast<float>(i == j);
		}
	}
}

template<unsigned int width, unsigned int height>
bebr::math::Matrix<width, height>::Matrix( float value )
{
	for (unsigned int i = 0; i < width; i++)
	{
		for (unsigned int j = 0; j < height; j++)
		{
			m_data[ i ][ j ] = value;
		}
	}
}

template<unsigned int width, unsigned int height>
inline float* bebr::math::Matrix<width, height>::operator[]( unsigned int index )
{
	return m_data[ index ];
}

//template<unsigned int width, unsigned int height>
//inline float* const bebr::math::Matrix<width, height>::operator[]( unsigned int index ) const
//{
//	return m_data[ index ];
//}

template<unsigned int width, unsigned int height>
bebr::math::Matrix<width, height> bebr::math::Matrix<width, height>::operator+( const Matrix<width, height>& other ) const
{
	Matrix<width, height> result;
	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			result[ i ][ j ] = (*this)[ i ][ j ] + other[ i ][ j ];
		}
	}
	return result;
}

template<unsigned int width, unsigned int height>
bebr::math::Matrix<width, height>& bebr::math::Matrix<width, height>::operator+=( const Matrix<width, height>& other )
{
	*this = *this + other;
	return *this;
}

template<unsigned int width, unsigned int height>
bebr::math::Matrix<width, height> bebr::math::Matrix<width, height>::operator-( const Matrix<width, height>& other ) const
{
	Matrix<width, height> result;
	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			result[ i ][ j ] = (*this)[ i ][ j ] - other[ i ][ j ];
		}
	}
	return result;
}

template<unsigned int width, unsigned int height>
bebr::math::Matrix<width, height>& bebr::math::Matrix<width, height>::operator-=( const Matrix<width, height>& other )
{
	*this = *this - other;
	return *this;
}

template<unsigned int width, unsigned int height>
bebr::math::Matrix<width, height> bebr::math::Matrix<width, height>::operator*( float scalar ) const
{
	Matrix<width, height> result;
	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			result[ i ][ j ] = (*this)[ i ][ j ] * scalar;
		}
	}
	return result;
}

template<unsigned int width, unsigned int height>
bebr::math::Matrix<width, height>& bebr::math::Matrix<width, height>::operator*=( float scalar )
{
	*this = *this * scalar;
	return *this;
}

template<unsigned int width, unsigned int height>
bebr::math::Matrix<width, height> bebr::math::Matrix<width, height>::operator/( float scalar ) const
{
	Matrix<width, height> result;
	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			result[ i ][ j ] = (*this)[ i ][ j ] / scalar;
		}
	}
	return result;
}

template<unsigned int width, unsigned int height>
inline bebr::math::Matrix<width, height>& bebr::math::Matrix<width, height>::operator/=( float scalar )
{
	*this = *this / scalar;
	return *this;
}

template<unsigned int width, unsigned int height>
template<unsigned int pWidth>
bebr::math::Matrix<pWidth, height> bebr::math::Matrix<width, height>::operator*( const Matrix<pWidth, width>& other ) const
{
	Matrix<pWidth, height> result;

	for (unsigned int i = 0; i < height; ++i) {
		for (unsigned int j = 0; j < pWidth; ++j) {
			float sum = 0.0f;
			for (unsigned int k = 0; k < width; ++k) {
				sum += m_data[ k ][ i ] * other.m_data[ j ][ k ];
			}
			result[ j ][ i ] = sum;
		}
	}

	return result;
}

template<unsigned int width, unsigned int height>
template<unsigned int pWidth>
inline bebr::math::Matrix<width, height>& bebr::math::Matrix<width, height>::operator*=( const Matrix<pWidth, width>& other )
{
	*this = *this * other;
	return *this;
}

template<unsigned int width, unsigned int height>
bool bebr::math::Matrix<width, height>::operator==( const Matrix<width, height>& other ) const
{
	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			if ((*this)[ i ][ j ] != other[ i ][ j ])
			{
				return false;
			}
		}
	}
	return true;
}

template<unsigned int width, unsigned int height>
bool bebr::math::Matrix<width, height>::operator!=( const Matrix<width, height>& other ) const
{
	return !(*this == other);
}
