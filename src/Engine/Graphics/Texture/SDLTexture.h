#ifndef SDLTEXTURE_H
#define SDLTEXTURE_H

#include "ATexture.h"
struct SDL_Texture;
class SDLTexture : public ATexture
{
public:
    SDLTexture();
    ~SDLTexture();
    SDL_Texture *texture() const;

    // ATexture interface
public:
    bool Create(const char *path) override;
    void Destroy() override;

private:
    SDL_Texture *m_texture;

};

#endif // SDLTEXTURE_H
