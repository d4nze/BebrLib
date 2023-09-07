#pragma once

namespace bebr
{
	namespace importer
	{
		namespace image
		{
			unsigned char* Load( const char* path, int* width, int* heigth, unsigned int* colors );
			unsigned char* LoadBMP( const char* path, int* width, int* height, unsigned int* colors );
			unsigned char* LoadJPG( const char* path, int* width, int* heigth, unsigned int* colors );
			unsigned char* LoadPNG( const char* path, int* width, int* heigth, unsigned int* colors );
			void Free( unsigned char* data );
		};
	}
}
