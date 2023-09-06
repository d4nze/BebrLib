#pragma once

namespace bebr
{
	namespace render
	{
		class VertexBuffer;
		class VertexBufferLayout;

		class VertexArray
		{
		public:
			VertexArray();
			~VertexArray();

			void bind() const;
			void unbind() const;
			void updateAttribute( const VertexBuffer& vb, const VertexBufferLayout& vbl ) const;

		private:
			static void Bind( unsigned int id );

			unsigned int m_id;
			static unsigned int s_currentId;
		};
	}
}
