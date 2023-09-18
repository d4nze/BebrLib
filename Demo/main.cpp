#include <Bebr/System/Window.h>
#include <Bebr/System/Keyboard.h>
#include <Bebr/System/Mouse.h>
#include <Bebr/Render/Renderer.h>
#include <Bebr/Camera/CameraMatrix2.h>

#include <Bebr/Shape/Circle.h>
#include <Bebr/Texture/TextureManager.h>

int main()
{
	bebr::system::Window window( 640, 480, "Another mario forever fan game" );
	window.setMaxFrameRate( 144u );
	bebr::system::Keyboard& keyboard = bebr::system::Keyboard::GetInstance();
	bebr::system::Mouse& mouse = bebr::system::Mouse::GetInstance();
	bebr::render::Renderer& renderer = bebr::render::Renderer::GetInstance();
	bebr::camera::CameraMatrix2 camera;
	camera.setCenter( 0.f, 0.f );
	camera.setSize( 640.f / 4.f, 480.f / 4.f );
	
	bebr::shape::Circle shape( 0.f, 0.f, 32.f, 32.f );
	shape.setCount( 32 );

	bebr::texture::TextureManager textureManager;
	bebr::texture::Texture& texture = textureManager[ "Resources/Textures/Block Brown.png" ];
	shape.setTexture( &texture );
	shape.setTextureRectangle( { { 0.f, 0.f }, { 16.f, 16.f } } );

	while (window.isOpen())
	{
		window.pollEvent();

		if (keyboard.isKeyDown( keyboard.Esc )) { window.close(); }
		if (keyboard.isKeyPressed( keyboard.F11 )) { window.setFullscreen(!window.getFullscreen()); }

		shape.rotate( 5.f );

		if (keyboard.isKeyDown( keyboard.LeftArrow )) { camera.move( -5.f, 0.f ); }
		if (keyboard.isKeyDown( keyboard.RightArrow )) { camera.move( +5.f, 0.f ); }
		if (keyboard.isKeyDown( keyboard.UpArrow )) { camera.move( 0.f, +5.f ); }
		if (keyboard.isKeyDown( keyboard.DownArrow )) { camera.move( 0.f, -5.f ); }
		if (keyboard.isKeyDown( keyboard.R )) { camera.setCenter( 0.0, 0.0 ); }

		shape.setPosition( camera.getMousePos( mouse.getPosition(), window.getSize() ) );

		renderer.start( &window, &camera );
		renderer.clear( { 0.1f, 0.1f, 0.25f } );

		shape.render();

		renderer.display();
		renderer.end();
	}

	return 0;
}