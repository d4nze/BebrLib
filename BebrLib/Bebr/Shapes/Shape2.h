#pragma once
#include "Shape.h"
#include "Shape2Vertex.h"
#include "../Render/ShaderProgram.h"

namespace bebr
{
	namespace shapes
	{
		class Shape2 : public Shape<Shape2Vertex>
		{
		public:
			Shape2();

			static render::ShaderProgram* s_program;
		};
	}
}
