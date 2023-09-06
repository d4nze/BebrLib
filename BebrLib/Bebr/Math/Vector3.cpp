#include "Vector3.h"

template<typename T>
bebr::math::Vector3<T>::Vector3() : x( static_cast<T>(0) ), y( static_cast<T>(0) ), z( static_cast<T>(0) ) {}

template<typename T>
bebr::math::Vector3<T>::Vector3( T x, T y, T z ) : x( x ), y( y ), z( z ) {}

template<typename T>
inline bebr::math::Vector3<T> bebr::math::Vector3<T>::operator+( const Vector3<T>& other ) const
{
	return Vector3<T>( x + other.x, y + other.y, z + other.z );
}

template<typename T>
inline bebr::math::Vector3<T> bebr::math::Vector3<T>::operator-( const Vector3<T>& other ) const
{
    return Vector3<T>( x - other.x, y - other.y, z - other.z );
}

template<typename T>
inline bebr::math::Vector3<T> bebr::math::Vector3<T>::operator*( T scalar ) const
{
    return Vector3<T>( x * scalar, y * scalar, z * scalar );
}

template<typename T>
inline bebr::math::Vector3<T> bebr::math::Vector3<T>::operator/( T scalar ) const
{
    return Vector3<T>( x / scalar, y / scalar, z / scalar );
}

template<typename T>
inline bebr::math::Vector3<T>& bebr::math::Vector3<T>::operator+=( const Vector3<T>& other )
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template<typename T>
inline bebr::math::Vector3<T>& bebr::math::Vector3<T>::operator-=( const Vector3<T>& other )
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template<typename T>
inline bebr::math::Vector3<T>& bebr::math::Vector3<T>::operator*=( T scalar )
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

template<typename T>
inline bebr::math::Vector3<T>& bebr::math::Vector3<T>::operator/=( T scalar )
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

template<typename T>
inline bool bebr::math::Vector3<T>::operator==( const Vector3<T>& other ) const
{
    return x == other.x && y == other.y && z == other.z;
}

template<typename T>
inline bool bebr::math::Vector3<T>::operator!=( const Vector3<T>& other ) const
{
    return !(*this == other);
}

#include "Bebr/Priv/Macroses.h"

TEMPLATE_STRUCT( bebr::math::Vector3 );
