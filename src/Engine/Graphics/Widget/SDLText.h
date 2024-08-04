#ifndef SDLTEXT_H
#define SDLTEXT_H

#include "AWidget.h"
#include <SDLFont.h>
#include <SDL2/SDL_pixels.h>

class SDLText : public AWidget
{
public:
    explicit SDLText(const char *text, int x, int y, int w, int h);
    ~SDLText();

    void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void setFont(const char* fontName = nullptr, int fontSize = 0);
    void setTextureID(int newTextureID);

    // AWidget interface
public:
    void Initialize() override;
    void Completed() override;
    void HandleEvent() override;
    void Render() override;


private:
    int m_textureID;
    const char* m_text;
    SDLFont* m_font{nullptr};
    SDL_Color m_color{0x0, 0x0, 0x0, 0xFF};
};

#endif // SDLTEXT_H
