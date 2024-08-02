#ifndef IRENDERER_H
#define IRENDERER_H

class IWindow;
class IRenderer
{
public:
    ~IRenderer() = default;
    virtual void Initialize(IWindow* window) = 0;
    virtual void SetDrawColor() = 0;
    virtual void Clear() = 0;
    virtual void Present() = 0;
    virtual void Destroy() = 0;;

};

#endif // IRENDERER_H
