#include "VertexBufferLayout.h"

bebr::render::VertexBufferLayout::VertexBufferLayout() : m_stridesize( 0u ) {}

#include <GL/glew.h>
#define TEMPLATE_PUSH( type, glType, glBool )\
template<>\
void bebr::render::VertexBufferLayout::push<type>( int count )\
{\
	static unsigned int typeSize = sizeof( type );\
	m_elements.push_back( { glType, typeSize, count, glBool } );\
	m_stridesize += typeSize * count;\
}
TEMPLATE_PUSH( char, GL_BYTE, GL_TRUE )
TEMPLATE_PUSH( unsigned char, GL_UNSIGNED_BYTE, GL_TRUE )
TEMPLATE_PUSH( short, GL_SHORT, GL_TRUE )
TEMPLATE_PUSH( unsigned short, GL_UNSIGNED_SHORT, GL_TRUE )
TEMPLATE_PUSH( int, GL_INT, GL_TRUE )
TEMPLATE_PUSH( unsigned int, GL_UNSIGNED_INT, GL_TRUE )
TEMPLATE_PUSH( float, GL_FLOAT, GL_FALSE )
TEMPLATE_PUSH( double, GL_DOUBLE, GL_FALSE )
#undef TEMPLATE_PUSH

const bebr::render::VertexBufferElement& bebr::render::VertexBufferLayout::operator[]( unsigned int index ) const
{
	return m_elements[ index ];
}

unsigned int bebr::render::VertexBufferLayout::getSize() const
{
	return static_cast<unsigned int>(m_elements.size());
}

unsigned int bebr::render::VertexBufferLayout::getStrideSize() const
{
	return m_stridesize;
}

