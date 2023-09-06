#pragma once
#include <vector>

#include "VertexShader.h"
#include "FragmentShader.h"
#include "ShaderUniform.h"

namespace bebr
{
	namespace render
	{
		class ShaderProgram
		{
		public:
			ShaderProgram();
			~ShaderProgram();

			void attachShader( const VertexShader& vertexShader ) const;
			void attachShader( const FragmentShader& fragmentShader ) const;

			void link() const;
			void use() const;
			void unuse() const;

			const ShaderUniform& operator[]( std::string uniformName );

		private:
			static void Use( unsigned int id );

			static unsigned int s_currentId;
			unsigned int m_id;
			std::vector<ShaderUniform> m_uniforms;
		};
	}
}
