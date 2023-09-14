#include "RectangleData.h"

void bebr::core::NormalizeRectangle( RectangleData& rectangle, math::Vector2f size )
{
	NormalizeRectangle( rectangle, size.x, size.y );
}

void bebr::core::NormalizeRectangle( RectangleData& rectangle, float width, float height )
{
	rectangle.position.x /= width;
	rectangle.position.y /= height;
	rectangle.size.x /= width;
	rectangle.size.y /= height;
}
