#include <Bebr/Collision/RectColliderPro.h>
#include <Bebr/Camera/CameraMatrix2.h>
#include <Bebr/Shape/Rectangle.h>
#include <Bebr/System/Keyboard.h>
#include <Bebr/Render/Renderer.h>
#include <Bebr/System/Window.h>
#include <Bebr/System/Mouse.h>

int main()
{
	bebr::system::Window window(640, 480, "rects");
	window.setMaxFrameRate(144u);
	bebr::system::Keyboard& keyboard = bebr::system::Keyboard::GetInstance();
	bebr::system::Mouse& mouse = bebr::system::Mouse::GetInstance();
	mouse.setIcon(mouse.Arrow);
	bebr::render::Renderer& renderer = bebr::render::Renderer::GetInstance();
	bebr::camera::CameraMatrix2 camera;
	camera.setCenter(0.f, 0.f);
	camera.setSize(640.f / 4.f, 480.f / 4.f);

	bebr::shape::Rectangle shape1(0.f, 0.f, 32.f, 32.f);
	shape1.setOrigin(16.f, 16.f);
	// shape1.setScale(1.f, 1.f);
	shape1.setAngle(15.f);

	bebr::shape::Rectangle shape2(0.f, 0.f, 64.f, 64.f);
	shape2.setOrigin(32.f, 32.f);
	// shape2.setScale({ 1.f, 1.f });
	shape2.setColor(bebr::core::Colorf::Red);

	bebr::collision::RectColliderPro collider1;
	bebr::collision::RectColliderPro collider2;

	while (window.isOpen())
	{
		window.pollEvent();

		if (keyboard.isKeyDown(keyboard.Esc)) { window.close(); }
		if (keyboard.isKeyPressed(keyboard.F11)) { window.setFullscreen(!window.getFullscreen()); }

		if (keyboard.isKeyPressed(keyboard.LeftArrow)) { shape1.rotate(-15.f); }
		if (keyboard.isKeyPressed(keyboard.RightArrow)) { shape1.rotate(15.f); }
		if (keyboard.isKeyPressed(keyboard.A)) { shape2.rotate(-15.f); }
		if (keyboard.isKeyPressed(keyboard.D)) { shape2.rotate(15.f); }

		collider1 = shape1;
		collider2 = shape2;

		if (collider1.collides(collider2) || collider2.collides(collider1)) { shape1.setColor(bebr::core::Colorf::Green); }
		else { shape1.setColor(bebr::core::Colorf::Blue); }

		shape1.setPosition(camera.getMousePos(mouse.getPosition(), window.getSize()));

		renderer.start(&window, &camera);
		renderer.clear({ 0.1f, 0.1f, 0.25f });

		shape2.render();
		shape1.render();

		renderer.display();
		renderer.end();
	}

	return 0;
}
