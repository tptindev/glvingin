#ifndef IRENDERER_H
#define IRENDERER_H

#include <bitset>
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
    /**
     * @brief Render
     * @param itexture
     * @param x
     * @param y
     * @param scale
     */
    virtual void Render(ITexture* itexture, int x, int y, float scale = 1.0f) {}
    /**
     * @brief Render
     * @param itexture
     * @param x
     * @param y
     * @param width
     * @param height
     */
    virtual void Render(ITexture* itexture, int x, int y, int width, int height) {}
    /**
     * @brief RenderFrame
     * @param itexture
     * @param position
     * @param frameWidth
     * @param frameHeight
     * @param coord
     * @param flip (vertical,horizontal) <=> bitset<2>(00)
     * @param rotation
     */
    virtual void RenderFrame(ITexture* itexture, int x, int y, int frameWidth, int frameHeight, int col, int row, std::bitset<2> flip, float rotation = 0.0f) {}

};

#endif // IRENDERER_H
