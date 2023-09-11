#include "ScaleMatrix2.h"

bebr::transform::ScaleMatrix2::ScaleMatrix2() : m_x( 1.f ), m_y( 1.f ) {}

bebr::transform::ScaleMatrix2::ScaleMatrix2( float x, float y ) { setScale( x, y ); }

bebr::transform::ScaleMatrix2::ScaleMatrix2( math::Vector2f scale ) { setScale( scale ); }

void bebr::transform::ScaleMatrix2::setScale( float x, float y )
{
	m_x = x;
	m_y = y;
}

void bebr::transform::ScaleMatrix2::setScale( math::Vector2f scale )
{
	m_x = scale.x;
	m_y = scale.y;
}

bebr::math::Vector2f bebr::transform::ScaleMatrix2::getScale() const
{
	return { m_x, m_y };
}

bebr::math::Mat4& bebr::transform::ScaleMatrix2::getMatrix() const
{
	static math::Mat4 s_matrix;
	s_matrix[ 0 ][ 0 ] = m_x;
	s_matrix[ 1 ][ 1 ] = m_y;
	return s_matrix;
}
