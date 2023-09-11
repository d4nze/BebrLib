#pragma once

#define KEYBOARD_TOTAL_KEYS 512u

namespace bebr
{
    namespace system
    {
        class Window;

        class Keyboard
        {
        public:
            static Keyboard& GetInstance();

            enum Key
            {
                A = 0x41, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
                Num0 = 0x30, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
                Shift = 0x10, Control, Alt, Pause, CapsLock, Esc = 0x1B,
                Space = 0x20, PageUp, PageDown, End, Home, LeftArrow, UpArrow, RightArrow, DownArrow,
                PrintScreen, Insert, Delete,
                NumLock = 0x90, ScrollLock, LShift = 0xA0, RShift, LControl, RControl, LAlt = 0xA4, RAlt,
                Semicolon = 0xBA, Plus = 0xBB, Comma = 0xBC, Minus = 0xBD, Period = 0xBE, Slash = 0xBF,
                Tilde = 0xC0, LBracket = 0xDB, Backslash = 0xDC, RBracket = 0xDD, Quote = 0xDE,
                F1 = 0x70, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, F16, F17, F18, F19,
                F20, F21, F22, F23, F24
            };
            bool isKeyPressed( Key key ) const;
            bool isKeyDown( Key key ) const;
            bool isKeyReleased( Key key ) const;
            bool isKeyUp( Key key ) const;

            void update();

        private:
            enum KeyState { Pressed = 0x01, Down, Released, Up };
            void setKeyState( Key key, KeyState state );
            KeyState getKeyState( Key key );

            Keyboard();

            KeyState m_keyStates[ KEYBOARD_TOTAL_KEYS ];

            friend class Window;
        };
    }
}
