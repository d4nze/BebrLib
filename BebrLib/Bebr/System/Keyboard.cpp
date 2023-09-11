#include "Keyboard.h"

bebr::system::Keyboard& bebr::system::Keyboard::GetInstance()
{
	static Keyboard s_keyboard;
	return s_keyboard;
}

bool bebr::system::Keyboard::isKeyPressed( Key key ) const
{
	return m_keyStates[ static_cast<unsigned int>(key) ] == Pressed;
}

bool bebr::system::Keyboard::isKeyDown( Key key ) const
{
	return m_keyStates[ static_cast<unsigned int>(key) ] == Down;
}

bool bebr::system::Keyboard::isKeyReleased( Key key ) const
{
	return m_keyStates[ static_cast<unsigned int>(key) ] == Released;
}

bool bebr::system::Keyboard::isKeyUp( Key key ) const
{
	return m_keyStates[ static_cast<unsigned int>(key) ] == Up;
}

void bebr::system::Keyboard::update()
{
	for (unsigned int i = 0; i < KEYBOARD_TOTAL_KEYS; i++)
	{
		if (m_keyStates[ i ] == Pressed) { m_keyStates[ i ] = Down; }
		else if (m_keyStates[ i ] == Released) { m_keyStates[ i ] = Up; }
	}
}

void bebr::system::Keyboard::setKeyState( Key key, KeyState state )
{
	m_keyStates[ key ] = state;
}

bebr::system::Keyboard::KeyState bebr::system::Keyboard::getKeyState( Key key )
{
	return m_keyStates[ key ];
}

bebr::system::Keyboard::Keyboard()
{
	for (unsigned int i = 0; i < KEYBOARD_TOTAL_KEYS; i++) { m_keyStates[ i ] = Up; }
}
