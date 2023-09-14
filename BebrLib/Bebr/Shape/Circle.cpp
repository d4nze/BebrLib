#include "Circle.h"

bebr::shape::Circle::Circle() : Shape2()
{
	setSize( 0.f, 0.f );
	setCount( 0 );
}

bebr::shape::Circle::Circle( core::RectangleData rectangle ) : Shape2()
{
	setPosition( rectangle.position );
	setSize( rectangle.size );
	setCount( 16 );
}

bebr::shape::Circle::Circle( float x, float y, float radius ) : Shape2()
{
	setPosition( x, y );
	setRadius( radius );
	setCount( 16 );
}

bebr::shape::Circle::Circle( math::Vector2f position, float radius ) : Shape2()
{
	setPosition( position );
	setRadius( radius );
	setCount( 16 );
}

bebr::shape::Circle::Circle( float x, float y, float width, float height ) : Shape2()
{
	setPosition( x, y );
	setSize( width, height );
	setCount( 16 );
}

bebr::shape::Circle::Circle( math::Vector2f position, math::Vector2f size ) : Shape2()
{
	setPosition( position );
	setSize( size );
	setCount( 16 );
}

#define _USE_MATH_DEFINES
#include <math.h>

void bebr::shape::Circle::setCount( int count )
{
	static float s_pi = M_PI;
	m_count = count;
	m_vertices = std::vector<Shape2Vertex>( count + 1 );
	m_indices = std::vector<unsigned int>( count * 3 );
	float angle = 0.f;
	float step = 360.f / static_cast<float>(count) * s_pi / 180.f;
	math::Vector2f halfSize = m_size / 2.f;
	for (int i = 1; i <= count; i++)
	{
		m_vertices[ i ].position.x = halfSize.x * cosf( angle );
		m_vertices[ i ].position.y = halfSize.y * sinf( angle );
		float distance = sqrtf( m_vertices[ i ].position.x * m_vertices[ i ].position.x + m_vertices[ i ].position.y * m_vertices[ i ].position.y );
		angle += step;
		int index = (i - 1) * 3;
		m_indices[ index ] = 0u;
		m_indices[ index + 1 ] = i;
		if (i == count) { m_indices[ index + 2 ] = 1u; }
		else { m_indices[ index + 2 ] = i + 1; }
	}
	setColor( core::Colorf::White );
	setData();
}

int bebr::shape::Circle::getCount() const { return m_count; }

void bebr::shape::Circle::setSize( float width, float height )
{
	m_size.x = width;
	m_size.y = height;
	setCount( m_count );
}

void bebr::shape::Circle::setSize( math::Vector2f size ) 
{
	m_size = size;
	setCount( m_count );
}

void bebr::shape::Circle::setRadius( float radius )
{
	m_size.x = radius;
	m_size.y = radius;
}

bebr::math::Vector2f bebr::shape::Circle::getSize() const { return m_size; }

void bebr::shape::Circle::setColor( core::Colorf color )
{
	for (Shape2Vertex& vertex : m_vertices) { vertex.color = color; }
}

bebr::core::Colorf bebr::shape::Circle::getColor() const { return m_vertices[ 0 ].color; }

void bebr::shape::Circle::setTextureRectangle( core::RectangleData textureRectangle )
{
	if (m_texture == nullptr) { return; }
	m_textureRectangle = textureRectangle;
	core::NormalizeRectangle(
		textureRectangle,
		static_cast<float>(m_texture->getWidth()),
		static_cast<float>(m_texture->getHeigth()) );
	math::Vector2f halfSize = m_size / 2.f;
	for (Shape2Vertex& vertex : m_vertices)
	{
		vertex.texCoords = vertex.position + halfSize;
		vertex.texCoords.x /= m_size.x * textureRectangle.size.x;
		vertex.texCoords.y /= m_size.y * textureRectangle.size.x;
		vertex.texCoords += textureRectangle.position;
	}
}

bebr::core::RectangleData bebr::shape::Circle::getTextureRectangle() const { return m_textureRectangle; }
