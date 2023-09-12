#include "TextureManager.h"

bebr::texture::TextureManager::TextureManager() {}

bebr::texture::TextureManager::~TextureManager() {}

bebr::texture::Texture& bebr::texture::TextureManager::operator[]( const char* path )
{
	if (m_data.find( path ) != m_data.end()) { return *m_data[ path ]; }
	Texture* result = new Texture;
	result->load( path );
	result->bind();
	result->setWrapping( result->Repeat );
	result->setFilter( result->Nearest );
	result->generateMipmap();
	result->unbind();
	m_data[ path ] = result;
	return *result;
}
