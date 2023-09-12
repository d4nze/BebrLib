#include "VertexBuffer.h"
#include <GL/glew.h>

bebr::buffer::VertexBuffer::VertexBuffer() : bebr::buffer::Buffer() {}

bebr::buffer::VertexBuffer::~VertexBuffer() {}

void bebr::buffer::VertexBuffer::bind() const { Bind( m_id ); }

void bebr::buffer::VertexBuffer::unbind() const { Bind( 0u ); }

void bebr::buffer::VertexBuffer::setData( const void* data, unsigned int size ) const
{
	glBufferData( GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW );
}

void bebr::buffer::VertexBuffer::updateData( const void* data, unsigned int size ) const
{
	glBufferSubData( GL_ARRAY_BUFFER, 0, size, data );
}

template<typename T>
void bebr::buffer::VertexBuffer::setData( const std::vector<T>& data ) const
{
	setData( data.data(), static_cast<unsigned int>(data.size()) * sizeof( T ) );
}

template<typename T>
void bebr::buffer::VertexBuffer::updateData( const std::vector<T>& data ) const
{
	updateData( data.data(), static_cast<unsigned int>(data.size()) * sizeof( T ) );
}

unsigned int bebr::buffer::VertexBuffer::s_currentId = 0u;

void bebr::buffer::VertexBuffer::Bind( unsigned int id )
{
	if (s_currentId != id)
	{
		s_currentId = id;
		glBindBuffer( GL_ARRAY_BUFFER, id );
	}
}

#include "../Shape/Shape2Vertex.h"

template void bebr::buffer::VertexBuffer::setData( const std::vector<float>& ) const;
template void bebr::buffer::VertexBuffer::setData( const std::vector<shape::Shape2Vertex>& ) const;
template void bebr::buffer::VertexBuffer::updateData( const std::vector<float>& ) const;
template void bebr::buffer::VertexBuffer::updateData( const std::vector<shape::Shape2Vertex>& ) const;
