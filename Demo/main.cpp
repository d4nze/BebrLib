#include "Bebr/System/Window.h"
#include "Bebr/System/Keyboard.h"
#include "Bebr/Render/Renderer.h"

#include "Bebr/Shapes/Shape2Vertex.h"

#include "Bebr/Render/ShaderSource.h"
#include "Bebr/Render/ShaderProgram.h"

#include "Bebr/Render/VertexArray.h"
#include "Bebr/Render/VertexBuffer.h"
#include "Bebr/Render/VertexBufferLayout.h"
#include "Bebr/Render/IndexBuffer.h""

#include "Bebr/Render/Texture.h"

int main()
{
	bebr::system::Window window( 640, 480, "Title" );
	bebr::system::Keyboard& keyboard = bebr::system::Keyboard::GetInstance();
	bebr::render::Renderer& renderer = bebr::render::Renderer::GetInstance();

	std::vector<bebr::shapes::Shape2Vertex> vertices = {
		{ { -0.5f, +0.5f }, { 1.f, 1.f, 1.f, 1.f }, { 0.f, 1.f } } ,
		{ { +0.5f, +0.5f }, { 1.f, 1.f, 1.f, 1.f }, { 1.f, 1.f } } ,
		{ { +0.5f, -0.5f }, { 1.f, 1.f, 1.f, 1.f }, { 1.f, 0.f } } ,
		{ { -0.5f, -0.5f }, { 1.f, 1.f, 1.f, 1.f }, { 0.f, 0.f } } 
	};
	std::vector<unsigned int> indices = { 0u, 1u, 2u, 0u, 3u, 2u };

	bebr::render::VertexShader vertShader;
	bebr::render::FragmentShader fragShader;
	bebr::render::ShaderProgram program;

	vertShader.attachSource( bebr::render::LoadShaderSource( "Resources/Shaders/test.vert" ).getSource() );
	fragShader.attachSource( bebr::render::LoadShaderSource( "Resources/Shaders/test.frag" ).getSource() );
	if (!vertShader.compile()) { return -1; }
	if (!fragShader.compile()) { return -1; }
	program.attachShader( vertShader );
	program.attachShader( fragShader );
	program.link();

	bebr::render::VertexArray va;
	bebr::render::VertexBuffer vb;
	bebr::render::VertexBufferLayout vbl;
	bebr::render::IndexBuffer ib;

	vbl.push<float>( 2u );
	vbl.push<float>( 4u );
	vbl.push<float>( 2u );

	va.bind();
	vb.bind();
	vb.setData( vertices );
	ib.bind();
	ib.setData( indices );
	va.unbind();
	vb.unbind();
	ib.unbind();

	bebr::render::Texture texture;
	texture.load( "Resources/Textures/PNG test.png" );
	texture.bind();
	texture.setWrapping( texture.Repeat );
	texture.setFilter( texture.Nearest );
	texture.generateMipmap();
	texture.unbind();

	while (window.isOpen())
	{
		window.pollEvent();
		if (keyboard.isKeyDown( keyboard.Esc )) { window.close(); }

		renderer.start( &window );
		renderer.clear( { 0.1f, 0.1f, 0.25f } );

		program.use();
		program[ "u_texture" ].setInt1( 0 );
		texture.bind();
		texture.bufferData();
		va.bind();
		va.updateAttribute( vb, vbl );
		ib.bind();
		renderer.drawTriangle( ib );
		ib.unbind();
		va.unbind();
		texture.unbind();
		program.unuse();

		renderer.display();
		renderer.end();
	}

	return 0;
}
