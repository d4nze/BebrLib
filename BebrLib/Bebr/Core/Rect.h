#pragma once
#include "../Math/Vector2.h"

namespace bebr
{
	namespace core
	{
		struct Rect
		{
			math::Vector2f position;
			math::Vector2f size;

			Rect();
			Rect(float x, float y, float width, float height);
			Rect(math::Vector2f position, math::Vector2f size);
		};

		void NormalizeRectangle( Rect& rectangle, math::Vector2f size );
		void NormalizeRectangle( Rect& rectangle, float width, float height );
	}
}
