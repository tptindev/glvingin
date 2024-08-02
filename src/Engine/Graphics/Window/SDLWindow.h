#ifndef SDLWINDOW_H
#define SDLWINDOW_H

#include "IWindow.h"

struct SDL_Window;
class SDLWindow : public IWindow
{
public:
    SDLWindow();
    SDL_Window* window() const;

    // IWindow interface
public:
    bool CreateWindow(int width, int height, const char *title) override;
    void DestroyWindow() override;

private:
    SDL_Window* m_window;
};

#endif // SDLWINDOW_H
