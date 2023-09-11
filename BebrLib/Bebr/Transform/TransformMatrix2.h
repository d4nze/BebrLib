#pragma once
#include "AngleMatrix2.h"
#include "PositionMatrix2.h"
#include "ScaleMatrix2.h"

namespace bebr
{
	namespace transform
	{
		class TransformMatrix2 : public AngleMatrix2, public PositionMatrix2, public ScaleMatrix2
		{
		public:
			TransformMatrix2();
			TransformMatrix2( math::Vector2f position, float angle, math::Vector2f scale );

			math::Mat4& getMatrix() const; // TODO: make 'protected'
		};
	}
}
