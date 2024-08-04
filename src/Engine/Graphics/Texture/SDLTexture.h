#ifndef SDLTEXTURE_H
#define SDLTEXTURE_H

#include "ITexture.h"
struct SDL_Texture;
class SDLTexture : public ITexture
{
public:
    SDLTexture();
    ~SDLTexture();
    SDL_Texture *data() const;

    // ATexture interface
public:
    bool CreateFromIMG(const char *path) override;
    bool CreateFromText(const char* text, AFont* font, uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 1) override;
    void Destroy() override;

private:
    SDL_Texture *m_data{nullptr};

};

#endif // SDLTEXTURE_H
