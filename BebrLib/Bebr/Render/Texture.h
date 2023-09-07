#pragma once
#include "TextureData.h"

namespace bebr
{
	namespace render
	{
		class Texture
		{
		public:
			Texture();

			void load( const char* path );
			void create( int width, int heigth );

			void bind();
			void unbind();

			static enum WrappingType
			{
				Repeat = 0,
				MirroredRepeat = 1,
				ClampToEdge = 2,
				ClampToBorder = 3
			};
			void setWrapping( WrappingType type = Repeat );

			static enum FilterType
			{
				Nearest = 0,
				Linear = 1
			};
			void setFilter( FilterType type = Nearest );

			int getWidth();
			int getHeigth();

		protected:
			unsigned char* m_data;
			int m_width, m_height;

		private:
			unsigned int m_id;
		};
	}
}
