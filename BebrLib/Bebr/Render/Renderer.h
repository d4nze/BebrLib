#pragma once
#include "../Core/Colorf.h"

namespace bebr
{
	namespace system { class Window; }
	namespace render
	{
		class VertexArray;
		class VertexBuffer;
		class VertexBufferLayout;
		class IndexBuffer;

		class Renderer
		{
		public:
			static Renderer& GetInstance();

			void start( system::Window* window );
			void end();

			void clear( float r, float g, float b, float a = 1.f ) const;
			void clear( core::Colorf color ) const;
			void _setAttribute( const VertexBuffer& vb );
			void drawTriangle(
				const VertexArray& va, const VertexBuffer& vb,
				const VertexBufferLayout& vbl, int trianglesCount = 1 );
			void drawTriangle(
				const VertexArray& va, const VertexBuffer& vb,
				const VertexBufferLayout& vbl, IndexBuffer& ib );

			void display() const;

		private:
			system::Window* m_currentWindow;

			Renderer();
			~Renderer() = default;
		};
	}
}
