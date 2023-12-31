#pragma once

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32
#include <chrono>
#include "../Math/Vector2.h"

namespace bebr
{
    namespace render { class Renderer; }
    namespace system
    {
        class Mouse;
        class Window {
        public:
            Window( int width, int height, const char* title );
            ~Window();

            void setSize( math::Vector2i size );
            void setSize( int width, int height );
            void setTitle( const char* title );
            void setMaxFrameRate( unsigned int maxFPS );
            void setFullscreen( bool fullscreen );

            math::Vector2i getSize() const;
            const char* getTitle() const;
            bool isOpen() const;
            unsigned int getMaxFrameRate() const;
            bool getFullscreen() const;

            void pollEvent();
            void close() const;

        private:
            void makeCurrent() const;
            void swapBuffers() const;

            static LRESULT CALLBACK WindowProc( HWND, UINT, WPARAM, LPARAM );

            HWND m_hWnd;
            HDC m_hDC;
            HGLRC m_hRC;

            int m_width, m_height;
            const char* m_title;

            unsigned int m_fpsLimit;
            std::chrono::high_resolution_clock::time_point m_lastFrameTime;

            static const wchar_t* s_name;

            Window( const Window& ) = delete;
            void operator=( const Window& ) = delete;

            friend class render::Renderer;
            friend class Mouse;
        };
    }
}
