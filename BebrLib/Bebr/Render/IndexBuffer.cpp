#include "IndexBuffer.h"
#include <GL/glew.h>

bebr::render::IndexBuffer::IndexBuffer() : Buffer(), m_size( 0u ), m_type( 0u ) {}

bebr::render::IndexBuffer::~IndexBuffer() {}

void bebr::render::IndexBuffer::bind() const
{
	Bind( m_id );
}

void bebr::render::IndexBuffer::unbind() const
{
	Bind( 0u );
}

template<typename T>
void bebr::render::IndexBuffer::setData( T* data, unsigned int size )
{
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW );
	updateType<T>();
	m_size = size / sizeof( T );
}

template<typename T>
void bebr::render::IndexBuffer::setData( std::vector<T>& data )
{
	setData( data.data(), static_cast<unsigned int>(data.size()) * sizeof( T ) );
}

template<typename T>
void bebr::render::IndexBuffer::updateData( T* data, unsigned int size )
{
	glBufferSubData( GL_ELEMENT_ARRAY_BUFFER, 0, size, data );
	updateType<T>();
	m_size = size / sizeof( T );
}

template<typename T>
void bebr::render::IndexBuffer::updateData( std::vector<T>& data )
{
	updateData( data.data(), static_cast<unsigned int>(data.size()) * sizeof( T ) );
}

unsigned int bebr::render::IndexBuffer::getType() const
{
	return m_type;
}

unsigned int bebr::render::IndexBuffer::getSize() const
{
	return m_size;
}

template<>
void bebr::render::IndexBuffer::updateType<char>()
{
	m_type = GL_BYTE;
}

template<>
void bebr::render::IndexBuffer::updateType<unsigned char>()
{
	m_type = GL_UNSIGNED_BYTE;
}

template<>
void bebr::render::IndexBuffer::updateType<int>()
{
	m_type = GL_INT;
}

template<>
void bebr::render::IndexBuffer::updateType<unsigned int>()
{
	m_type = GL_UNSIGNED_INT;
}

unsigned int bebr::render::IndexBuffer::s_currentId = 0u;

void bebr::render::IndexBuffer::Bind( unsigned int id )
{
	if (id != s_currentId)
	{
		s_currentId = id;
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id );
	}
}

#define TEMPLATE_IB_METHODS( type )\
template void bebr::render::IndexBuffer::setData<type>( type*, unsigned int );\
template void bebr::render::IndexBuffer::updateData<type>( type*, unsigned int );\
template void bebr::render::IndexBuffer::setData<type>( std::vector<type>& );\
template void bebr::render::IndexBuffer::updateData<type>( std::vector<type>& )
TEMPLATE_IB_METHODS( char );
TEMPLATE_IB_METHODS( unsigned char );
TEMPLATE_IB_METHODS( int );
TEMPLATE_IB_METHODS( unsigned int );
