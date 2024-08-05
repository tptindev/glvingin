#include "Renderer2D.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDLWindowWrapper.h>
#include <SDLTexture.h>

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
    this->m_winWrapper = dynamic_cast<SDLWindowWrapper*>(window);
    this->m_renderer = SDL_CreateRenderer(this->m_winWrapper->window(), -1, SDL_RENDERER_ACCELERATED);
    return (window != nullptr) && (this->m_renderer != nullptr);
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

void Renderer2D::Render(ITexture *itexture, int x, int y, float scale)
{
    if (itexture == nullptr) return;
    SDLTexture* texture = dynamic_cast<SDLTexture*>(itexture);
    // Get the original texture size
    int width, height;
    SDL_QueryTexture(texture->data(), NULL, NULL, &width, &height);
    SDL_FRect destRect = {(float)x, (float)y, (float)width * scale, (float)height * scale};
    SDL_RenderCopyF(this->m_renderer, texture->data(), NULL, &destRect);
}

SDL_Renderer *Renderer2D::renderer() const
{
    return m_renderer;
}

void Renderer2D::Render(ITexture* itexture, int x, int y, int width, int height)
{
    if (itexture == nullptr) return;
    SDLTexture* texture = dynamic_cast<SDLTexture*>(itexture);
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect destRect = {x, y, width, height};
    SDL_RenderCopy(this->m_renderer, texture->data(), &srcRect, &destRect);
}

void Renderer2D::RenderFrame(ITexture* itexture, int x, int y, int frameWidth, int frameHeight, int col, int row, std::bitset<2> flip, float rotation)
{
    if (itexture == nullptr) return;

    SDL_RendererFlip sdlFlip = SDL_FLIP_NONE;
    if (flip[0] == 1)
    {
        sdlFlip = SDL_FLIP_HORIZONTAL;
    }
    else if (flip[1] == 1)
    {
        sdlFlip = SDL_FLIP_VERTICAL;
    }

    SDLTexture* texture = dynamic_cast<SDLTexture*>(itexture);
    int frameX = frameWidth * col;
    int frameY = frameHeight * row;

    SDL_Rect srcRect = {frameX, frameY, frameWidth, frameHeight};
    SDL_Rect destRect = {
        x,
        y,
        frameWidth,
        frameHeight
    };
    SDL_RenderCopyEx(this->m_renderer, texture->data(), &srcRect, &destRect, 0, NULL, sdlFlip);
}
