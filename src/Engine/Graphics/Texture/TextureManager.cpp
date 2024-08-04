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

ITexture *TextureManager::GetTextureByID(int id)
{
    decltype(this->m_textures)::iterator it = this->m_textures.find(id);
    if (it != this->m_textures.end())
    {
        return this->m_textures.at(id).get();
    }
    return nullptr;
}

/**
 * @brief TextureManager::Load
 * Load a texture from file and store it with an ID
 */
void TextureManager::LoadIMG(std::shared_ptr<ITexture> buffer, int id, const char *path)
{
    decltype(this->m_textures)::iterator it = this->m_textures.find(id);
    if (it == this->m_textures.end() && buffer->CreateFromIMG(path))
    {
        this->m_textures[id] = buffer;
    }
}

void TextureManager::LoadTxt(std::shared_ptr<ITexture> buffer, int id, const char* text, AFont* font, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    decltype(this->m_textures)::iterator it = this->m_textures.find(id);
    if (it == this->m_textures.end() && buffer->CreateFromText(text, font, r, g, b, a))
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
    decltype(this->m_textures)::iterator it = this->m_textures.begin();
    while (it != this->m_textures.end())
    {
        it->second->Destroy();
        it++;
    }
}
