#include "PositionMatrix2.h"

bebr::transform::PositionMatrix2::PositionMatrix2() : m_x( 0.f ), m_y( 0.f ) {}

bebr::transform::PositionMatrix2::PositionMatrix2( float x, float y ) { setPosition( x, y ); }

bebr::transform::PositionMatrix2::PositionMatrix2( math::Vector2f position ) { setPosition( position ); }

void bebr::transform::PositionMatrix2::setPosition( float x, float y )
{
	m_x = x;
	m_y = y;
}

void bebr::transform::PositionMatrix2::setPosition( math::Vector2f position )
{
	m_x = position.x;
	m_y = position.y;
}

bebr::math::Vector2f bebr::transform::PositionMatrix2::getPosition() const
{
	return { m_x, m_y };
}

void bebr::transform::PositionMatrix2::move( float x, float y )
{
	m_x += x;
	m_y += y;
}

void bebr::transform::PositionMatrix2::move( math::Vector2f velocity )
{
	m_x += velocity.x;
	m_y += velocity.y;
}

bebr::math::Mat4& bebr::transform::PositionMatrix2::getMatrix() const
{
	static bebr::math::Mat4 s_matrix;
	s_matrix[ 3 ][ 0 ] = m_x;
	s_matrix[ 3 ][ 1 ] = m_y;
	return s_matrix;
}
