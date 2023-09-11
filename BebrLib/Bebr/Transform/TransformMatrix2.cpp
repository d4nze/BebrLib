#include "TransformMatrix2.h"

bebr::transform::TransformMatrix2::TransformMatrix2() : AngleMatrix2(), PositionMatrix2(), ScaleMatrix2() {}

bebr::transform::TransformMatrix2::TransformMatrix2( math::Vector2f position, float angle, math::Vector2f scale ) :
	AngleMatrix2( angle ), PositionMatrix2( position ), ScaleMatrix2( scale ) {}

bebr::math::Mat4& bebr::transform::TransformMatrix2::getMatrix() const
{
	static math::Mat4 s_matrix;
	s_matrix = PositionMatrix2::getMatrix(); 
	s_matrix *= ScaleMatrix2::getMatrix(); 
	s_matrix *= AngleMatrix2::getMatrix();
	return s_matrix;
}