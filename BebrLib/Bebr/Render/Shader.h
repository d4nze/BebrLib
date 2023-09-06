#pragma once
#include <string>

namespace bebr
{
	namespace render
	{
		class Shader
		{
		public:
			Shader( unsigned int type );
			~Shader();

			void attachSource( const std::string& source );
			bool compile() const;

		private:
			unsigned int m_id;
			unsigned int m_type;

			friend class ShaderProgram;
		};
	}
}
