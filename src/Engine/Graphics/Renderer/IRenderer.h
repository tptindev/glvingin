#ifndef IRENDERER_H
#define IRENDERER_H

#include <glm/glm.hpp>
class IWindowWrapper;
class ITexture;
class IRenderer
{
public:
    ~IRenderer() = default;
    virtual bool Initialize(IWindowWrapper* window) = 0;
    virtual void SetDrawColor() = 0;
    virtual void Clear() = 0;
    virtual void Present() = 0;
    virtual void Destroy() = 0;
    virtual void Render(ITexture* texture, glm::ivec2 position, int width, int height, bool fip) {}
    virtual void RenderFrame(ITexture* texture, glm::ivec2 position, int frameWidth, int frameHeight, glm::ivec2 coord, bool flip = false, float rotation = 0.0f) {}

};

#endif // IRENDERER_H
