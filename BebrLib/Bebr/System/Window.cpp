#include "Window.h"

const wchar_t* bebr::system::Window::s_name = L"BebrWindow";

bebr::system::Window::Window( int width, int height, const char* title )
    : m_width( width ), m_height( height ), m_title( title ), m_fpsLimit( 0u )
{
    WNDCLASSEX wc = {
        sizeof( WNDCLASSEX ),
        CS_CLASSDC,
        WindowProc,
        0L,
        0L,
        GetModuleHandle( NULL ),
        NULL,
        NULL,
        NULL,
        NULL,
        s_name,
        NULL
    };
    RegisterClassEx( &wc );

    m_hWnd = CreateWindow( wc.lpszClassName, s_name, WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, wc.hInstance, this );

    m_hDC = GetDC( m_hWnd );

    static PIXELFORMATDESCRIPTOR s_pfd = {};

    memset( &s_pfd, 0, sizeof( PIXELFORMATDESCRIPTOR ) );
    s_pfd.nSize = sizeof( PIXELFORMATDESCRIPTOR );
    s_pfd.nVersion = 1;
    s_pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    s_pfd.iPixelType = PFD_TYPE_RGBA;
    s_pfd.cColorBits = 32;
    s_pfd.cDepthBits = 24;
    s_pfd.cStencilBits = 8;
    s_pfd.iLayerType = PFD_MAIN_PLANE;

    int pixelFormat = ChoosePixelFormat( m_hDC, &s_pfd );
    SetPixelFormat( m_hDC, pixelFormat, &s_pfd );

    m_hRC = wglCreateContext( m_hDC );
    makeCurrent();

    setSize( width, height );
    setTitle( title );
    ShowWindow( m_hWnd, SW_SHOWDEFAULT );
    UpdateWindow( m_hWnd );
}

bebr::system::Window::~Window()
{
    DestroyWindow( m_hWnd );
    UnregisterClass( s_name, GetModuleHandle( NULL ) );
}

void bebr::system::Window::setSize( math::Vector2i size ) { setSize( size.x, size.y ); }

void bebr::system::Window::setSize( int width, int height )
{
    m_width = width;
    m_height = height;

    RECT windowRect = { 0, 0, width, height };
    AdjustWindowRectEx( &windowRect, WS_OVERLAPPEDWINDOW, FALSE, 0 );

    int screenWidth = GetSystemMetrics( SM_CXSCREEN );
    int screenHeight = GetSystemMetrics( SM_CYSCREEN );

    int x = (screenWidth - width) / 2;
    int y = (screenHeight - height) / 2;

    if (m_hWnd)
    {
        SetWindowPos( m_hWnd, NULL, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE );
    }
}

#include <string>

void bebr::system::Window::setTitle( const char* title )
{
    std::wstring m_wTitle( title, title + strlen( title ) );
    if (m_hWnd)
    {
        SetWindowText( m_hWnd, m_wTitle.c_str() );
    }
}

void bebr::system::Window::setMaxFrameRate( unsigned int maxFPS )
{
    m_fpsLimit = maxFPS;
}

void bebr::system::Window::setFullscreen( bool fullscreen )
{
    if (fullscreen == getFullscreen()) { return; }

    if (fullscreen) 
    {
        DWORD style = GetWindowLong( m_hWnd, GWL_STYLE );
        SetWindowLong( m_hWnd, GWL_STYLE, style & ~WS_OVERLAPPEDWINDOW );

        MONITORINFO monitorInfo = { sizeof( MONITORINFO ) };
        if (GetMonitorInfo( MonitorFromWindow( m_hWnd, MONITOR_DEFAULTTONEAREST ), &monitorInfo )) {
            SetWindowPos( m_hWnd, NULL, monitorInfo.rcMonitor.left, monitorInfo.rcMonitor.top,
                monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left,
                monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top,
                SWP_NOZORDER | SWP_NOACTIVATE );
        }
    }
    else 
    {
        DWORD style = GetWindowLong( m_hWnd, GWL_STYLE );
        SetWindowLong( m_hWnd, GWL_STYLE, style | WS_OVERLAPPEDWINDOW );

        SetWindowPos( m_hWnd, NULL, 100, 100, m_width, m_height,
            SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE );
    }
}

