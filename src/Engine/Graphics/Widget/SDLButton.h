#ifndef SDLBUTTON_H
#define SDLBUTTON_H

#include <SDL2/SDL.h>
#include "AWidget.h"

struct SDLButtonState
{
    int normal;
    int pressed;
    int released;
};

class SDLButton : public AWidget
{
public:
    SDLButton();
    SDLButton(int x, int y, int w, int h);
    virtual ~SDLButton();

    void setNormal(SDL_Color bgColor, SDL_Color txtColor);
    void setPressed(SDL_Color bgColor, SDL_Color txtColor);
    void setReleased(SDL_Color bgColor, SDL_Color txtColor);

    void setCurrentState(int newCurrentState);

    // AWidget interface
public:
    void Initialize() override;
    void Completed() override;
    void HandleEvent() override;
    void Render() override;


protected:
    SDLButtonState m_state;
    int m_currentState;

private:
    SDL_Rect m_rect;
    SDL_Color m_bgColor[3];
    SDL_Color m_txtColor[3];
};

#endif // SDLBUTTON_H
