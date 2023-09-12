#include "IndexBuffer.h"
#include <GL/glew.h>

bebr::buffer::IndexBuffer::IndexBuffer() : Buffer(), m_size( 0u ), m_type( 0u ) {}

bebr::buffer::IndexBuffer::~IndexBuffer() {}

void bebr::buffer::IndexBuffer::bind() const
{
	Bind( m_id );
}

void bebr::buffer::IndexBuffer::unbind() const
{
	Bind( 0u );
}

template<typename T>
void bebr::buffer::IndexBuffer::setData( T* data, unsigned int size )
{
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW );
	updateType<T>();
	m_size = size / sizeof( T );
}

template<typename T>
void bebr::buffer::IndexBuffer::setData( std::vector<T>& data )
{
	setData( data.data(), static_cast<unsigned int>(data.size()) * sizeof( T ) );
}

template<typename T>
void bebr::buffer::IndexBuffer::updateData( T* data, unsigned int size )
{
	glBufferSubData( GL_ELEMENT_ARRAY_BUFFER, 0, size, data );
	updateType<T>();
	m_size = size / sizeof( T );
}

template<typename T>
void bebr::buffer::IndexBuffer::updateData( std::vector<T>& data )
{
	updateData( data.data(), static_cast<unsigned int>(data.size()) * sizeof( T ) );
}

unsigned int bebr::buffer::IndexBuffer::getType() const
{
	return m_type;
}

unsigned int bebr::buffer::IndexBuffer::getSize() const
{
	return m_size;
}

template<>
void bebr::buffer::IndexBuffer::updateType<char>()
{
	m_type = GL_BYTE;
}

template<>
void bebr::buffer::IndexBuffer::updateType<unsigned char>()
{
	m_type = GL_UNSIGNED_BYTE;
}

template<>
void bebr::buffer::IndexBuffer::updateType<int>()
{
	m_type = GL_INT;
}

template<>
void bebr::buffer::IndexBuffer::updateType<unsigned int>()
{
	m_type = GL_UNSIGNED_INT;
}

unsigned int bebr::buffer::IndexBuffer::s_currentId = 0u;

void bebr::buffer::IndexBuffer::Bind( unsigned int id )
{
	if (id != s_currentId)
	{
		s_currentId = id;
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id );
	}
}

#define TEMPLATE_IB_METHODS( type )\
template void bebr::buffer::IndexBuffer::setData<type>( type*, unsigned int );\
template void bebr::buffer::IndexBuffer::updateData<type>( type*, unsigned int );\
template void bebr::buffer::IndexBuffer::setData<type>( std::vector<type>& );\
template void bebr::buffer::IndexBuffer::updateData<type>( std::vector<type>& )
TEMPLATE_IB_METHODS( char );
TEMPLATE_IB_METHODS( unsigned char );
TEMPLATE_IB_METHODS( int );
TEMPLATE_IB_METHODS( unsigned int );
