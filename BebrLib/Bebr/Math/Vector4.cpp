#include "Vector4.h"

template<typename T>
bebr::math::Vector4<T>::Vector4() : x( static_cast<T>(0) ), y( static_cast<T>(0) ), z( static_cast<T>(0) ), w( static_cast<T>(0) ) {}

template<typename T>
bebr::math::Vector4<T>::Vector4( T x, T y, T z, T w ) : x( x ), y( y ), z( z ), w( w ) {}

template<typename T>
inline bebr::math::Vector4<T> bebr::math::Vector4<T>::operator+( const Vector4<T>& other ) const
{
    return Vector4<T>( x + other.x, y + other.y, z + other.z, w + other.w );
}

template<typename T>
inline bebr::math::Vector4<T> bebr::math::Vector4<T>::operator-( const Vector4<T>& other ) const
{
    return Vector4<T>( x - other.x, y - other.y, z - other.z, w - other.w );
}

template<typename T>
inline bebr::math::Vector4<T> bebr::math::Vector4<T>::operator*( T scalar ) const
{
    return Vector4<T>( x * scalar, y * scalar, z * scalar, w * scalar );
}

template<typename T>
inline bebr::math::Vector4<T> bebr::math::Vector4<T>::operator/( T scalar ) const
{
    return Vector4<T>( x / scalar, y / scalar, z / scalar, w / scalar );
}

template<typename T>
inline bebr::math::Vector4<T>& bebr::math::Vector4<T>::operator+=( const Vector4<T>& other )
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

template<typename T>
inline bebr::math::Vector4<T>& bebr::math::Vector4<T>::operator-=( const Vector4<T>& other )
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

template<typename T>
inline bebr::math::Vector4<T>& bebr::math::Vector4<T>::operator*=( T scalar )
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

template<typename T>
inline bebr::math::Vector4<T>& bebr::math::Vector4<T>::operator/=( T scalar )
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}

template<typename T>
inline bool bebr::math::Vector4<T>::operator==( const Vector4<T>& other ) const
{
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

template<typename T>
inline bool bebr::math::Vector4<T>::operator!=( const Vector4<T>& other ) const
{
    return !(*this == other);
}

#include "Bebr/Priv/Macroses.h"

TEMPLATE_STRUCT( bebr::math::Vector4 );
