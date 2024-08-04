#include "SDLFont.h"

SDLFont::SDLFont(const char* fontName, const char* fontFilePath, int fontSize)
{
    this->setFontName(fontName);
    this->setFontFilePath(fontFilePath);
    this->setFontSize(fontSize);
}

SDLFont::~SDLFont()
{

}

bool SDLFont::OpenFont()
{
    this->m_data = TTF_OpenFont(this->fontFilePath(), this->fontSize());
    if (this->m_data == nullptr)
    {
        return false;
    }
    return true;
}

void SDLFont::CloseFont()
{
    if (this->m_data != nullptr)
    {
        TTF_CloseFont(this->m_data);
    }
}

void *SDLFont::Data()
{
    return reinterpret_cast<void*>(m_data);
}
