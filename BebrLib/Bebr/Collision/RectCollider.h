#pragma once
#include "../Core/RectangleData.h"
#include "../Shape/Rectangle.h"

namespace bebr
{
	namespace collision
	{
		class RectCollider : public core::RectangleData
		{
		public:
			RectCollider();
			RectCollider( shape::Rectangle& rectangle );
			RectCollider( float x, float y, float width, float height );
			RectCollider( math::Vector2f position, math::Vector2f size );

			bool operator()( RectCollider& other );
			bool operator()( RectCollider other, math::Vector2f velocity );
			bool operator()( RectCollider other, float moveX, float moveY );

			void operator=( shape::Rectangle& rectangle );
		};
	}
}
