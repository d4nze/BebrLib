#pragma once
#include "../Math/Vector2.h"

namespace bebr
{
	namespace core
	{
		struct RectangleData
		{
			math::Vector2f position;
			math::Vector2f size;
		};

		void NormalizeRectangle( RectangleData& rectangle, math::Vector2f size );
		void NormalizeRectangle( RectangleData& rectangle, float width, float height );
	}
}
