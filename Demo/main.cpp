//#include "Bebr/System/Window.h"
//#include "Bebr/System/Keyboard.h"
//#include "Bebr/Render/Renderer.h"
//
//#include "Bebr/Render/ShaderSource.h"
//#include "Bebr/Render/ShaderProgram.h"
//
//#include "Bebr/Render/VertexArray.h"
//#include "Bebr/Render/VertexBuffer.h"
//#include "Bebr/Render/VertexBufferLayout.h"
//#include "Bebr/Render/IndexBuffer.h"
//
//int main()
//{
//	bebr::system::Window window( 640, 480, "Title" );
//	bebr::system::Keyboard& keyboard = bebr::system::Keyboard::GetInstance();
//	bebr::render::Renderer& renderer = bebr::render::Renderer::GetInstance();
//
//	std::vector<float> vertices = {
//		-0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
//		+0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
//		+0.0f, +0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
//	};
//	std::vector<unsigned int> indices = { 0u, 1u, 2u };
//
//	bebr::render::VertexShader vertShader;
//	bebr::render::FragmentShader fragShader;
//	bebr::render::ShaderProgram program;
//
//	vertShader.attachSource( bebr::render::LoadShaderSource( "Resources/Shaders/test.vert" ).getSource() );
//	fragShader.attachSource( bebr::render::LoadShaderSource( "Resources/Shaders/test.frag" ).getSource() );
//	if (!vertShader.compile()) { return -1; }
//	if (!fragShader.compile()) { return -1; }
//	program.attachShader( vertShader );
//	program.attachShader( fragShader );
//	program.link();
//
//	bebr::render::VertexArray va;
//	bebr::render::VertexBuffer vb;
//	bebr::render::VertexBufferLayout vbl;
//	bebr::render::IndexBuffer ib;
//
//	vbl.push<float>( 2u );
//	vbl.push<float>( 4u );
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
//	program.use();
//	program[ "u_color" ].setFloat4( 1.f, 0.f, 0.f, 0.f );
//
//	while (window.isOpen())
//	{
//		window.pollEvent();
//		if (keyboard.isKeyDown( keyboard.Esc )) { window.close(); }
//
//		renderer.start( &window );
//		renderer.clear( { 0.1f, 0.1f, 0.25f } );
//		renderer.drawTriangle( va, vb, vbl, ib );
//		renderer.display();
//		renderer.end();
//	}
//
//	return 0;
//}

#include "Bebr/Importer/Texture.h"
#include <iostream>
#include <string>

int main()
{
	int width, height;
	unsigned int colors;

    std::cout << "1x2 24 bit:\n";
    unsigned char* data = bebr::importer::texture::LoadBMP( "Resources/Textures/1x2 24bit.bmp", &width, &height, &colors );
    for (int i = 0; i < width * height * 4; i++)
    {
        if (i != 0 && i % (width * 4) == 0) { std::cout << std::endl; }
        std::string num = std::to_string( int( data[ i ] ) ); std::cout << num;
        for (int j = 3 - num.size() + 1; j > 0; j--) { std::cout << ' '; }
    }
    bebr::importer::texture::Free( data );

    std::cout << "\n1x2 32 bit:\n";
    data = bebr::importer::texture::LoadBMP( "Resources/Textures/1x2.bmp", &width, &height, &colors );
    for (int i = 0; i < width * height * 4; i++)
    {
        if (i != 0 && i % (width * 4) == 0) { std::cout << std::endl; }
        std::string num = std::to_string( int( data[ i ] ) ); std::cout << num;
        for (int j = 3 - num.size() + 1; j > 0; j--) { std::cout << ' '; }
    }
    bebr::importer::texture::Free( data );

	return 0;
}
