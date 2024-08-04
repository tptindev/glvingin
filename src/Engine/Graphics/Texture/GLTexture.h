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
    bool CreateFromText(const char *text) override;
    void Destroy() override;
};

#endif // GLTEXTURE_H
