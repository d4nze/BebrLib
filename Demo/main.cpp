#include "Bebr/System/Window.h"
#include "Bebr/System/Keyboard.h"
#include "Bebr/Render/Renderer.h"
#include "Bebr/Camera/CameraMatrix2.h"

#include "Bebr/Shape/Shape2Vertex.h"

#include "Bebr/Shader/ShaderSource.h"
#include "Bebr/Shader/ShaderProgram.h"

#include "Bebr/Buffer/VertexBuffer.h"
#include "Bebr/Buffer/IndexBuffer.h"
#include "Bebr/Render/VertexArray.h"
#include "Bebr/Render/VertexBufferLayout.h"

#include "Bebr/Transform/TransformMatrix2.h"
#include "Bebr/Texture/TextureManager.h"

//int main()
//{
//	bebr::system::Window window( 640, 480, "Another mario forever fan game" );
//	window.setMaxFrameRate( 144u );
//	bebr::system::Keyboard& keyboard = bebr::system::Keyboard::GetInstance();
//	bebr::render::Renderer& renderer = bebr::render::Renderer::GetInstance();
//	bebr::camera::CameraMatrix2 camera;
//	camera.setCenter( 0.f, 0.f );
//	camera.setSize( 640.f, 480.f );
//
//	std::vector<bebr::shape::Shape2Vertex> vertices = {
//		{ { -16.f, +16.f }, { 1.f, 1.f, 1.f, 1.f }, { 0.f, 1.f } },
//		{ { +16.f, +16.f }, { 1.f, 1.f, 1.f, 1.f }, { 1.f, 1.f } },
//		{ { +16.f, -16.f }, { 1.f, 1.f, 1.f, 1.f }, { 1.f, 0.f } },
//		{ { -16.f, -16.f }, { 1.f, 1.f, 1.f, 1.f }, { 0.f, 0.f } } 
//	};
//	std::vector<unsigned int> indices = { 0u, 1u, 2u, 0u, 3u, 2u };
//
//	bebr::shader::ShaderProgram program;
//	bebr::shader::VertexShader vertShader;
//	bebr::shader::FragmentShader fragShader;
//
//	vertShader.attachSource( bebr::shader::LoadShaderSource( "Resources/Shaders/test.vert" ).getSource() );
//	fragShader.attachSource( bebr::shader::LoadShaderSource( "Resources/Shaders/test.frag" ).getSource() );
//	if (!vertShader.compile()) { return -1; }
//	if (!fragShader.compile()) { return -1; }
//	program.attachShader( vertShader );
//	program.attachShader( fragShader );
//	program.link();
//
//	bebr::buffer::VertexBuffer vb;
//	bebr::buffer::IndexBuffer ib;
//	bebr::render::VertexArray va;
//	bebr::render::VertexBufferLayout vbl;
//
//	vbl.push<float>( 2u );
//	vbl.push<float>( 4u );
//	vbl.push<float>( 2u );
//
//	va.bind();
//	vb.bind();
//	vb.setData( vertices );
//	ib.bind();
//	ib.setData( indices );
//	va.unbind();
//	vb.unbind();
//	ib.unbind();
//
//	bebr::transform::TransformMatrix2 transform;
//	bebr::texture::TextureManager textureManager;
//	bebr::texture::Texture& texture = textureManager[ "Resources/Textures/PNG test.png" ];
//
//	while (window.isOpen())
//	{
//		window.pollEvent();
//		
//		if (keyboard.isKeyDown( keyboard.Esc )) { window.close(); }
//
//		if (keyboard.isKeyDown( keyboard.LeftArrow )) { camera.move( -5.f, 0.f ); }
//		if (keyboard.isKeyDown( keyboard.RightArrow )) { camera.move( +5.f, 0.f ); }
//		if (keyboard.isKeyDown( keyboard.UpArrow )) { camera.move( 0.f, +5.f ); }
//		if (keyboard.isKeyDown( keyboard.DownArrow )) { camera.move( 0.f, -5.f ); }
//
//		renderer.start( &window, &camera );
//		renderer.clear( { 0.1f, 0.1f, 0.25f } );
//
//		program.use();
//		program[ "u_camera" ].setMat4( camera.getMatrix() );
//		program[ "u_transform" ].setMat4( transform.getMatrix() );
//		program[ "u_texture" ].setInt1( 0 );
//		texture.bind();
//		texture.bufferData();
//		va.bind();
//		va.updateAttribute( vb, vbl );
//		ib.bind();
//		renderer.drawTriangle( ib );
//		ib.unbind();
//		va.unbind();
//		texture.unbind();
//		program.unuse();
//
//		renderer.display();
//		renderer.end();
//	}
//
//	return 0;
//}

#include "Bebr/Shape/Shape2.h"

int main()
{
	bebr::system::Window window( 640, 480, "Another mario forever fan game" );
	window.setMaxFrameRate( 144u );
	bebr::system::Keyboard& keyboard = bebr::system::Keyboard::GetInstance();
	bebr::render::Renderer& renderer = bebr::render::Renderer::GetInstance();
	bebr::camera::CameraMatrix2 camera;
	camera.setCenter( 0.f, 0.f );
	camera.setSize( 640.f, 480.f );

	bebr::shape::Shape2 shape;

	std::vector<bebr::shape::Shape2Vertex> vertices = {
		{ { -16.f, +16.f }, { 1.f, 1.f, 1.f, 1.f }, { 0.f, 1.f } },
		{ { +16.f, +16.f }, { 1.f, 1.f, 1.f, 1.f }, { 1.f, 1.f } },
		{ { +16.f, -16.f }, { 1.f, 1.f, 1.f, 1.f }, { 1.f, 0.f } },
		{ { -16.f, -16.f }, { 1.f, 1.f, 1.f, 1.f }, { 0.f, 0.f } }
	};
	shape.setVertices( vertices );
	std::vector<unsigned int> indices = { 0u, 1u, 2u, 0u, 3u, 2u };
	shape.setIndices( indices );
	shape.setData();

	bebr::texture::TextureManager textureManager;
	bebr::texture::Texture& texture = textureManager[ "Resources/Textures/PNG test.png" ];
	shape.setTexture( &texture );

	while (window.isOpen())
	{
		window.pollEvent();

		if (keyboard.isKeyDown( keyboard.Esc )) { window.close(); }

		if (keyboard.isKeyDown( keyboard.LeftArrow )) { camera.move( -5.f, 0.f ); }
		if (keyboard.isKeyDown( keyboard.RightArrow )) { camera.move( +5.f, 0.f ); }
		if (keyboard.isKeyDown( keyboard.UpArrow )) { camera.move( 0.f, +5.f ); }
		if (keyboard.isKeyDown( keyboard.DownArrow )) { camera.move( 0.f, -5.f ); }

		renderer.start( &window, &camera );
		renderer.clear( { 0.1f, 0.1f, 0.25f } );

		shape.render();

		renderer.display();
		renderer.end();
	}

	return 0;
}
