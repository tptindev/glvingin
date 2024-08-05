#ifndef SDLFONT_H
#define SDLFONT_H

#include "AFont.h"
#include <SDL2/SDL_ttf.h>

class SDLFont : public AFont
{
public:
    explicit SDLFont(int id, const char* fontFilePath, int fontSize);
    ~SDLFont();
    // AFont interface
public:
    bool OpenFont() override;
    void CloseFont() override;
    void *Data() override;

private:
    TTF_Font* m_data{nullptr};
};

#endif // SDLFONT_H
