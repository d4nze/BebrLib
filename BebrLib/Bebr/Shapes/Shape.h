#pragma once
#include "../Render/VertexArray.h"
#include "../Render/VertexBuffer.h"
#include "../Render/IndexBuffer.h"

#include <vector>

namespace bebr
{
	namespace shapes
	{
		class Shape
		{
		protected:
			std::vector<float> m_vertices;
			std::vector<unsigned int> m_indices;

			bebr::render::VertexArray m_va;
			bebr::render::VertexBuffer m_vb;
			bebr::render::IndexBuffer m_ib;
		};
	}
}
