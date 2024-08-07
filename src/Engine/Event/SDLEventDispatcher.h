#ifndef SDLEVENTDISPATCHER_H
#define SDLEVENTDISPATCHER_H

#include <SDL2/SDL_events.h>
#include "AEventDispatcher.h"

class SDLEventDispatcher : public AEventDispatcher
{
public:
    SDLEventDispatcher(const SDLEventDispatcher &) = delete;
    SDLEventDispatcher(SDLEventDispatcher &&) = delete;
    SDLEventDispatcher &operator=(const SDLEventDispatcher &) = delete;
    SDLEventDispatcher &operator=(SDLEventDispatcher &&) = delete;
    ~SDLEventDispatcher();
    static SDLEventDispatcher *Instance();
    static void ResetInstance();

    // AEventDispatcher interface
public:
    static SDLEventDispatcher* s_instance;
    SDLEventDispatcher();
    void Listen() override;

private:
    SDL_Event m_event;
};

#endif // SDLEVENTDISPATCHER_H
