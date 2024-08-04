#include "SDLTexture.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <AFont.h>
#include <SDLFont.h>
#include <Renderer2D.h>
SDLTexture::SDLTexture()
{
    std::cout << __FUNCTION__ << std::endl;
}

SDLTexture::~SDLTexture()
{
    std::cout << __FUNCTION__ << std::endl;
}

bool SDLTexture::CreateFromIMG(const char *path)
{
    if (this->m_data != nullptr) return false;
    SDL_Surface *surface = IMG_Load(path);
    if (surface == nullptr)
    {
        return false;
    }
    this->m_data = SDL_CreateTextureFromSurface(Renderer2D::Instance()->renderer(), surface);
    SDL_FreeSurface(surface);
    return true;
}

bool SDLTexture::CreateFromText(const char* text, AFont* font, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    if (this->m_data != nullptr) return false;
    SDL_Color color = { r, g, b, a };
    TTF_Font* sdlFont = reinterpret_cast<TTF_Font*>(dynamic_cast<SDLFont*>(font)->Data());
    SDL_Surface* surface = TTF_RenderText_Solid(
        sdlFont,
        text,
        color);
    if (surface == nullptr)
    {
        return false;
    }
    this->m_data = SDL_CreateTextureFromSurface(Renderer2D::Instance()->renderer(), surface);
    SDL_FreeSurface(surface);
    return true;
}

void SDLTexture::Destroy()
{
    SDL_DestroyTexture(this->m_data);
}

SDL_Texture *SDLTexture::data() const
{
    return m_data;
}