bebr::math::Vector2i bebr::system::Window::getSize()
{
    return { m_width, m_height };
}

const char* bebr::system::Window::getTitle()
{
    return m_title;
}

bool bebr::system::Window::isOpen()
{
    return IsWindowVisible( m_hWnd );
}

unsigned int bebr::system::Window::getMaxFrameRate()
{
    return m_fpsLimit;
}

bool bebr::system::Window::getFullscreen()
{
    DWORD style = GetWindowLong( m_hWnd, GWL_STYLE );
    return (style & WS_OVERLAPPEDWINDOW) == 0;
}

#include "Mouse.h"
#include "Keyboard.h"
#include <thread>

void bebr::system::Window::pollEvent()
{
    static Keyboard& keyboard = Keyboard::GetInstance();
    static Mouse& mouse = Mouse::GetInstance();
    keyboard.update();
    ShowCursor( 1 );

    MSG msg;
    while (PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ))
    {
        if (msg.message == WM_QUIT) { return; }
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }

    RECT clientRect;
    GetClientRect( m_hWnd, &clientRect );

    m_width = clientRect.right - clientRect.left;
    m_height = clientRect.bottom - clientRect.top;

    POINT mousePos = { 0, 0 };
    GetCursorPos( &mousePos );
    ScreenToClient( m_hWnd, &mousePos );
    mouse.m_x = mousePos.x;
    mouse.m_y = mousePos.y * -1;

    if (m_fpsLimit == 0u) { return; }

    auto currentTime = std::chrono::high_resolution_clock::now();
    auto frameDuration = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - m_lastFrameTime).count();
    auto frameTime = 1000000 / m_fpsLimit;

    if (frameDuration < frameTime)
    {
        std::this_thread::sleep_for( std::chrono::microseconds( frameTime - frameDuration ) );
    }

    m_lastFrameTime = currentTime;
}

void bebr::system::Window::close()
{
    if (m_hWnd)
    {
        PostMessage( m_hWnd, WM_CLOSE, 0, 0 );
    }
}

void bebr::system::Window::makeCurrent()
{
    wglMakeCurrent( m_hDC, m_hRC );
}

void bebr::system::Window::swapBuffers()
{
    SwapBuffers( m_hDC );
}

LRESULT CALLBACK bebr::system::Window::WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    if (uMsg == WM_CREATE) {
        LPCREATESTRUCT pCreate = reinterpret_cast<LPCREATESTRUCT>(lParam);
        Window* pThis = reinterpret_cast<Window*>(pCreate->lpCreateParams);
        SetWindowLongPtr( hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis) );
    }

    Window* pThis = reinterpret_cast<Window*>(GetWindowLongPtr( hwnd, GWLP_USERDATA ));
    static Keyboard& keyboard = Keyboard::GetInstance();

    if (pThis) {
        switch (uMsg) {
        case WM_CLOSE:
            DestroyWindow( hwnd );
            break;
        case WM_DESTROY:
            PostQuitMessage( 0 );
            return 0;
        case WM_KEYDOWN:
        {
            Keyboard::Key keyCode = static_cast<Keyboard::Key>(static_cast<int>(wParam));
            Keyboard::KeyState state = keyboard.getKeyState( keyCode ) == Keyboard::KeyState::Down ? Keyboard::KeyState::Down : Keyboard::KeyState::Pressed;
            keyboard.setKeyState( keyCode, state );
            break;
        }
        case WM_KEYUP:
        {
            keyboard.setKeyState( static_cast<Keyboard::Key>(static_cast<int>(wParam)), Keyboard::KeyState::Released );
            break;
        }
        }
    }

    return DefWindowProc( hwnd, uMsg, wParam, lParam );
}
