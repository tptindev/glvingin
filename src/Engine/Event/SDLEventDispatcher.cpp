#include "SDLEventDispatcher.h"
#include <algorithm>
#include <iostream>
#include <Engine2D.h>

SDLEventDispatcher *SDLEventDispatcher::s_instance = nullptr;
SDLEventDispatcher::SDLEventDispatcher()
{
    std::cout << __FUNCTION__ << std::endl;
}

void SDLEventDispatcher::Listen()
{
    int x = 0;
    int y = 0;
    SDL_GetMouseState(&x, &y);
    std::cout << x << ":" << y << std::endl;
    while(SDL_PollEvent(&this->m_event)){
        switch(this->m_event.type){
        case SDL_QUIT:
            Engine2D::Running() = false;
            break;
        default:
            this->Dispatch();
            break;
        }
    }
}

SDLEventDispatcher::~SDLEventDispatcher()
{
    std::cout << __FUNCTION__ << std::endl;
}

SDLEventDispatcher *SDLEventDispatcher::Instance()
{
    if (SDLEventDispatcher::s_instance == nullptr)
    {
        SDLEventDispatcher::s_instance = new SDLEventDispatcher();
    }
    return SDLEventDispatcher::s_instance;
}

void SDLEventDispatcher::ResetInstance()
{
    if (SDLEventDispatcher::s_instance != nullptr)
    {
        delete SDLEventDispatcher::s_instance;
        SDLEventDispatcher::s_instance = nullptr;
    }
    return;
}
