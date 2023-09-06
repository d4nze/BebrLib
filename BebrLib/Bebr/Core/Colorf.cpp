#include "Colorf.h"
#include "Coloru.h"

bebr::core::Colorf::Colorf() : r( 0.f ), g( 0.f ), b( 0.f ), a( 1.f ) {}

bebr::core::Colorf::Colorf( const Colorf& copy ) : r( copy.r ), g( copy.g ), b( copy.b ), a( copy.a ) {}

bebr::core::Colorf::Colorf( const core::Coloru& copy ) : 
	r( static_cast<float>( copy.r ) / 255.f ), 
	g( static_cast<float>( copy.g ) / 255.f ), 
	b( static_cast<float>( copy.b ) / 255.f ), 
	a( static_cast<float>( copy.a ) / 255.f ) {}

#include <algorithm>

bebr::core::Colorf::Colorf( float r, float g, float b, float a ) : 
    r( std::max( std::min( r, 1.f ), 0.f ) ), 
    g( std::max( std::min( g, 1.f ), 0.f ) ), 
    b( std::max( std::min( b, 1.f ), 0.f ) ), 
    a( std::max( std::min( a, 1.f ), 0.f ) ) {}

inline bebr::core::Colorf bebr::core::Colorf::operator+( const Colorf& other ) const
{
    return { r + other.r, g + other.g, b + other.b, a + other.a };
}

inline bebr::core::Colorf bebr::core::Colorf::operator-( const Colorf& other ) const
{
    return { r - other.r, g - other.g, b - other.b, a - other.a };
}

inline bebr::core::Colorf bebr::core::Colorf::operator*( float scalar ) const
{
    return { r * scalar, g * scalar, b * scalar, a * scalar };
}

inline bebr::core::Colorf bebr::core::Colorf::operator/( float scalar ) const
{
    return { r / scalar, g / scalar, b / scalar, a / scalar };
}

inline bebr::core::Colorf& bebr::core::Colorf::operator+=( const Colorf& other )
{
    r += other.r;
    g += other.g;
    b += other.b;
    a += other.a;
    return *this;
}

inline bebr::core::Colorf& bebr::core::Colorf::operator-=( const Colorf& other )
{
    r -= other.r;
    g -= other.g;
    b -= other.b;
    a -= other.a;
    return *this;
}

inline bebr::core::Colorf& bebr::core::Colorf::operator*=( float scalar )
{
    r *= scalar;
    g *= scalar;
    b *= scalar;
    a *= scalar;
    return *this;
}

inline bebr::core::Colorf& bebr::core::Colorf::operator/=( float scalar )
{
    r /= scalar;
    g /= scalar;
    b /= scalar;
    a /= scalar;
    return *this;
}

inline bool bebr::core::Colorf::operator==( const Colorf& other ) const
{
    return r == other.r && g == other.g && b == other.b && a == other.a;
}

inline bool bebr::core::Colorf::operator!=( const Colorf& other ) const
{
    return !(*this == other);
}

namespace bebr
{
    namespace core
    {
        const Colorf Colorf::White = { 1.0f, 1.0f, 1.0f, 1.0f };
        const Colorf Colorf::Black = { 0.0f, 0.0f, 0.0f, 1.0f };

        const Colorf Colorf::Red = { 1.0f, 0.0f, 0.0f, 1.0f };
        const Colorf Colorf::Green = { 0.0f, 1.0f, 0.0f, 1.0f };
        const Colorf Colorf::Blue = { 0.0f, 0.0f, 1.0f, 1.0f };

        const Colorf Colorf::DarkRed = { 0.25f, 0.0f, 0.0f, 1.0f };
        const Colorf Colorf::DarkGreen = { 0.0f, 0.25f, 0.0f, 1.0f };
        const Colorf Colorf::DarkBlue = { 0.0f, 0.0f, 0.25f, 1.0f };

        const Colorf Colorf::Orange = { 1.0f, 0.5f, 0.0f, 1.0f };
        const Colorf Colorf::Purple = { 0.5f, 0.0f, 0.5f, 1.0f };
        const Colorf Colorf::Yellow = { 1.0f, 1.0f, 0.0f, 1.0f };
        const Colorf Colorf::Cyan = { 0.0f, 1.0f, 1.0f, 1.0f };
        const Colorf Colorf::Magenta = { 1.0f, 0.0f, 1.0f, 1.0f };
        const Colorf Colorf::Pink = { 1.0f, 0.75f, 0.8f, 1.0f };
        const Colorf Colorf::Teal = { 0.0f, 0.5f, 0.5f, 1.0f };
        const Colorf Colorf::Lime = { 0.0f, 1.0f, 0.0f, 1.0f };
        const Colorf Colorf::Brown = { 0.6f, 0.4f, 0.2f, 1.0f };
        const Colorf Colorf::Gold = { 1.0f, 0.84f, 0.0f, 1.0f };
    }
}
