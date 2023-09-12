#pragma once

namespace bebr
{
	namespace buffer { class VertexBuffer; }
	namespace render { class VertexBufferLayout; }
	namespace render
	{
		class VertexArray
		{
		public:
			VertexArray();
			~VertexArray();

			void bind() const;
			void unbind() const;
			void updateAttribute( const buffer::VertexBuffer& vb, const VertexBufferLayout& vbl ) const;

		private:
			static void Bind( unsigned int id );

			unsigned int m_id;
			static unsigned int s_currentId;
		};
	}
}
