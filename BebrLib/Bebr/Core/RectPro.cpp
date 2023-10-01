#include "RectPro.h"

bebr::core::RectPro::RectPro() : angle(0.f) {}

bebr::core::RectPro::RectPro(math::Vector2f center, math::Vector2f size, float angle) : center(center), size(size), angle(angle) {}

bebr::core::RectPro::RectPro(float centerX, float centerY, float width, float height, float angle) :
	center{ centerX, centerY }, size{ width, height }, angle(angle) {}
