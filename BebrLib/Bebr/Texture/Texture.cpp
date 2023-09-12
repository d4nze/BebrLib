#include "Texture.h"
#include <GL/glew.h>

bebr::texture::Texture::Texture() : m_data( nullptr ), m_width( 0 ), m_height( 0 ), m_colors( 0u )
{
	glGenTextures( 1, &m_id );
}

#include "../Importer/stb_image.h"

bebr::texture::Texture::~Texture()
{
	glDeleteTextures( 1, &m_id );
	stbi_image_free( m_data );
}

void bebr::texture::Texture::load( const char* path )
{
	if (m_data != nullptr) { stbi_image_free( m_data ); }
	stbi_set_flip_vertically_on_load( true );
	m_data = stbi_load( path, &m_width, &m_height, &m_colors, STBI_rgb_alpha );
	// importer::image::ConvertBGRtoRGB( m_data, m_width, m_height, m_colors );
}

void bebr::texture::Texture::create( int width, int height )
{
	if (m_data != nullptr) { stbi_image_free( m_data ); }
	m_width = width;
	m_height = height;
	m_colors = 4u;
	int size = m_width * m_height * m_colors;
	m_data = new unsigned char[ size ];
	for (int i = 0; i < size; i++) { m_data[ i ] = 0; }
}

void bebr::texture::Texture::bind() { Bind( m_id ); }

void bebr::texture::Texture::unbind() { Bind( 0u ); }

void bebr::texture::Texture::generateMipmap() { glGenerateMipmap( GL_TEXTURE_2D ); }

void bebr::texture::Texture::bufferData()
{
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		m_width,
		m_height,
		0,
		(m_colors == 4 ? GL_RGBA : GL_RGB),
		GL_UNSIGNED_BYTE,
		m_data );
}

void bebr::texture::Texture::setWrapping( WrappingType type )
{
	int wrap;
	switch (type)
	{
	case Repeat:
		wrap = GL_REPEAT;
		break;
	case MirroredRepeat:
		wrap = GL_MIRRORED_REPEAT;
		break;
	case ClampToEdge:
		wrap = GL_CLAMP_TO_EDGE;
		break;
	default:
		wrap = GL_CLAMP_TO_BORDER;
		break;
	}
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap );
}

void bebr::texture::Texture::setFilter( FilterType type )
{
	int filert = (type == Nearest ? GL_NEAREST : GL_LINEAR);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filert );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filert );
}

void bebr::texture::Texture::setPixel( int x, int y, core::Coloru color )
{
	if (m_data == nullptr) { return; }
	int pos = m_width * m_colors * y + x * m_colors;
	m_data[ pos + 0 ] = color.r;
	m_data[ pos + 1 ] = color.g;
	m_data[ pos + 2 ] = color.b;
	m_data[ pos + 3 ] = color.a;
}

bebr::core::Coloru bebr::texture::Texture::getPixel( int x, int y )
{
	int pos = m_width * m_colors * y + x * m_colors;
	return { m_data[ pos ], m_data[ pos + 1 ], m_data[ pos + 2 ], m_data[ pos + 3 ] };
}

int bebr::texture::Texture::getWidth() { return m_width; }

int bebr::texture::Texture::getHeigth() { return m_height; }

unsigned int bebr::texture::Texture::s_currentId = 0u;

void bebr::texture::Texture::Bind( unsigned int id )
{
	if (id != s_currentId)
	{
		s_currentId = id;
		glActiveTexture( GL_TEXTURE0 );
		glBindTexture( GL_TEXTURE_2D, id );
	}
}
