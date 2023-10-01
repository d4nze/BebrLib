#include "RectColliderPro.h"

bebr::collision::RectColliderPro::RectColliderPro() : core::RectPro() {}

bebr::collision::RectColliderPro::RectColliderPro(const core::RectPro& rectPro) : core::RectPro(rectPro) {}

bebr::collision::RectColliderPro::RectColliderPro(const shape::Rectangle& rectangle) :
	core::RectPro(rectangle.getPosition(), rectangle.getSize(), rectangle.getAngle())
{
	math::Vector2f scale = rectangle.getScale();
	size.x *= scale.x;
	size.y *= scale.y;
}

bebr::collision::RectColliderPro::RectColliderPro(math::Vector2f center, math::Vector2f size, float angle) :
	core::RectPro(center, size, angle) {}

bebr::collision::RectColliderPro::RectColliderPro(float centerX, float centerY, float width, float height, float angle) :
	core::RectPro(centerX, centerY, width, height, angle) {}

#include "Bebr/Priv/Constants.h"
#include <math.h>

bool bebr::collision::RectColliderPro::collides(const RectCollider& collider) const
{
	// перевод градусов в радианты
	float rAngle = angle * DEG_TO_RAD;
	float sin = sinf(-rAngle);
	float cos = cosf(-rAngle);

	math::Vector2f halfSize = size / 2.f;
	math::Vector2f points[4] = {
		center - halfSize,
		center + math::Vector2f{ -halfSize.x, halfSize.y },
		center + math::Vector2f{ halfSize.x, -halfSize.y },
		center + halfSize,
	};

	// поворот точек
	for (math::Vector2f& point : points)
	{
		float x = (point.x - center.x) * cos - (point.y - center.y) * sin + center.x;
		float y = (point.x - center.x) * sin + (point.y - center.y) * cos + center.y;
		// проверка, есть ли точка в прямоугольнике
		if (collider.contains(x, y)) { return true; }
	}

	return false;
}

bool bebr::collision::RectColliderPro::collides(RectCollider rect, math::Vector2f velocity) const
{
	rect.position -= velocity;
	return collides(rect);
}

bool bebr::collision::RectColliderPro::collides(RectCollider rect, float moveX, float moveY) const
{
	rect.position.x -= moveX;
	rect.position.y -= moveY;
	return collides(rect);
}

bool bebr::collision::RectColliderPro::collides(const RectColliderPro& rect) const
{
	float rAngle = -angle * DEG_TO_RAD;
	float sin1 = sinf(rAngle);
	float cos1 = cosf(rAngle);
	rAngle = rect.angle * DEG_TO_RAD;
	float sin2 = sinf(rAngle);
	float cos2 = cosf(rAngle);

	math::Vector2f halfSize = size / 2.f;
	math::Vector2f points[4] = {
		center - halfSize,
		center + math::Vector2f{ -halfSize.x, halfSize.y },
		center + math::Vector2f{ halfSize.x, -halfSize.y },
		center + halfSize,
	};

	RectCollider pointChecker(rect.center - rect.size / 2.f, rect.size);

	for (math::Vector2f& point : points)
	{
		float x = (point.x - center.x) * cos1 - (point.y - center.y) * sin1 + center.x;
		float y = (point.x - center.x) * sin1 + (point.y - center.y) * cos1 + center.y;
		point.x = x; point.y = y;
		x = (point.x - rect.center.x) * cos2 - (point.y - rect.center.y) * sin2 + rect.center.x;
		y = (point.x - rect.center.x) * sin2 + (point.y - rect.center.y) * cos2 + rect.center.y;
		if (pointChecker.contains(x, y)) { return true; }
	}

	return false;
}

bool bebr::collision::RectColliderPro::collides(RectColliderPro rect, math::Vector2f velocity) const
{
	rect.center -= velocity;
	return collides(rect);
}

bool bebr::collision::RectColliderPro::collides(RectColliderPro rect, float moveX, float moveY) const
{
	rect.center.x -= moveX;
	rect.center.y -= moveY;
	return collides(rect);
}

bool bebr::collision::RectColliderPro::contains(float x, float y) const
{
	float rAngle = angle * DEG_TO_RAD;
	float sin = sinf(rAngle);
	float cos = cosf(rAngle);
	float tmp_x = (x - center.x) * cos - (y - center.y) * sin + center.x;
	float tmp_y = (x - center.x) * sin + (y - center.y) * cos + center.y;
	return RectCollider(center - size / 2.f, size).contains(tmp_x, tmp_y);
}
