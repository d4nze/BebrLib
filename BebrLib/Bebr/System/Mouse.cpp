#include "Mouse.h"

bebr::system::Mouse& bebr::system::Mouse::GetInstance()
{
	static Mouse s_mouse;
	return s_mouse;
}

bebr::math::Vector2i bebr::system::Mouse::getPosition() const { return { m_x, m_y }; }

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

void bebr::system::Mouse::setVisible( bool visible ) { m_visible = visible; }

bool bebr::system::Mouse::getVisible() const { return m_visible; }

bebr::system::Mouse::Mouse() : m_x( 0 ), m_y( 0 ), m_visible( true ) {}
