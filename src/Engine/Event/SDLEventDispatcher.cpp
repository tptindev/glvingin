#include "SDLEventDispatcher.h"
#include <algorithm>
#include <iostream>
SDLEventDispatcher *SDLEventDispatcher::s_instance = nullptr;
SDLEventDispatcher::SDLEventDispatcher()
{
    std::cout << __FUNCTION__ << std::endl;
}

void SDLEventDispatcher::AddListener(AEventListener *listener)
{
    decltype(this->m_listener)::iterator it = std::find(this->m_listener.begin(), this->m_listener.end(), listener);
    if (it != this->m_listener.end())
    {
        this->m_listener.push_back(listener);
    }
    return;
}

void SDLEventDispatcher::RemoveListener(AEventListener* listener)
{

}

void SDLEventDispatcher::Dispatch()
{

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
