#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "IRenderer.h"

struct SDL_Renderer;
class ITexture;
class SDLWindowWrapper;
class Renderer2D : public IRenderer
{
public:
    Renderer2D(const Renderer2D &) = delete;
    Renderer2D(Renderer2D &&) = delete;
    Renderer2D &operator=(const Renderer2D &) = delete;
    Renderer2D &operator=(Renderer2D &&) = delete;
    static Renderer2D* Instance();
    static void ResetInstance();
    ~Renderer2D();

    SDL_Renderer *renderer() const;

    // ARenderer interface
public:
    bool Initialize(IWindowWrapper* window) override;
    void SetDrawColor() override;
    void Clear() override;
    void Present() override;
    void Destroy() override;
    void Render(ITexture* texture, glm::ivec2 position, int width, int height, bool fip) override;
    void RenderFrame(ITexture* texture, glm::ivec2 position, int frameWidth, int frameHeight, glm::ivec2 coord, bool flip = false, float rotation = 0.0f) override;


private:
    static Renderer2D* s_instance;
    Renderer2D();
    SDLWindowWrapper* m_winWrapper{nullptr};
    SDL_Renderer* m_renderer{nullptr};
};

#endif // RENDERER2D_H
