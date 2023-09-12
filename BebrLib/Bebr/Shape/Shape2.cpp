#include "Shape2.h"
#include "../shader/ShaderSource.h"

bebr::shader::ShaderProgram* bebr::shape::Shape2::s_program = nullptr;

bebr::shape::Shape2::Shape2()
{
	if (s_program == nullptr)
	{
		s_program = new shader::ShaderProgram;
		bebr::shader::VertexShader vertShader;
		bebr::shader::FragmentShader fragShader;
		vertShader.attachSource( bebr::shader::LoadShaderSource( "Resources/Shaders/test.vert" ).getSource() );
		fragShader.attachSource( bebr::shader::LoadShaderSource( "Resources/Shaders/test.frag" ).getSource() );
		if (vertShader.compile()) { s_program->attachShader( vertShader ); }
		if (fragShader.compile()) { s_program->attachShader( fragShader ); }
		s_program->link();
	}
	m_vbl.push<float>( 2 );
	m_vbl.push<float>( 4 );
	m_vbl.push<float>( 2 );
}
