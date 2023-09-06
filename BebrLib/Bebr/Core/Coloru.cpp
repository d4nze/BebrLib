#include "Coloru.h"
#include "Colorf.h"

bebr::core::Coloru::Coloru() : r( 0u ), g( 0u ), b( 0u ), a( 0u ) {}

bebr::core::Coloru::Coloru( const Coloru& copy ) : r( copy.r ), g( copy.g ), b( copy.b ), a( copy.a ) {}

bebr::core::Coloru::Coloru( const Colorf& copy ) :
	r( static_cast<uint8_t>(copy.r * 255.f) ),
	g( static_cast<uint8_t>(copy.g * 255.f) ),
	b( static_cast<uint8_t>(copy.b * 255.f) ),
	a( static_cast<uint8_t>(copy.a * 255.f) ) {}

bebr::core::Coloru::Coloru( uint8_t r, uint8_t g, uint8_t b, uint8_t a ) : r( r ), g( g ), b( b ), a( a ) {}

inline bebr::core::Coloru bebr::core::Coloru::operator+( const Coloru& other ) const
{
    return { static_cast<uint8_t>(r + other.r), static_cast<uint8_t>(g + other.g),
             static_cast<uint8_t>(b + other.b), static_cast<uint8_t>(a + other.a) };
}

inline bebr::core::Coloru bebr::core::Coloru::operator-( const Coloru& other ) const
{
    return { static_cast<uint8_t>(r - other.r), static_cast<uint8_t>(g - other.g),
             static_cast<uint8_t>(b - other.b), static_cast<uint8_t>(a - other.a) };
}

inline bebr::core::Coloru bebr::core::Coloru::operator*( uint8_t scalar ) const
{
    return { static_cast<uint8_t>(r * scalar), static_cast<uint8_t>(g * scalar), static_cast<uint8_t>(b * scalar), static_cast<uint8_t>(a * scalar) };
}

inline bebr::core::Coloru bebr::core::Coloru::operator/( uint8_t scalar ) const
{
    return { static_cast<uint8_t>(r / scalar), static_cast<uint8_t>(g / scalar), static_cast<uint8_t>(b / scalar), static_cast<uint8_t>(a / scalar) };
}

inline bebr::core::Coloru& bebr::core::Coloru::operator+=( const Coloru& other )
{
    r = static_cast<uint8_t>(r + other.r);
    g = static_cast<uint8_t>(g + other.g);
    b = static_cast<uint8_t>(b + other.b);
    a = static_cast<uint8_t>(a + other.a);
    return *this;
}

inline bebr::core::Coloru& bebr::core::Coloru::operator-=( const Coloru& other )
{
    r = static_cast<uint8_t>(r - other.r);
    g = static_cast<uint8_t>(g - other.g);
    b = static_cast<uint8_t>(b - other.b);
    a = static_cast<uint8_t>(a - other.a);
    return *this;
}

inline bebr::core::Coloru& bebr::core::Coloru::operator*=( uint8_t scalar )
{
    r = static_cast<uint8_t>(r * scalar);
    g = static_cast<uint8_t>(g * scalar);
    b = static_cast<uint8_t>(b * scalar);
    a = static_cast<uint8_t>(a * scalar);
    return *this;
}

inline bebr::core::Coloru& bebr::core::Coloru::operator/=( uint8_t scalar )
{
    r = static_cast<uint8_t>(r / scalar);
    g = static_cast<uint8_t>(g / scalar);
    b = static_cast<uint8_t>(b / scalar);
    a = static_cast<uint8_t>(a / scalar);
    return *this;
}

inline bool bebr::core::Coloru::operator==( const Coloru& other ) const
{
    return r == other.r && g == other.g && b == other.b && a == other.a;
}

inline bool bebr::core::Coloru::operator!=( const Coloru& other ) const
{
    return !(*this == other);
}

namespace bebr
{
    namespace core
    {
        const Coloru Coloru::White = Coloru( Colorf::White );
        const Coloru Coloru::Black = Coloru( Colorf::Black );
        const Coloru Coloru::Red = Coloru( Colorf::Red );
        const Coloru Coloru::Green = Coloru( Colorf::Green );
        const Coloru Coloru::Blue = Coloru( Colorf::Blue );
        const Coloru Coloru::Orange = Coloru( Colorf::Orange );
        const Coloru Coloru::Purple = Coloru( Colorf::Purple );
        const Coloru Coloru::Yellow = Coloru( Colorf::Yellow );
        const Coloru Coloru::Cyan = Coloru( Colorf::Cyan );
        const Coloru Coloru::Magenta = Coloru( Colorf::Magenta );
        const Coloru Coloru::Pink = Coloru( Colorf::Pink );
        const Coloru Coloru::Teal = Coloru( Colorf::Teal );
        const Coloru Coloru::Lime = Coloru( Colorf::Lime );
        const Coloru Coloru::Brown = Coloru( Colorf::Brown );
        const Coloru Coloru::Gold = Coloru( Colorf::Gold );
    }
}
