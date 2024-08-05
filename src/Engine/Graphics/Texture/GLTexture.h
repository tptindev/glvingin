#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "ITexture.h"

class GLTexture : public ITexture
{
public:
    GLTexture();

    // ATexture interface
public:
    bool CreateFromIMG(const char *path) override;
    bool CreateFromText(const char* text, AFont* font, uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 1) override;
    void GetInfo(uint32_t *format, int* access, int *width, int *height) override;
    void Destroy() override;
};

#endif // GLTEXTURE_H
