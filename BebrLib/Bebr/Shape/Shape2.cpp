#include "Shape2.h"
#include "../shader/ShaderSource.h"

bebr::shader::ShaderProgram* bebr::shape::Shape2::s_program = nullptr;

bebr::shape::Shape2::Shape2() : Shape<Shape2Vertex>(), transform::TransformMatrix2()
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
}

void bebr::shape::Shape2::setVertices( std::vector<Shape2Vertex>& vertices )
{
	m_vertices = vertices;
}

void bebr::shape::Shape2::setIndices( std::vector<unsigned int>& indices )
{
	m_indices = indices;
}

#include "../Render/Renderer.h"
#include <string>

void bebr::shape::Shape2::render()
{
	static render::Renderer& s_renderer = render::Renderer::GetInstance();
	s_program->use();
	(*s_program)[ "u_camera" ].setMat4( s_renderer.m_currentCamera->getMatrix() );
	(*s_program)[ "u_transform" ].setMat4( TransformMatrix2::getMatrix() );
	(*s_program)[ "u_texture" ].setInt1( 0 );
	Shape<Shape2Vertex>::render();
	s_program->unuse();
}
