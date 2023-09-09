#pragma once
#include "../Math/Vector2.h"
#include "../Core/Colorf.h"

namespace bebr
{
	namespace shapes
	{
		struct Shape2Vertex
		{
			math::Vector2f position;
			core::Colorf color;
			math::Vector2f texCoords;
		};
	}
}
