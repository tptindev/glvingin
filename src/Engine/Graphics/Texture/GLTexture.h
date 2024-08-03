#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "ITexture.h"

class GLTexture : public ITexture
{
public:
    GLTexture();

    // ATexture interface
public:
    bool Create(const char *path) override;
    void Destroy() override;

};

#endif // GLTEXTURE_H
