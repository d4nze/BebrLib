#pragma once
#include "../Core/Colorf.h"
#include "../Camera/CameraMatrix2.h"

namespace bebr
{
	namespace system { class Window; }
	namespace buffer { class IndexBuffer; }
	namespace shape { class Shape2; }
	namespace render
	{
		class Renderer
		{
		public:
			static Renderer& GetInstance();

			void start( system::Window* window );
			void start( system::Window* window, camera::CameraMatrix2* camera );
			void end();

			void clear( float r, float g, float b, float a = 1.f ) const;
			void clear( core::Colorf color ) const;
			void drawTriangle( buffer::IndexBuffer& ib );

			void display() const;

		private:
			system::Window* m_currentWindow;
			camera::CameraMatrix2* m_currentCamera;

			friend class shape::Shape2;

			Renderer();
			~Renderer() = default;
		};
	}
}
