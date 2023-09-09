#pragma once
#include "../Core/Coloru.h"

namespace bebr
{
	namespace render
	{
		class Texture
		{
		public:
			Texture();
			~Texture();

			void load( const char* path );
			void create( int width, int height );

			void bind();
			void unbind();

			void generateMipmap();
			void bufferData();

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

			void setPixel( int x, int y, core::Coloru color );
			core::Coloru getPixel( int x, int y );

			int getWidth();
			int getHeigth();

		private:
			static void Bind( unsigned int id );

		protected:
			unsigned char* m_data;
			int m_width, m_height;
			unsigned int m_colors;

		private:
			unsigned int m_id;
			static unsigned int s_currentId;
		};
	}
}
