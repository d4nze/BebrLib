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
    if (glewInit() != GLEW_OK) { exit( -1 ); }
    glViewport( 0, 0, window->m_width, window->m_height );
    m_currentWindow = window;
}

void bebr::render::Renderer::end()
{
    m_currentWindow = nullptr;
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

void bebr::render::Renderer::_setAttribute( const VertexBuffer& vb )
{
    glVertexAttribPointer( 0u, 2, GL_FLOAT, GL_FALSE, 2 * sizeof( float ), (void*)0 );
    glEnableVertexAttribArray( 0u );
}

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

void bebr::render::Renderer::drawTriangle(
    const VertexArray& va, const VertexBuffer& vb,
    const VertexBufferLayout& vbl, int trianglesCount )
{
    va.bind();
    va.updateAttribute( vb, vbl );
    glDrawArrays( GL_TRIANGLES, 0, trianglesCount * 3 );
    va.unbind();
}

#include "IndexBuffer.h"

void bebr::render::Renderer::drawTriangle(
    const VertexArray& va, const VertexBuffer& vb,
    const VertexBufferLayout& vbl, IndexBuffer& ib )
{
    va.bind();
    va.updateAttribute( vb, vbl );
    ib.bind();
    glDrawElements( GL_TRIANGLES, ib.getSize(), ib.getType(), nullptr );
    ib.unbind();
    va.unbind();
}

void bebr::render::Renderer::display() const
{
    m_currentWindow->swapBuffers();
}

bebr::render::Renderer::Renderer() : m_currentWindow( nullptr ) 
{
    if (glewInit() != GLEW_OK) { exit( -1 ); }
}
