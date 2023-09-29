#include "TransformMatrix2.h"

bebr::transform::TransformMatrix2::TransformMatrix2() : AngleMatrix2(), PositionMatrix2(), ScaleMatrix2() {}

bebr::transform::TransformMatrix2::TransformMatrix2( math::Vector2f position, float angle, math::Vector2f scale, math::Vector2f origin ) :
	AngleMatrix2( angle ), PositionMatrix2( position ), ScaleMatrix2( scale ), OriginMatrix2( origin ) {}

bebr::math::Mat4& bebr::transform::TransformMatrix2::getMatrix() const
{
	static math::Mat4 s_matrix;
	s_matrix = PositionMatrix2::getMatrix();
	s_matrix *= AngleMatrix2::getMatrix();
	s_matrix *= OriginMatrix2::getMatrix();
	s_matrix *= ScaleMatrix2::getMatrix();
	return s_matrix;
}
