#ifndef SDLBUTTON_H
#define SDLBUTTON_H

#include <memory>
#include <unordered_map>
#include <SDL2/SDL.h>
#include "AWidget.h"

class SDLText;
class SDLButton : public AWidget
{
public:
    enum SDLButtonState
    {
        NORMAL,
        PRESSED,
        RELEASED
    };

    SDLButton();
    SDLButton(int x, int y, int w, int h);
    virtual ~SDLButton();

    void setBorderWidth(int width);
    void setNormal(SDL_Color bgColor);
    void setPressed(SDL_Color bgColor);
    void setReleased(SDL_Color bgColor);
    void setNormal(SDL_Color bgColor, SDL_Color borderColor);
    void setPressed(SDL_Color bgColor, SDL_Color borderColor);
    void setReleased(SDL_Color bgColor, SDL_Color borderColor);
    void attachText(std::shared_ptr<SDLText> text);
    void setCurrentState(int newCurrentState);

    // AWidget interface
public:
    void Initialize() override;
    void Completed() override;
    void HandleEvent() override;
    void Render() override;


protected:
    int m_currentState;

private:
    SDL_Rect m_rect;
    std::unordered_map<int, SDL_Color> m_bgColorState;
    std::unordered_map<int, SDL_Color> m_borderColorState;
    int m_borderWidth;
    std::shared_ptr<SDLText> m_text;
};

#endif // SDLBUTTON_H
