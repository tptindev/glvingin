#ifndef ITEXTURE_H
#define ITEXTURE_H

#include <stdint.h>
class AFont;
class ITexture
{
public:
    ~ITexture() = default;
    
    virtual bool CreateFromIMG(const char* path) = 0;
    virtual bool CreateFromText(const char* text, AFont* font, uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 1) = 0;
    virtual void GetInfo(uint32_t *format, int* access, int *width, int *height) = 0;
    virtual void Destroy() = 0;
};

#endif // ITEXTURE_H
