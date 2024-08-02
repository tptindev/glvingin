#ifndef SDLWINDOWWRAPPER_H
#define SDLWINDOWWRAPPER_H

#include "IWindowWrapper.h"

struct SDL_Window;
class SDLWindowWrapper : public IWindowWrapper
{
public:
    SDLWindowWrapper();
    ~SDLWindowWrapper();
    SDL_Window* window() const;

    // IWindow interface
public:
    bool CreateWindow(int width, int height, const char *title) override;
    void DestroyWindow() override;

private:
    SDL_Window* m_window;
};

#endif // SDLWINDOWWRAPPER_H
