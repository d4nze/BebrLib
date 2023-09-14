#include "AngleMatrix2.h"

bebr::transform::AngleMatrix2::AngleMatrix2() : m_angle( 0.f ) {}

bebr::transform::AngleMatrix2::AngleMatrix2( float angle ) { setAngle( angle ); }

void bebr::transform::AngleMatrix2::setAngle( float angle ) { m_angle = angle; }

float bebr::transform::AngleMatrix2::getAngle() const { return m_angle; }

void bebr::transform::AngleMatrix2::rotate( float rotation ) { setAngle( m_angle + rotation ); }

#define _USE_MATH_DEFINES
#include <math.h>

bebr::math::Mat4& bebr::transform::AngleMatrix2::getMatrix() const
{
	static math::Mat4 s_matrix;
	static float s_pi = M_PI;
	float angleDegrees = m_angle * s_pi / 180.f;
	float s = sinf( angleDegrees );
	float c = cosf( angleDegrees );
	s_matrix[ 0 ][ 0 ] = c;
	s_matrix[ 1 ][ 0 ] = s;
	s_matrix[ 0 ][ 1 ] = -s;
	s_matrix[ 1 ][ 1 ] = c;
	return s_matrix;
}
