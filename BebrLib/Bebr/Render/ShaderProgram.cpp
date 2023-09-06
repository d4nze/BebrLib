#include "ShaderProgram.h"
#include <GL/glew.h>

bebr::render::ShaderProgram::ShaderProgram() : m_id( glCreateProgram() ) {}

bebr::render::ShaderProgram::~ShaderProgram() { glDeleteProgram( m_id ); }

void bebr::render::ShaderProgram::attachShader( const VertexShader& vertexShader ) const
{
	glAttachShader( m_id, vertexShader.m_id );
}

void bebr::render::ShaderProgram::attachShader( const FragmentShader& fragmentShader ) const
{
	glAttachShader( m_id, fragmentShader.m_id );
}

void bebr::render::ShaderProgram::link() const { glLinkProgram( m_id ); }

void bebr::render::ShaderProgram::use() const { Use( m_id ); }

void bebr::render::ShaderProgram::unuse() const { Use( 0u ); }

const bebr::render::ShaderUniform& bebr::render::ShaderProgram::operator[]( std::string uniformName )
{
	ShaderUniform* noUniform = nullptr;
	for (ShaderUniform& uniform : m_uniforms)
	{
		if (uniform.m_name == uniformName) { return uniform; }
		if (uniform.m_name == "" && uniform.m_location == 0u) { noUniform = &uniform; }
	}
	unsigned int location = glGetUniformLocation( m_id, uniformName.c_str() );
	if (location == 0u) 
	{ 
		if (noUniform != nullptr) { return *noUniform; }
		uniformName = "";
	}
	m_uniforms.push_back( ShaderUniform( location, uniformName ) );
	return m_uniforms.back();
}

unsigned int bebr::render::ShaderProgram::s_currentId = 0u;

void bebr::render::ShaderProgram::Use( unsigned int id )
{
	if (s_currentId != id)
	{
		s_currentId = id;
		glUseProgram( id );
	}
}
