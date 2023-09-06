#pragma once
#include "VertexBufferElement.h"
#include <vector>

namespace bebr
{
	namespace render
	{
		class VertexBufferLayout
		{
		public:
			VertexBufferLayout();

			template<typename T>
			void push( int count = 0 );
			const VertexBufferElement& operator[]( unsigned int index ) const;
			unsigned int getSize() const;
			unsigned int getStrideSize() const;

		private:
			unsigned int m_stridesize;
			std::vector<VertexBufferElement> m_elements;
		};
	}
}
