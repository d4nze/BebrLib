#include "OriginMatrix.h"

bebr::transform::OriginMatrix::OriginMatrix() : m_x( 0.f ), m_y( 0.f ) {}

bebr::transform::OriginMatrix::OriginMatrix( float x, float y ) { setOrigin( x, y ); }

bebr::transform::OriginMatrix::OriginMatrix( math::Vector2f offset ) { setOrigin( offset ); }

void bebr::transform::OriginMatrix::setOrigin( float x, float y )
{
    m_x = x;
    m_y = y;
}

void bebr::transform::OriginMatrix::setOrigin( math::Vector2f offset )
{
    m_x = offset.x;
    m_y = offset.y;
}

bebr::math::Vector2f bebr::transform::OriginMatrix::getOrigin() const
{
    return { m_x, m_y };
}

bebr::math::Mat4& bebr::transform::OriginMatrix::getMatrix() const
{
    static math::Mat4 s_matrix;
    s_matrix[ 3 ][ 0 ] = -m_x;
    s_matrix[ 3 ][ 1 ] = -m_y;
    return s_matrix;
}
