#include "AFont.h"
int AFont::fontSize() const
{
    return m_fontSize;
}

void AFont::setFontSize(int newFontSize)
{
    m_fontSize = newFontSize;
}

const char *AFont::fontFilePath() const
{
    return m_fontFilePath;
}

void AFont::setFontFilePath(const char *newFontFilePath)
{
    m_fontFilePath = newFontFilePath;
}

int AFont::id() const
{
    return m_id;
}

void AFont::setId(int newId)
{
    m_id = newId;
}
