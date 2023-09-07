#pragma once
#include "../Render/VertexArray.h"
#include "../Render/VertexBuffer.h"
#include "../Render/IndexBuffer.h"
#include "../Render/Texture.h"

#include <vector>

namespace bebr
{
	namespace shapes
	{
		class Shape
		{
		public:
			Shape();
			void render();

			std::vector<float> m_vertices;
			std::vector<unsigned int> m_indices;

			bebr::render::VertexArray m_va;
			bebr::render::VertexBuffer m_vb;
			bebr::render::IndexBuffer m_ib;
			bebr::render::Texture* m_texture;
		};
	}
}
