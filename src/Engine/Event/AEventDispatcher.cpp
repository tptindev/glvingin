#include "AEventDispatcher.h"
#include "AEventListener.h"
#include <iostream>
#include <algorithm>
void AEventDispatcher::AddListener(IEventListener *listener)
{
    decltype(this->m_listener)::iterator it = std::find(this->m_listener.begin(), this->m_listener.end(), listener);
    if (it == this->m_listener.end())
    {
        this->m_listener.push_back(listener);
    }
    return;
}

void AEventDispatcher::RemoveListener(IEventListener *listener)
{
    decltype(this->m_listener)::iterator it = std::find(this->m_listener.begin(), this->m_listener.end(), listener);
    if (it != this->m_listener.end())
    {
        this->m_listener.erase(it);
    }
    return;
}

void AEventDispatcher::Dispatch()
{
    decltype(this->m_listener)::iterator it = this->m_listener.begin();
    while (it != this->m_listener.end())
    {
        it++;
    }
    return;
}
