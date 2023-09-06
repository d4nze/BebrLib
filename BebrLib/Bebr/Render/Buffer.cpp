#include "Buffer.h"
#include <GL/glew.h>

bebr::render::Buffer::Buffer()
{
	glGenBuffers( 1, &m_id );
}

bebr::render::Buffer::~Buffer()
{
	glDeleteBuffers( 1, &m_id );
}
