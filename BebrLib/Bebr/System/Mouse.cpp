#include "Mouse.h"

bebr::system::Mouse& bebr::system::Mouse::GetInstance()
{
	static Mouse s_mouse;
	return s_mouse;
}

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

void bebr::system::Mouse::setPosition(int x, int y) const { SetCursorPos(x, -y); }

void bebr::system::Mouse::setPosition(math::Vector2i position) const { SetCursorPos(position.x, -position.y); }

bebr::math::Vector2i bebr::system::Mouse::getPosition() const 
{
	POINT mousePos = { 0, 0 };
	GetCursorPos(&mousePos);
	return { mousePos.x, -mousePos.y };
}

#include "Window.h"

void bebr::system::Mouse::setPosition(int x, int y, const Window& window) const
{
	POINT mousePos = { x, y };
	ClientToScreen(window.m_hWnd, &mousePos);
	SetCursorPos(mousePos.x, -mousePos.y);
}

void bebr::system::Mouse::setPosition(math::Vector2i position, const Window& window) const
{
	POINT mousePos = { position.x, position.y };
	ClientToScreen(window.m_hWnd, &mousePos);
	SetCursorPos(mousePos.x, -mousePos.y);
}

bebr::math::Vector2i bebr::system::Mouse::getPosition(const Window& window) const
{
	POINT mousePos = { 0, 0 };
	GetCursorPos(&mousePos);
	ScreenToClient(window.m_hWnd, &mousePos);
	return { mousePos.x, -mousePos.y };
}

void bebr::system::Mouse::setVisible( bool visible ) { m_visible = visible; }

bool bebr::system::Mouse::getVisible() const { return m_visible; }

void bebr::system::Mouse::setIcon( Icon icon )
{
	m_icon = icon;
}

bebr::system::Mouse::Icon bebr::system::Mouse::getIcon() const { return m_icon; }

bebr::system::Mouse::Mouse() : m_visible( true ), m_icon( Arrow ) {}

void bebr::system::Mouse::updateIcon() const
{
	if (!m_visible) 
	{ 
		SetCursor(nullptr);
		return;
	}
	HCURSOR icon = nullptr;
	switch (m_icon)
	{
	case Icon::Arrow:
		icon = LoadCursor(nullptr, IDC_ARROW); break;
	case Icon::Loading:
		icon = LoadCursor(nullptr, IDC_WAIT); break;
	case Icon::Select:
		icon = LoadCursor(nullptr, IDC_HAND); break;
	default:
		icon = LoadCursor(nullptr, IDC_ARROW); break;
	}
	SetCursor(icon);
}
