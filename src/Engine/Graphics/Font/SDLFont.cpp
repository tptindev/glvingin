#include "SDLFont.h"

SDLFont::SDLFont(const char* fontName, int fontSize)
{
    this->setFontName(fontName);
    this->setFontSize(fontSize);
}

bool SDLFont::OpenFont()
{
    this->m_data = TTF_OpenFont(this->fontName(), this->fontSize());
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

TTF_Font *SDLFont::data() const
{
    return m_data;
}
