#ifndef AFONT_H
#define AFONT_H

class AFont
{
public:
    virtual ~AFont() = default;
    virtual bool OpenFont() = 0;
    virtual void CloseFont() = 0;
    const char *fontName() const;
    void setFontName(const char *newFontName);

    int fontSize() const;
    void setFontSize(int newFontSize);

private:
    const char* m_fontName;
    int m_fontSize;
};

#endif // AFONT_H
