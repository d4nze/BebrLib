#include "OriginMatrix2.h"

bebr::transform::OriginMatrix2::OriginMatrix2() : m_x( 0.f ), m_y( 0.f ) {}

bebr::transform::OriginMatrix2::OriginMatrix2( float x, float y ) { setOrigin( x, y ); }

bebr::transform::OriginMatrix2::OriginMatrix2( math::Vector2f offset ) { setOrigin( offset ); }

void bebr::transform::OriginMatrix2::setOrigin( float x, float y )
{
    m_x = x;
    m_y = y;
}

void bebr::transform::OriginMatrix2::setOrigin( math::Vector2f offset )
{
    m_x = offset.x;
    m_y = offset.y;
}

bebr::math::Vector2f bebr::transform::OriginMatrix2::getOrigin() const
{
    return { m_x, m_y };
}

bebr::math::Mat4& bebr::transform::OriginMatrix2::getMatrix() const
{
    static math::Mat4 s_matrix;
    s_matrix[ 3 ][ 0 ] = -m_x;
    s_matrix[ 3 ][ 1 ] = -m_y;
    return s_matrix;
}
