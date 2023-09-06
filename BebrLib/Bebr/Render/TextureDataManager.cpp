#include "TextureDataManager.h"

bebr::render::TextureDataManager::~TextureDataManager()
{
	for (TextureData* data : m_data)
	{
		delete data;
		data = nullptr;
	}
}
