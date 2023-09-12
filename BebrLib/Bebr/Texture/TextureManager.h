#pragma once
#include "Texture.h"
#include <unordered_map>

namespace bebr
{
	namespace texture
	{
		class TextureManager
		{
		public:
			TextureManager();
			~TextureManager();

			Texture& operator[]( const char* path );

		private:
			std::unordered_map<const char*, Texture*> m_data;
		};
	}
}
