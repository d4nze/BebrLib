#pragma once
#include <string>

namespace bebr
{
	namespace render
	{
		class ShaderSource
		{
		public:
			ShaderSource( std::string path );

			const std::string& getSource() const;

			bool operator==( const ShaderSource& other ) const;
			bool operator!=( const ShaderSource& other ) const;

		private:
			std::string m_source = "";
		};

		ShaderSource LoadShaderSource( std::string path );
	}
}
