#ifndef AFONT_H
#define AFONT_H

class AFont
{
public:
    virtual ~AFont() = default;
    virtual bool OpenFont() = 0;
    virtual void CloseFont() = 0;
    virtual void* Data() = 0;

    int id() const;
    void setId(int newId);

    int fontSize() const;
    void setFontSize(int newFontSize);


    const char *fontFilePath() const;
    void setFontFilePath(const char *newFontFilePath);



private:
    int m_id;
    const char* m_fontFilePath;
    int m_fontSize;
};

#endif // AFONT_H
