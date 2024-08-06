#ifndef SDLEVENTDISPATCHER_H
#define SDLEVENTDISPATCHER_H

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

    void AddListener(AEventListener *listener) override;
    void RemoveListener(AEventListener* listener) override;
    void Dispatch() override;
};

#endif // SDLEVENTDISPATCHER_H
