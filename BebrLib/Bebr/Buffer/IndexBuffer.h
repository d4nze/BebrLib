#pragma once
#include "Buffer.h"
#include <vector>

namespace bebr
{
	namespace buffer
	{
		class IndexBuffer : Buffer
		{
		public:
			IndexBuffer();
			~IndexBuffer();

			void bind() const;
			void unbind() const;

			template<typename T>
			void setData( T* data, unsigned int size );
			template<typename T>
			void setData( std::vector<T>& data );

			template<typename T>
			void updateData( T* data, unsigned int size );
			template<typename T>
			void updateData( std::vector<T>& data );

			unsigned int getType() const;
			unsigned int getSize() const;

		private:
			template<typename T>
			void updateType();

			static void Bind( unsigned int id );

			unsigned int m_id;
			unsigned int m_type;
			unsigned int m_size;
			static unsigned int s_currentId;
		};
	}
}
