#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "IRenderer.h"

struct SDL_Renderer;
class SDLWindow;
class Renderer2D : public IRenderer
{
public:
    Renderer2D();

    // ARenderer interface
public:
    void Initialize(IWindow* window) override;
    void SetDrawColor() override;
    void Clear() override;
    void Present() override;
    void Destroy() override;

private:
    SDLWindow* m_window;
    SDL_Renderer* m_renderer;
};

#endif // RENDERER2D_H
