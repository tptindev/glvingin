#include "TextureManager.h"
#include <iostream>

TextureManager *TextureManager::s_instance = nullptr;
TextureManager::TextureManager()
{
    std::cout << __FUNCTION__ << std::endl;
}

TextureManager *TextureManager::Instance()
{
    if (TextureManager::s_instance == nullptr)
    {
        TextureManager::s_instance = new TextureManager();
    }
    return TextureManager::s_instance;
}

void TextureManager::ResetInstance()
{
    if (TextureManager::s_instance != nullptr)
    {
        delete TextureManager::s_instance;
        TextureManager::s_instance = nullptr;
    }
    return;
}

TextureManager::~TextureManager()
{
    std::cout << __FUNCTION__ << std::endl;
}

ITexture *TextureManager::GetTextureByID(int id) const
{
    return this->m_textures.at(id).get();
}

/**
 * @brief TextureManager::Load
 * Load a texture from file and store it with an ID
 */
void TextureManager::Load(std::shared_ptr<ITexture> buffer, int id, const char *path)
{
    if (buffer->Create(path))
    {
        this->m_textures[id] = buffer;
    }
}

/**
 * @brief TextureManager::Clean
 * Clean up all loaded textures
 */
void TextureManager::Clean()
{
    
}
