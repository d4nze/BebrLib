#include "ShaderUniform.h"
#include <GL/glew.h>

bebr::shader::ShaderUniform::ShaderUniform( unsigned int location, std::string name ) :
	m_location( location ), m_name( name ) {}

void bebr::shader::ShaderUniform::setInt1( int value ) const
{
	glUniform1i( m_location, value );
}

void bebr::shader::ShaderUniform::setInt2( int value1, int value2 ) const
{
	glUniform2i( m_location, value1, value2 );
}

void bebr::shader::ShaderUniform::setInt3( int value1, int value2, int value3 ) const
{
	glUniform3i( m_location, value1, value2, value3 );
}

void bebr::shader::ShaderUniform::setInt4( int value1, int value2, int value3, int value4 ) const
{
	glUniform4i( m_location, value1, value2, value3, value4 );
}

void bebr::shader::ShaderUniform::setUInt1( unsigned int value ) const
{
	glUniform1ui( m_location, value );
}

void bebr::shader::ShaderUniform::setUInt2( unsigned int value1, unsigned int value2 ) const
{
	glUniform2ui( m_location, value1, value2 );
}

void bebr::shader::ShaderUniform::setUInt3( unsigned int value1, unsigned int value2, unsigned int value3 ) const
{
	glUniform3ui( m_location, value1, value2, value3 );
}

void bebr::shader::ShaderUniform::setUInt4( unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4 ) const
{
	glUniform4ui( m_location, value1, value2, value3, value4 );
}

void bebr::shader::ShaderUniform::setFloat1( float value ) const
{
	glUniform1f( m_location, value );
}

void bebr::shader::ShaderUniform::setFloat2( float value1, float value2 ) const
{
	glUniform2f( m_location, value1, value2 );
}

void bebr::shader::ShaderUniform::setFloat3( float value1, float value2, float value3 ) const
{
	glUniform3f( m_location, value1, value2, value3 );
}

void bebr::shader::ShaderUniform::setFloat4( float value1, float value2, float value3, float value4 ) const
{
	glUniform4f( m_location, value1, value2, value3, value4 );
}

void bebr::shader::ShaderUniform::setDouble1( double value ) const
{
	glUniform1d( m_location, value );
}

void bebr::shader::ShaderUniform::setDouble2( double value1, double value2 ) const
{
	glUniform2d( m_location, value1, value2 );
}

void bebr::shader::ShaderUniform::setDouble3( double value1, double value2, double value3 ) const
{
	glUniform3d( m_location, value1, value2, value3 );
}

void bebr::shader::ShaderUniform::setDouble4( double value1, double value2, double value3, double value4 ) const
{
	glUniform4d( m_location, value1, value2, value3, value4 );
}

void bebr::shader::ShaderUniform::setMat2( math::Mat2& matrix ) const
{
	float* matData = math::getMatrixData(matrix);
	glUniformMatrix2fv( m_location, 1, GL_TRUE, matData );
	delete[] matData;
}

void bebr::shader::ShaderUniform::setMat3( math::Mat3& matrix ) const
{
	float* matData = math::getMatrixData(matrix);
	glUniformMatrix3fv( m_location, 1, GL_TRUE, matData );
	delete[] matData;
}

void bebr::shader::ShaderUniform::setMat4( math::Mat4& matrix ) const
{
	float* matData = math::getMatrixData(matrix);
	glUniformMatrix4fv( m_location, 1, GL_TRUE, matData );
	delete[] matData;
}

template<>
void bebr::shader::ShaderUniform::setVec2<int>( math::Vector2i value ) const
{
	glUniform2i( m_location, value.x, value.y );
}

template<>
void bebr::shader::ShaderUniform::setVec3<int>( math::Vector3i value ) const
{
	glUniform3i( m_location, value.x, value.y, value.z );
}

template<>
void bebr::shader::ShaderUniform::setVec4<int>( math::Vector4i value ) const
{
	glUniform4i( m_location, value.x, value.y, value.z, value.w );
}

template<>
void bebr::shader::ShaderUniform::setVec2<unsigned int>( math::Vector2u value ) const
{
	glUniform2ui( m_location, value.x, value.y );
}

template<>
void bebr::shader::ShaderUniform::setVec3<unsigned int>( math::Vector3u value ) const
{
	glUniform3ui( m_location, value.x, value.y, value.z );
}

template<>
void bebr::shader::ShaderUniform::setVec4<unsigned int>( math::Vector4u value ) const
{
	glUniform4ui( m_location, value.x, value.y, value.z, value.w );
}

template<>
void bebr::shader::ShaderUniform::setVec2<float>( math::Vector2f value ) const
{
	glUniform2f( m_location, value.x, value.y );
}

template<>
void bebr::shader::ShaderUniform::setVec3<float>( math::Vector3f value ) const
{
	glUniform3f( m_location, value.x, value.y, value.z );
}

template<>
void bebr::shader::ShaderUniform::setVec4<float>( math::Vector4f value ) const
{
	glUniform4f( m_location, value.x, value.y, value.z, value.w );
}

template<>
void bebr::shader::ShaderUniform::setVec2<double>( math::Vector2d value ) const
{
	glUniform2d( m_location, value.x, value.y );
}

template<>
void bebr::shader::ShaderUniform::setVec3<double>( math::Vector3d value ) const
{
	glUniform3d( m_location, value.x, value.y, value.z );
}

template<>
void bebr::shader::ShaderUniform::setVec4<double>( math::Vector4d value ) const
{
	glUniform4d( m_location, value.x, value.y, value.z, value.w );
}
