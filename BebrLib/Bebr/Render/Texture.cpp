#include "Texture.h"
#include <GL/glew.h>

bebr::render::Texture::Texture() : m_data( nullptr ), m_width( 0 ), m_height( 0 )
{
	glGenTextures( 1, &m_id );
}
