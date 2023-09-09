#pragma once
#include "../Render/VertexArray.h"
#include "../Render/VertexBuffer.h"
#include "../Render/VertexBufferLayout.h"
#include "../Render/IndexBuffer.h"
#include "../Render/Texture.h"

#include <vector>

namespace bebr
{
	namespace shapes
	{
		template<typename VertexType>
		class Shape
		{
		public:
			Shape();

			std::vector<VertexType> m_vertices;
			std::vector<unsigned int> m_indices;

			bebr::render::VertexArray m_va;
			bebr::render::VertexBuffer m_vb;
			bebr::render::VertexBufferLayout m_vbl;
			bebr::render::IndexBuffer m_ib;

			bebr::render::Texture* m_texture;
		};
	}
}
