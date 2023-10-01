#pragma once
#include "../Math/Vector2.h"

namespace bebr
{
	namespace core
	{
		struct RectPro
		{
			math::Vector2f center;
			math::Vector2f size;
			float angle;

			RectPro();
			RectPro(math::Vector2f center, math::Vector2f size, float angle);
			RectPro(float centerX, float centerY, float width, float height, float angle);
		};
	}
}
