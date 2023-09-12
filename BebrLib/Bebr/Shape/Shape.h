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

			std::vector<VertexType> m_vertices;
			std::vector<unsigned int> m_indices;

			bebr::render::VertexArray m_va;
			bebr::render::VertexBufferLayout m_vbl;
			bebr::buffer::VertexBuffer m_vb;
			bebr::buffer::IndexBuffer m_ib;

			bebr::texture::Texture* m_texture;
		};
	}
}
