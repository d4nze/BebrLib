#pragma once
#include "../Core/Rect.h"
#include "../Shape/Rectangle.h"
//#include "RectColliderPro.h"

namespace bebr
{
	namespace collision
	{
		class RectCollider : public core::Rect
		{
		public:
			RectCollider();
			RectCollider(const core::Rect& rect);
			RectCollider( shape::Rectangle& rectangle );
			RectCollider( float x, float y, float width, float height );
			RectCollider( math::Vector2f position, math::Vector2f size );

			bool collides( Rect& other ) const;
			bool collides( Rect other, math::Vector2f velocity ) const;
			bool collides( Rect other, float moveX, float moveY ) const;

			bool contains(float x, float y) const;
			bool contains(math::Vector2f point) const;
		};
	}
}
