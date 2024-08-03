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
    this->m_winWrapper = static_cast<SDLWindowWrapper*>(window);
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

SDL_Renderer *Renderer2D::renderer() const
{
    return m_renderer;
}

/**
 * @brief Renderer2D::Render
 * @param texture
 * @param position
 * @param width
 * @param height
 * @param fip
 * Render a texture to the screen
 */
void Renderer2D::Render(ITexture *texture, glm::ivec2 position, int width, int height, bool fip)
{
    SDLTexture* sdlTexture = static_cast<SDLTexture*>(texture);
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect destRect = {position.x, position.y, width, height};
    SDL_RenderCopy(this->m_renderer, sdlTexture->data(), &srcRect, &destRect);
}

/**
 * @brief Renderer2D::RenderFrame
 * @param texture
 * @param position
 * @param frameWidth
 * @param frameHeight
 * @param coord
 * @param flip
 * @param rotation
 * Render a portion of a texture (useful for sprite sheets)
 */
void Renderer2D::RenderFrame(ITexture* texture, glm::ivec2 position, int frameWidth, int frameHeight, glm::ivec2 coord, bool flip, float rotation)
{
    SDLTexture* sdlTexture = static_cast<SDLTexture*>(texture);
    int frameX = frameWidth * coord.x;
    int frameY = frameHeight * coord.y;

    SDL_Rect srcRect = {frameX, frameY, frameWidth, frameHeight};
    SDL_Rect destRect = {
        position.x,
        position.y,
        frameWidth,
        frameHeight
    };
    SDL_RenderCopyEx(this->m_renderer, sdlTexture->data(), &srcRect, &destRect, 0, NULL, SDL_FLIP_NONE);
}
