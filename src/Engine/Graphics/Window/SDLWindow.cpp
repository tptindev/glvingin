#include "SDLWindow.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL.h>
SDLWindow::SDLWindow()
{

}

SDL_Window *SDLWindow::window() const
{
    return this->m_window;
}

void SDLWindow::CreateWindow(int width, int height, const char *title)
{
    this->m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if (this->m_window == nullptr)
    {
        return;
    }
}

void SDLWindow::DestroyWindow()
{
    SDL_DestroyWindow(this->m_window);
}
