#include "StandartTexture.h"

bebr::texture::StandartTexture& bebr::texture::StandartTexture::GetInstance()
{
	static StandartTexture s_texture;
	return s_texture;
}

bebr::texture::StandartTexture::StandartTexture()
{
	create(1, 1);
	setPixel(0, 0, core::Colorf::White);
	bind();	
	setWrapping(Repeat);
	setFilter(Nearest);
	generateMipmap();
	unbind();
}
