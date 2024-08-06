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
    void setNormal(SDL_Color color);
    void setPressed(SDL_Color color);
    void setReleased(SDL_Color color);
    void setNormal(SDL_Color bgColor, SDL_Color textColor);
    void setPressed(SDL_Color bgColor, SDL_Color textColor);
    void setReleased(SDL_Color bgColor, SDL_Color textColor);
    void setNormal(SDL_Color bgColor, SDL_Color borderColor, SDL_Color textColor);
    void setPressed(SDL_Color bgColor, SDL_Color borderColor, SDL_Color textColor);
    void setReleased(SDL_Color bgColor, SDL_Color borderColor, SDL_Color textColor);
    void attachText(int textureID, int fontID, const char* text);
    SDLText* text() const;
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
    std::unordered_map<int, SDL_Color> m_textColorState;
    std::shared_ptr<SDLText> m_text;
    int m_borderWidth{0};
    int m_radius{0};
};

#endif // SDLBUTTON_H
