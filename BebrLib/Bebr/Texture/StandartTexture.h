#pragma once
#include "Texture.h"

namespace bebr
{
	namespace texture
	{
		class StandartTexture : public Texture
		{
		public:
			static StandartTexture& GetInstance();

		private:
			StandartTexture();
		};
	}
}

