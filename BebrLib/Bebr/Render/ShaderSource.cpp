#include "ShaderSource.h"
#include <fstream>

bebr::render::ShaderSource::ShaderSource( std::string path )
{
	std::ifstream fin( path );
	if (!fin.fail())
	{
		typedef std::istreambuf_iterator< char > fin_it;
		m_source = std::string( fin_it( fin ), fin_it() );
	}
}

const std::string& bebr::render::ShaderSource::getSource() const
{
	return m_source;
}

bool bebr::render::ShaderSource::operator==( const ShaderSource& other ) const
{
    return m_source == other.m_source;
}

bool bebr::render::ShaderSource::operator!=( const ShaderSource& other ) const
{
    return !(*this == other);
}

#include <vector>

bebr::render::ShaderSource bebr::render::LoadShaderSource( std::string path )
{
	static std::vector<ShaderSource> s_source;
	ShaderSource newSource( path );
	for (size_t i = static_cast<size_t>(0); i < s_source.size(); i++)
	{
		if (s_source[ i ] == newSource) { return s_source[ i ]; }
	}
	s_source.push_back( newSource );
	return newSource;
}
