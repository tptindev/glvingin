#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "IRenderer.h"

struct SDL_Renderer;
class SDLWindowWrapper;
class Renderer2D : public IRenderer
{
public:
    Renderer2D();

    // ARenderer interface
public:
    bool Initialize(IWindowWrapper* window) override;
    void SetDrawColor() override;
    void Clear() override;
    void Present() override;
    void Destroy() override;

private:
    SDLWindowWrapper* m_winWrapper{nullptr};
    SDL_Renderer* m_renderer{nullptr};
};

#endif // RENDERER2D_H
