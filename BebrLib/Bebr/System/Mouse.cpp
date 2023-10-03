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

void bebr::system::Mouse::setIcon( Icon icon ) { m_icon = icon; }

bebr::system::Mouse::Icon bebr::system::Mouse::getIcon() const { return m_icon; }

bebr::system::Mouse::Mouse() : m_icon( Arrow ) {}

void bebr::system::Mouse::updateIcon() const
{
	HCURSOR icon = nullptr;
	switch (m_icon)
	{
	case Icon::Arrow:
		icon = LoadCursor( nullptr, IDC_ARROW ); break;
	case Icon::ArrowLoad:
		icon = LoadCursor( nullptr, IDC_APPSTARTING ); break;
	case Icon::Wait:
		icon = LoadCursor( nullptr, IDC_WAIT ); break;
	case Icon::Hand:
		icon = LoadCursor( nullptr, IDC_HAND ); break;
	case Icon::Text:
		icon = LoadCursor( nullptr, IDC_IBEAM ); break;
	case Icon::Cross:
		icon = LoadCursor( nullptr, IDC_CROSS ); break;
	case Icon::ResizeX:
		icon = LoadCursor( nullptr, IDC_SIZEWE ); break;
	case Icon::ResizeY:
		icon = LoadCursor( nullptr, IDC_SIZENS ); break;
	case Icon::ResizeXY1:
		icon = LoadCursor( nullptr, IDC_SIZENWSE ); break;
	case Icon::ResizeXY2:
		icon = LoadCursor( nullptr, IDC_SIZENESW ); break;
	case Icon::Move:
		icon = LoadCursor( nullptr, IDC_SIZEALL ); break;
	case Icon::No:
		icon = LoadCursor(nullptr, IDC_NO); break;
	case Icon::Nothing:
		icon = nullptr; break;
	default:
		icon = LoadCursor( nullptr, IDC_ARROW ); break;
	}
	SetCursor( icon );
}
