#pragma once
#include "../Core/Coloru.h"

namespace bebr
{
	namespace texture
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

			enum WrappingType { Repeat = 0, MirroredRepeat, ClampToEdge, ClampToBorder };
			void setWrapping( WrappingType type = Repeat );

			enum FilterType { Nearest = 0, Linear };
			void setFilter( FilterType type = Nearest );

			void setPixel( int x, int y, core::Coloru color );
			core::Coloru getPixel( int x, int y );

			int getWidth();
			int getHeigth();

		private:
			static void Bind( unsigned int id );

		protected:
			unsigned char* m_data;
			int m_width, m_height, m_colors;

		private:
			unsigned int m_id;
			static unsigned int s_currentId;
		};
	}
}
