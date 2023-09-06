#pragma once
#include <vector>

namespace bebr
{
	namespace render
	{
		struct TextureData
		{
			enum ColorType
			{
				RGB, RGBA, // Grayscale, IndexColor, Depth, Stencil, Compressed wtf
			};
			ColorType colorType;
			std::vector<unsigned char> data;
		};
	}
}
