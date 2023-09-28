#include "Shape.h"
#include "../Texture/StandartTexture.h"

template<typename VertexType>
bebr::shape::Shape<VertexType>::Shape() : m_texture(&texture::StandartTexture::GetInstance()) {}

template<typename VertexType>
void bebr::shape::Shape<VertexType>::setTexture( texture::Texture* texture )
{
	m_texture = texture;
}

template<typename VertexType>
void bebr::shape::Shape<VertexType>::setData()
{
	m_va.bind();
	m_vb.bind();
	m_vb.setData( m_vertices );
	m_ib.bind();
	m_ib.setData( m_indices );
	m_va.unbind();
	m_vb.unbind();
	m_ib.unbind();
}

template<typename VertexType>
void bebr::shape::Shape<VertexType>::updateData()
{
	m_va.bind();
	m_vb.bind();
	m_ib.bind();
	m_vb.updateData( m_vertices );
	m_ib.updateData( m_indices );
	m_va.unbind();
	m_vb.unbind();
	m_ib.unbind();
}

#include <GL/glew.h>

template<typename VertexType>
void bebr::shape::Shape<VertexType>::render()
{
	if (m_texture == nullptr) { return; }
	m_texture->bind();
	m_texture->bufferData();
	updateData();

	m_va.bind();
	m_va.updateAttribute( m_vb, m_vbl );
	m_ib.bind();
	glDrawElements( GL_TRIANGLES, m_ib.getSize(), m_ib.getType(), nullptr );
	m_ib.unbind();
	m_va.unbind();
	m_texture->unbind();
}

#include "Shape2Vertex.h"

template class bebr::shape::Shape<bebr::shape::Shape2Vertex>;
