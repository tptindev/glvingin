#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "ATexture.h"

class GLTexture : public ATexture
{
public:
    GLTexture();

    // ATexture interface
public:
    bool Create(const char *path) override;
    void Destroy() override;

};

#endif // GLTEXTURE_H
