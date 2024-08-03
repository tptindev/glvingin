#include "Renderer2D.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDLWindowWrapper.h>
Renderer2D *Renderer2D::s_instance = nullptr;
Renderer2D::Renderer2D()
{
    std::cout << __FUNCTION__ << std::endl;
}

Renderer2D *Renderer2D::Instance()
{
    if (Renderer2D::s_instance == nullptr)
    {
        Renderer2D::s_instance = new Renderer2D();
    }
    return Renderer2D::s_instance;
}

void Renderer2D::ResetInstance()
{
    if (Renderer2D::s_instance != nullptr)
    {
        delete Renderer2D::s_instance;
        Renderer2D::s_instance = nullptr;
    }
    return;
}

Renderer2D::~Renderer2D()
{
    std::cout << __FUNCTION__ << std::endl;
}

bool Renderer2D::Initialize(IWindowWrapper* window)
{
    this->m_winWrapper = static_cast<SDLWindowWrapper*>(window);
    this->m_renderer = SDL_CreateRenderer(this->m_winWrapper->window(), -1, SDL_RENDERER_ACCELERATED);
    if (this->m_renderer == nullptr)
    {
        return false;
    }
    return (window != nullptr);
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

void Renderer2D::RenderTexture(ATexture *texture)
{

}

SDL_Renderer *Renderer2D::renderer() const
{
    return m_renderer;
}
