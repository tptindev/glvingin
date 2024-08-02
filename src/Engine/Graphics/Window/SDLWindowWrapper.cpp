#include "SDLWindowWrapper.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL.h>
SDLWindowWrapper::SDLWindowWrapper()
{
    std::cout << __FUNCTION__ << std::endl;
}

SDLWindowWrapper::~SDLWindowWrapper()
{
    std::cout << __FUNCTION__ << std::endl;
}

SDL_Window *SDLWindowWrapper::window() const
{
    return this->m_window;
}

bool SDLWindowWrapper::CreateWindow(int width, int height, const char *title)
{
    this->m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if (this->m_window == nullptr)
    {
        return false;
    }
    return true;
}

void SDLWindowWrapper::DestroyWindow()
{
    SDL_DestroyWindow(this->m_window);
}
