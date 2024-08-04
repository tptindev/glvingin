#include "AFont.h"

const char *AFont::fontName() const
{
    return m_fontName;
}

void AFont::setFontName(const char *newFontName)
{
    m_fontName = newFontName;
}

int AFont::fontSize() const
{
    return m_fontSize;
}

void AFont::setFontSize(int newFontSize)
{
    m_fontSize = newFontSize;
}
