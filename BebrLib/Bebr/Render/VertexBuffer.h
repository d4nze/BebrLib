#pragma once
#include "Buffer.h"
#include <vector>

namespace bebr
{
	namespace render
	{
		class VertexBuffer : Buffer
		{
		public:
			VertexBuffer();
			~VertexBuffer();

			void bind() const;
			void unbind() const;

			void setData( const void* data, unsigned int size ) const;
			void updateData( const void* data, unsigned int size ) const;

			template<typename T>
			void setData( const std::vector<T>& data ) const;
			template<typename T>
			void updateData( const std::vector<T>& data ) const;

		private:
			static void Bind( unsigned int id );
			static unsigned int s_currentId;
		};
	}
}
