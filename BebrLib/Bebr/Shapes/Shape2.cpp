#include "Shape2.h"
#include "../Render/ShaderSource.h"

bebr::render::ShaderProgram* bebr::shapes::Shape2::s_program = nullptr;

bebr::shapes::Shape2::Shape2()
{
	if (s_program == nullptr)
	{
		s_program = new render::ShaderProgram;
		bebr::render::VertexShader vertShader;
		bebr::render::FragmentShader fragShader;
		vertShader.attachSource( bebr::render::LoadShaderSource( "Resources/Shaders/test.vert" ).getSource() );
		fragShader.attachSource( bebr::render::LoadShaderSource( "Resources/Shaders/test.frag" ).getSource() );
		if (vertShader.compile()) { s_program->attachShader( vertShader ); }
		if (fragShader.compile()) { s_program->attachShader( fragShader ); }
		s_program->link();
	}
	m_vbl.push<float>( 2 );
	m_vbl.push<float>( 4 );
	m_vbl.push<float>( 2 );
}
