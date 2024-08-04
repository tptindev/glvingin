#ifndef SDLFONT_H
#define SDLFONT_H

#include "AFont.h"
#include <SDL2/SDL_ttf.h>

class SDLFont : public AFont
{
public:
    SDLFont(const char* fontName, int fontSize);

    // AFont interface
public:
    bool OpenFont() override;
    void CloseFont() override;

    TTF_Font *data() const;

private:
    TTF_Font* m_data;
};

#endif // SDLFONT_H
