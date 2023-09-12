#pragma once
#include "Shape.h"
#include "Shape2Vertex.h"
#include "../Shader/ShaderProgram.h"

namespace bebr
{
	namespace shape
	{
		class Shape2 : public Shape<Shape2Vertex>
		{
		public:
			Shape2();

			static shader::ShaderProgram* s_program;
		};
	}
}
