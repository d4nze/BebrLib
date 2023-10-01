#pragma once
#include "../Core/RectPro.h"
#include "../Shape/Rectangle.h"
#include "../Collision/RectCollider.h"

namespace bebr
{
	namespace collision
	{
		class RectColliderPro : public core::RectPro
		{
		public:
			RectColliderPro();
			RectColliderPro(const core::RectPro& rectPro);
			RectColliderPro(const shape::Rectangle& rectangle);
			RectColliderPro(math::Vector2f center, math::Vector2f size, float angle);
			RectColliderPro(float centerX, float centerY, float width, float height, float angle);

			bool collides(const RectCollider& rect) const;
			bool collides(RectCollider rect, math::Vector2f velocity) const;
			bool collides(RectCollider rect, float moveX, float moveY) const;

			bool collides(const RectColliderPro& rect) const;
			bool collides(RectColliderPro rect, math::Vector2f velocity) const;
			bool collides(RectColliderPro rect, float moveX, float moveY) const;

			bool contains(float x, float y) const;
			bool contains(math::Vector2f point) const;
		};
	}
}
