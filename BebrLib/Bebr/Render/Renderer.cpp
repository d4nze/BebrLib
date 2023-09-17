#include "Renderer.h"
#include "../System/Window.h"
#include "GL/glew.h"

bebr::render::Renderer& bebr::render::Renderer::GetInstance()
{
    static Renderer s_renderer;
    return s_renderer;
}

void bebr::render::Renderer::start( system::Window* window )
{
    window->makeCurrent();
    m_currentWindow = window;
    if (glewInit() != GLEW_OK) { exit( -1 ); }
    glViewport( 0, 0, window->m_width, window->m_height );
}

void bebr::render::Renderer::start( system::Window* window, camera::CameraMatrix2* camera )
{
    window->makeCurrent();
    m_currentWindow = window;

    m_currentCamera = camera;
    
    if (glewInit() != GLEW_OK) { exit( -1 ); }
    glViewport( 0, 0, window->m_width, window->m_height );
}

void bebr::render::Renderer::end()
{
    m_currentWindow = nullptr;
    m_currentCamera = nullptr;
}

void bebr::render::Renderer::clear( float r, float g, float b, float a ) const
{
    glClearColor( r, g, b, a );
    glClear( GL_COLOR_BUFFER_BIT );
}

void bebr::render::Renderer::clear( core::Colorf color ) const
{
    clear( color.r, color.g, color.b, color.a );
}

void bebr::render::Renderer::display() const
{
    m_currentWindow->swapBuffers();
}

bebr::render::Renderer::Renderer() : m_currentWindow( nullptr ), m_currentCamera( nullptr )
{
    if (glewInit() != GLEW_OK) { exit( -1 ); }
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );
}
