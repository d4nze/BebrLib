#include "Rect.h"

bebr::core::Rect::Rect() {}

bebr::core::Rect::Rect(float x, float y, float width, float height) : position{ x, y }, size{ width, height } {}

bebr::core::Rect::Rect(math::Vector2f position, math::Vector2f size) : position(position), size(size) {}

void bebr::core::NormalizeRectangle(Rect& rectangle, math::Vector2f size )
{
	NormalizeRectangle( rectangle, size.x, size.y );
}

void bebr::core::NormalizeRectangle(Rect& rectangle, float width, float height )
{
	rectangle.position.x /= width;
	rectangle.position.y /= height;
	rectangle.size.x /= width;
	rectangle.size.y /= height;
}
