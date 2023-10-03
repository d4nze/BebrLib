#include <Bebr/Camera/CameraMatrix2.h>
#include <Bebr/System/Keyboard.h>
#include <Bebr/Render/Renderer.h>
#include <Bebr/System/Window.h>

int main()
{
	bebr::system::Window window(640, 480, "rects");
	window.setMaxFrameRate(144u);
	bebr::camera::CameraMatrix2 camera;
	camera.setCenter(0.f, 0.f);
	camera.setSize(640.f / 4.f, 480.f / 4.f);
	bebr::system::Keyboard& keyboard = bebr::system::Keyboard::GetInstance();
	bebr::render::Renderer& renderer = bebr::render::Renderer::GetInstance();

	while (window.isOpen())
	{
		window.pollEvent();

		if (keyboard.isKeyDown(keyboard.Esc)) { window.close(); }
		if (keyboard.isKeyPressed(keyboard.F11)) { window.setFullscreen(!window.getFullscreen()); }

		renderer.start(&window, &camera);
		renderer.clear({ 0.1f, 0.1f, 0.25f });

		// Render here..

		renderer.display();
		renderer.end();
	}

	return 0;
}
