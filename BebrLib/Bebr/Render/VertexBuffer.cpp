#include "VertexBuffer.h"
#include <GL/glew.h>

bebr::render::VertexBuffer::VertexBuffer() : bebr::render::Buffer() {}

bebr::render::VertexBuffer::~VertexBuffer() {}

void bebr::render::VertexBuffer::bind() const { Bind( m_id ); }

void bebr::render::VertexBuffer::unbind() const { Bind( 0u ); }

void bebr::render::VertexBuffer::setData( const void* data, unsigned int size ) const
{
	glBufferData( GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW );
}

void bebr::render::VertexBuffer::updateData( const void* data, unsigned int size ) const
{
	glBufferSubData( GL_ARRAY_BUFFER, 0, size, data );
}

template<typename T>
void bebr::render::VertexBuffer::setData( const std::vector<T>& data ) const
{
	setData( data.data(), static_cast<unsigned int>(data.size()) * sizeof( T ) );
}

template<typename T>
void bebr::render::VertexBuffer::updateData( const std::vector<T>& data ) const
{
	updateData( data.data(), static_cast<unsigned int>(data.size()) * sizeof( T ) );
}

unsigned int bebr::render::VertexBuffer::s_currentId = 0u;

void bebr::render::VertexBuffer::Bind( unsigned int id )
{
	if (s_currentId != id)
	{
		s_currentId = id;
		glBindBuffer( GL_ARRAY_BUFFER, id );
	}
}

#include "../Shapes/Shape2Vertex.h"

template void bebr::render::VertexBuffer::setData( const std::vector<float>& ) const;
template void bebr::render::VertexBuffer::setData( const std::vector<shapes::Shape2Vertex>& ) const;
template void bebr::render::VertexBuffer::updateData( const std::vector<float>& ) const;
template void bebr::render::VertexBuffer::updateData( const std::vector<shapes::Shape2Vertex>& ) const;
