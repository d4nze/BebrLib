#include "Buffer.h"
#include <GL/glew.h>

bebr::buffer::Buffer::Buffer()
{
	glGenBuffers( 1, &m_id );
}

bebr::buffer::Buffer::~Buffer()
{
	glDeleteBuffers( 1, &m_id );
}
