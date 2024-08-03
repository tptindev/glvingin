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

/**
 * @brief TextureManager::Load
 * Load a texture from file and store it with an ID
 */
void TextureManager::Load(int id, const char *path)
{
    this->m_textures[id] = nullptr;
}

/**
 * @brief TextureManager::Render
 * Render a texture to the screen
 */
void TextureManager::Render()
{
    
}

/**
 * @brief TextureManager::RenderFrame
 * Render a portion of a texture (useful for sprite sheets)
 */
void TextureManager::RenderFrame()
{
    
}

/**
 * @brief TextureManager::Clean
 * Clean up all loaded textures
 */
void TextureManager::Clean()
{
    
}
