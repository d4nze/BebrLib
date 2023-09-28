#include "RectCollider.h"

bebr::collision::RectCollider::RectCollider() : core::Rect{ { 0.f, 0.f }, { 0.f, 0.f } } {}

bebr::collision::RectCollider::RectCollider( shape::Rectangle& rectangle ) :
	core::Rect{ rectangle.getPosition() - rectangle.getOrigin(), rectangle.getSize() }
{
	math::Vector2f scale = rectangle.getScale();
	size.x *= scale.x;
	size.y *= scale.y;
}

bebr::collision::RectCollider::RectCollider( float x, float y, float width, float height ) :
	core::Rect{ { x, y }, { width, height } } {}

bebr::collision::RectCollider::RectCollider( math::Vector2f position, math::Vector2f size ) :
	core::Rect{ position, size } {}

bool bebr::collision::RectCollider::operator()( RectCollider& other )
{
	return position.x + size.x >= other.position.x
		&& position.x <= other.position.x + other.size.x
		&& position.y + size.y >= other.position.y
		&& position.y <= other.position.y + other.size.y;
}

bool bebr::collision::RectCollider::operator()( RectCollider other, math::Vector2f velocity )
{
	other.position -= velocity;
	return (*this)(other);
}

bool bebr::collision::RectCollider::operator()( RectCollider other, float moveX, float moveY )
{
	other.position.x -= moveX;
	other.position.y -= moveY;
	return (*this)(other);
}

void bebr::collision::RectCollider::operator=( shape::Rectangle& rectangle )
{
	position = rectangle.getPosition() - rectangle.getOrigin();
	size = rectangle.getSize();
	math::Vector2f scale = rectangle.getScale();
	size.x *= scale.x;
	size.y *= scale.y;
}
