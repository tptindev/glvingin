#include "SDLTexture.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Renderer/Renderer2D.h"
SDLTexture::SDLTexture()
{
    std::cout << __FUNCTION__ << std::endl;
}

SDLTexture::~SDLTexture()
{
    std::cout << __FUNCTION__ << std::endl;
}

bool SDLTexture::Create(const char *path)
{
    SDL_Surface *surface = IMG_Load(path);
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
