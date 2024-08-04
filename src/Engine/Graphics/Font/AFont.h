#ifndef AFONT_H
#define AFONT_H

class AFont
{
public:
    virtual ~AFont() = default;
    virtual bool OpenFont() = 0;
    virtual void CloseFont() = 0;
    virtual void* Data() = 0;
    const char *fontName() const;
    void setFontName(const char *newFontName);

    int fontSize() const;
    void setFontSize(int newFontSize);


    const char *fontFilePath() const;
    void setFontFilePath(const char *newFontFilePath);

private:
    const char* m_fontName;
    const char* m_fontFilePath;
    int m_fontSize;
};

#endif // AFONT_H
