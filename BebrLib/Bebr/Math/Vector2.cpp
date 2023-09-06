#include "Vector2.h"

template<typename T>
bebr::math::Vector2<T>::Vector2() : x( static_cast<T>(0) ), y( static_cast<T>(0) ) {}

template<typename T>
bebr::math::Vector2<T>::Vector2( T x, T y ) : x( x ), y( y ) {}

template<typename T>
inline bebr::math::Vector2<T> bebr::math::Vector2<T>::operator+( const Vector2<T>& other ) const
{
    return Vector2<T>( x + other.x, y + other.y );
}

template<typename T>
inline bebr::math::Vector2<T> bebr::math::Vector2<T>::operator-( const Vector2<T>& other ) const
{
    return Vector2<T>( x - other.x, y - other.y );
}

template<typename T>
inline bebr::math::Vector2<T> bebr::math::Vector2<T>::operator*( T scalar ) const
{
    return Vector2<T>( x * scalar, y * scalar );
}

template<typename T>
inline bebr::math::Vector2<T> bebr::math::Vector2<T>::operator/( T scalar ) const
{
    return Vector2<T>( x / scalar, y / scalar );
}

template<typename T>
inline bebr::math::Vector2<T>& bebr::math::Vector2<T>::operator+=( const Vector2<T>& other )
{
    x += other.x;
    y += other.y;
    return *this;
}

template<typename T>
inline bebr::math::Vector2<T>& bebr::math::Vector2<T>::operator-=( const Vector2<T>& other )
{
    x -= other.x;
    y -= other.y;
    return *this;
}

template<typename T>
inline bebr::math::Vector2<T>& bebr::math::Vector2<T>::operator*=( T scalar )
{
    x *= scalar;
    y *= scalar;
    return *this;
}

template<typename T>
inline bebr::math::Vector2<T>& bebr::math::Vector2<T>::operator/=( T scalar )
{
    x /= scalar;
    y /= scalar;
    return *this;
}

template<typename T>
inline bool bebr::math::Vector2<T>::operator==( const Vector2<T>& other ) const
{
    return x == other.x && y == other.y;
}

template<typename T>
inline bool bebr::math::Vector2<T>::operator!=( const Vector2<T>& other ) const
{
    return !(*this == other);
}

#include "Bebr/Priv/Macroses.h"

TEMPLATE_STRUCT( bebr::math::Vector2 );
