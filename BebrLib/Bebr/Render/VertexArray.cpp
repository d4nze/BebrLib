#include "VertexArray.h"
#include <GL/glew.h>

bebr::render::VertexArray::VertexArray()
{
	glGenVertexArrays( 1, &m_id );
}

bebr::render::VertexArray::~VertexArray()
{
	glDeleteVertexArrays( 1, &m_id );
}

void bebr::render::VertexArray::bind() const
{
	Bind( m_id );
}

void bebr::render::VertexArray::unbind() const
{
	Bind( 0u );
}

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

void bebr::render::VertexArray::updateAttribute( const VertexBuffer& vb, const VertexBufferLayout& vbl ) const
{
	vb.bind();

	const unsigned int stride = vbl.getStrideSize();
	unsigned int offset = 0u;
	for (unsigned int i = 0; i < vbl.getSize(); i++)
	{
		const VertexBufferElement& vbe = vbl[ i ];
		glVertexAttribPointer( i, vbe.count, vbe.type, vbe.normalized, stride, (void*)offset );
		glEnableVertexAttribArray( i );
		offset += vbe.typeSize * vbe.count;
	}

	vb.unbind();
}

unsigned int bebr::render::VertexArray::s_currentId = 0u;

void bebr::render::VertexArray::Bind( unsigned int id )
{
	if (id != s_currentId)
	{
		s_currentId = id;
		glBindVertexArray( id );
	}
}
