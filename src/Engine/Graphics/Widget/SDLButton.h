#ifndef SDLBUTTON_H
#define SDLBUTTON_H

#include "AWidget.h"
#include <SDL2/SDL.h>

class SDLButton : public AWidget
{
public:
    SDLButton();
    SDLButton(int x, int y, int w, int h);
    virtual ~SDLButton();

    // AWidget interface
public:
    void Initialize() override;
    void HandleEvent() override;
    void Render() override;

private:
    SDL_Rect m_rect;
};

#endif // SDLBUTTON_H
