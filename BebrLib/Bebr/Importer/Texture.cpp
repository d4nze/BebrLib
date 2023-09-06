#include "Texture.h"
#include <fstream>

#pragma pack(push, 1) // отключение выравнивания байт
struct BMPheader24 {
    char signature[ 2 ];
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t dataOffset;
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t totalColors;
    uint32_t importantColors;
};

struct BMPheader32 {
    char signature[ 2 ];
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t dataOffset;
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t totalColors;
    uint32_t importantColors;
    uint32_t redMask;
    uint32_t greenMask;
    uint32_t blueMask;
    uint32_t alphaMask;
    uint32_t colorSpaceType;
    int32_t redX;
    int32_t redY;
    int32_t redZ;
    int32_t greenX;
    int32_t greenY;
    int32_t greenZ;
    int32_t blueX;
    int32_t blueY;
    int32_t blueZ;
    uint32_t gammaRed;
    uint32_t gammaGreen;
    uint32_t gammaBlue;
};
#pragma pack(pop) // включение выравнивания байт

unsigned char* bebr::importer::texture::LoadBMP( const char* path, int* width, int* height, unsigned int* colors )
{
    *width = 0;
    *height = 0;
    *colors = 0;

    std::ifstream fin( path, std::ios::binary );
    if (!fin.is_open()) { return nullptr; }

    BMPheader24 header24;
    BMPheader32 header32;

    fin.read( reinterpret_cast<char*>(&header24), sizeof( BMPheader24 ) );

    if (header24.signature[ 0 ] != 'B' || header24.signature[ 1 ] != 'M') { return nullptr; }

    if (header24.bitsPerPixel == 24) {
        *width = header24.width;
        *height = header24.height;
        *colors = header24.bitsPerPixel / 8u;
    }
    else if (header24.bitsPerPixel == 32)
    {
        fin.seekg( 0 );
        fin.read( reinterpret_cast<char*>(&header32), sizeof( BMPheader32 ) );
        *width = header32.width;
        *height = header32.height;
        *colors = header32.bitsPerPixel / 8u;
        fin.seekg( header32.dataOffset );
    }
    else { return nullptr; }

    size_t dataSize = static_cast<size_t>(*width) * static_cast<size_t>(*height) * 4;
    unsigned char* data = new unsigned char[ dataSize ];

    fin.read( reinterpret_cast<char*>(data), dataSize );
    fin.close();

    return data;
}

void bebr::importer::texture::Free( unsigned char* data )
{
    if (data != nullptr) { delete[] data; }
}

unsigned char* bebr::importer::texture::BGRAtoRGB( unsigned char* data )
{
    return nullptr;
}
