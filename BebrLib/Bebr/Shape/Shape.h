#pragma once
#include "../Render/VertexArray.h"
#include "../Render/VertexBufferLayout.h"
#include "../Buffer/VertexBuffer.h"
#include "../Buffer/IndexBuffer.h"
#include "../Texture/Texture.h"

#include <vector>

namespace bebr
{
	namespace shape
	{
		template<typename VertexType>
		class Shape
		{
		public:
			Shape();

			void setTexture( texture::Texture* texture );

		protected:
			void setData();
			void updateData();
			void render();

			std::vector<VertexType> m_vertices;
			std::vector<unsigned int> m_indices;
			bebr::render::VertexBufferLayout m_vbl;
			bebr::texture::Texture* m_texture;

		private:
			bebr::render::VertexArray m_va;
			bebr::buffer::VertexBuffer m_vb;
			bebr::buffer::IndexBuffer m_ib;
		};
	}
}
