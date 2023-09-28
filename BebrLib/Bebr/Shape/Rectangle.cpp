#include "Rectangle.h"

bebr::shape::Rectangle::Rectangle() : Shape2(), m_size()
{
	initVertices();
	initIndices();
	setData();
}

bebr::shape::Rectangle::Rectangle( core::Rect rectangle ) : Shape2()
{
	initVertices();
	setPosition( rectangle.position );
	setSize( rectangle.size );
	initIndices();
	setData();
}

bebr::shape::Rectangle::Rectangle( float x, float y, float width, float height ) : Shape2()
{
	initVertices();
	setPosition( x, y );
	setSize( width, height );
	initIndices();
	setData();
}

bebr::shape::Rectangle::Rectangle( math::Vector2f position, math::Vector2f size ) : Shape2()
{
	initVertices();
	setPosition( position );
	setSize( size );
	initIndices();
	setData();
}

void bebr::shape::Rectangle::setSize( float width, float height )
{
	m_size.x = width;
	m_size.y = height;
	m_vertices[ TopLeft ].position.x = 0.f;
	m_vertices[ TopLeft ].position.y = height;
	m_vertices[ TopRight ].position = m_size;
	m_vertices[ BottomRight ].position.x = width;
	m_vertices[ BottomRight ].position.y = 0.f;
	m_vertices[ BottomLeft ].position.x = 0.f;
	m_vertices[ BottomLeft ].position.y = 0.f;
}

void bebr::shape::Rectangle::setSize( math::Vector2f size ) { setSize( size.x, size.y ); }

bebr::math::Vector2f bebr::shape::Rectangle::getSize() const { return m_size; }

void bebr::shape::Rectangle::setColor( core::Colorf color )
{
	m_vertices[ TopLeft ].color = color;
	m_vertices[ TopRight ].color = color;
	m_vertices[ BottomRight ].color = color;
	m_vertices[ BottomLeft ].color = color;
}

void bebr::shape::Rectangle::setColor( core::Colorf color, Corner corner )
{
	m_vertices[ corner ].color = color;
}

bebr::core::Colorf bebr::shape::Rectangle::getColor( Corner corner ) const { return m_vertices[ corner ].color; }

void bebr::shape::Rectangle::setTextureRectangle( core::Rect textureRectangle )
{
	if (m_texture == nullptr) { return; }
	m_textureRectangle = textureRectangle;
	core::NormalizeRectangle(
		textureRectangle,
		static_cast<float>(m_texture->getWidth()),
		static_cast<float>(m_texture->getHeigth()) );
	m_vertices[ TopLeft ].texCoords.x = textureRectangle.position.x;
	m_vertices[ TopLeft ].texCoords.y = textureRectangle.position.y + textureRectangle.size.y;
	m_vertices[ TopRight ].texCoords = textureRectangle.position + textureRectangle.size;
	m_vertices[ BottomRight ].texCoords.x = textureRectangle.position.x + textureRectangle.size.x;
	m_vertices[ BottomRight ].texCoords.y = textureRectangle.position.y;
	m_vertices[ BottomLeft ].texCoords = textureRectangle.position;
}

bebr::core::Rect bebr::shape::Rectangle::getTextureRectangle() const { return m_textureRectangle; }

void bebr::shape::Rectangle::initVertices() 
{ 
	m_vertices = std::vector<Shape2Vertex>( 4 );
	setColor( core::Colorf::White );
	m_vertices[TopLeft].texCoords = math::Vector2f{ 0.f, 1.f };
	m_vertices[TopRight].texCoords = math::Vector2f{ 1.f, 1.f };
	m_vertices[BottomRight].texCoords = math::Vector2f{ 1.f, 0.f };
	m_vertices[BottomLeft].texCoords = math::Vector2f{ 0.f, 0.f };
}

void bebr::shape::Rectangle::initIndices() { m_indices = { 0u, 1u, 2u, 0u, 3u, 2u }; }
