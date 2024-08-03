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
    bool Create(const char *path) override;
    void Destroy() override;

private:
    SDL_Texture *m_data;

};

#endif // SDLTEXTURE_H
