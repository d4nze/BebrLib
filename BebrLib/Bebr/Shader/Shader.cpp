#include "Shader.h"
#include <GL/glew.h>

bebr::shader::Shader::Shader( unsigned int type ) : m_type( type )
{
	m_id = glCreateShader( type );
}

bebr::shader::Shader::~Shader() { glDeleteShader( m_id ); }

void bebr::shader::Shader::attachSource( const std::string& source )
{
	const char* c_source = source.c_str();
	glShaderSource( m_id, 1, &c_source, nullptr );
}

bool bebr::shader::Shader::compile() const
{
	glCompileShader( m_id );
	int compileStatus;
	glGetShaderiv( m_id, GL_COMPILE_STATUS, &compileStatus );
	return compileStatus == GL_TRUE;
}
