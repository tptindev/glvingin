#include "FontManager.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "AFont.h"

FontManager* FontManager::s_instance = nullptr;
FontManager::FontManager()
{
    std::cout << __FUNCTION__ << std::endl;
}

FontManager::~FontManager()
{
    decltype(this->m_fonts)::iterator it = this->m_fonts.begin();
    while (it != this->m_fonts.end())
    {
        it->second->CloseFont();
        it++;
    }

    std::cout << __FUNCTION__ << std::endl;
}

AFont* FontManager::Load(std::shared_ptr<AFont> font)
{
    decltype(this->m_fonts)::iterator it = this->m_fonts.find(font->id());
    if (it != this->m_fonts.end())
    {
        return it->second.get();
    }
    if (!font->OpenFont())
    {
        return nullptr;
    }
    this->m_fonts[font->id()] = font;
    return font.get();
}

AFont *FontManager::GetFont(int fontID)
{
    decltype(this->m_fonts)::iterator it = this->m_fonts.find(fontID);
    if (it != this->m_fonts.end())
    {
        return it->second.get();
    }
    return nullptr;
}

FontManager *FontManager::Instance()
{
    if (FontManager::s_instance == nullptr)
    {
        FontManager::s_instance = new FontManager();
    }
    return FontManager::s_instance;
}

void FontManager::ResetInstance()
{
    if (FontManager::s_instance != nullptr)
    {
        delete FontManager::s_instance;
        FontManager::s_instance = nullptr;
    }
    return;
}

