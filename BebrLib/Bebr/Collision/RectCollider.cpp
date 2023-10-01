#include "RectCollider.h"

bebr::collision::RectCollider::RectCollider() : core::Rect{ { 0.f, 0.f }, { 0.f, 0.f } } {}

bebr::collision::RectCollider::RectCollider(const core::Rect& rect) : core::Rect(rect) {}

bebr::collision::RectCollider::RectCollider( shape::Rectangle& rectangle ) :
	core::Rect{ rectangle.getPosition(), rectangle.getSize() }
{
	position -= rectangle.getOrigin();
	math::Vector2f scale = rectangle.getScale();
	size.x *= scale.x;
	size.y *= scale.y;
}

bebr::collision::RectCollider::RectCollider( float x, float y, float width, float height ) :
	core::Rect{ { x, y }, { width, height } } {}

bebr::collision::RectCollider::RectCollider( math::Vector2f position, math::Vector2f size ) :
	core::Rect{ position, size } {}

bool bebr::collision::RectCollider::collides( Rect& other ) const
{
	return position.x + size.x >= other.position.x
		&& position.x <= other.position.x + other.size.x
		&& position.y + size.y >= other.position.y
		&& position.y <= other.position.y + other.size.y;
}

bool bebr::collision::RectCollider::collides(Rect other, math::Vector2f velocity ) const
{
	other.position -= velocity;
	return collides(other);
}

bool bebr::collision::RectCollider::collides(Rect other, float moveX, float moveY ) const
{
	other.position.x -= moveX;
	other.position.y -= moveY;
	return collides(other);
}

bool bebr::collision::RectCollider::contains(float x, float y) const
{
	return x >= position.x && x <= position.x + size.x
		&& y >= position.y && y <= position.y + size.y;
}

bool bebr::collision::RectCollider::contains(math::Vector2f point) const
{
	return point.x >= position.x && point.x <= position.x + size.x
		&& point.y >= position.y && point.y <= position.y + size.y;
}
