#pragma once
#include "Shape.h"
#include "Shape2Vertex.h"
#include "../Transform/TransformMatrix2.h"
#include "../Shader/ShaderProgram.h"

namespace bebr
{
	namespace shape
	{
		class Shape2 : 
			public Shape<Shape2Vertex>, 
			public transform::TransformMatrix2
		{
		public:
			Shape2();
			void render();

		private:
			static shader::ShaderProgram* s_program;
		};
	}
}
