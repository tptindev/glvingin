#include "Renderer2D.h"
#include <SDL2/SDL.h>
#include <SDLWindow.h>
Renderer2D::Renderer2D()
{
    
}

void Renderer2D::Initialize(IWindow* window)
{
    this->m_window = static_cast<SDLWindow*>(window);
    SDL_CreateRenderer(this->m_window->window(), -1, SDL_RENDERER_ACCELERATED);
}

void Renderer2D::SetDrawColor()
{
    SDL_SetRenderDrawColor(this->m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void Renderer2D::Clear()
{
    SDL_RenderClear(this->m_renderer);
}

void Renderer2D::Present()
{
    SDL_RenderPresent(this->m_renderer);
}

void Renderer2D::Destroy()
{
    SDL_DestroyRenderer(this->m_renderer);
}
