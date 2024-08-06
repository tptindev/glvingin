#ifndef SDLTEXT_H
#define SDLTEXT_H

#include "AWidget.h"
#include <SDLFont.h>
#include <SDL2/SDL_pixels.h>

class SDLText : public AWidget
{
public:
    explicit SDLText(int textureID, const char *text, int x, int y);
    explicit SDLText(int textureID, const char *text, int x, int y, int w, int h);
    ~SDLText();

    void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void setFont(int fontID);

    // AWidget interface
public:
    void Initialize() override;
    void Completed() override;
    void HandleEvent() override;
    void Render() override;


    float scale() const;
    void setScale(float newScale);

    int textureID() const;
    void setTextureID(int newTextureID);

private:
    int m_textureID;
    const char* m_text;
    float m_scale{1};
    SDLFont* m_font{nullptr};
    SDL_Color m_color{0x0, 0x0, 0x0, 0xFF};
};

#endif // SDLTEXT_H
