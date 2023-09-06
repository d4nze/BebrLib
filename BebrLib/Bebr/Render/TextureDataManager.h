#pragma once
#include "TextureData.h"

namespace bebr
{
	namespace render
	{
		class TextureDataManager
		{
		public:
			~TextureDataManager();

		private:
			std::vector<TextureData*> m_data;
		};
	}
}
