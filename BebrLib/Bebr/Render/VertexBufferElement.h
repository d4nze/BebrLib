#pragma once

namespace bebr
{
	namespace render
	{
		struct VertexBufferElement
		{
			unsigned int type;
			unsigned int typeSize;
			int count;
			unsigned char normalized;
		};
	}
}
