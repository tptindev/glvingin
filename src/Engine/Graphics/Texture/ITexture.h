#ifndef ITEXTURE_H
#define ITEXTURE_H

class ITexture
{
public:
    ~ITexture() = default;
    
    virtual bool CreateFromIMG(const char* path) = 0;
    virtual bool CreateFromText(const char* text) = 0;
    virtual void Destroy() = 0;
};

#endif // ITEXTURE_H
