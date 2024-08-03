#ifndef ITEXTURE_H
#define ITEXTURE_H

class ITexture
{
public:
    ~ITexture() = default;
    
    virtual bool Create(const char* path) = 0;
    virtual void Destroy() = 0;
};

#endif // ITEXTURE_H
