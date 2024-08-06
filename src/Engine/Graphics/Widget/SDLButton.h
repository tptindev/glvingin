#ifndef SDLBUTTON_H
#define SDLBUTTON_H

#include <memory>
#include <unordered_map>
#include <SDL2/SDL.h>
#include "AWidget.h"
#include "AEventListener.h"

class SDLText;

class SDLButton : public AWidget, AEventListener
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

    void SetBorderWidth(int width);
    void SetNormal(SDL_Color color);
    void SetPressed(SDL_Color color);
    void SetReleased(SDL_Color color);
    void SetNormal(SDL_Color bgColor, SDL_Color textColor);
    void SetPressed(SDL_Color bgColor, SDL_Color textColor);
    void SetReleased(SDL_Color bgColor, SDL_Color textColor);
    void SetNormal(SDL_Color bgColor, SDL_Color borderColor, SDL_Color textColor);
    void SetPressed(SDL_Color bgColor, SDL_Color borderColor, SDL_Color textColor);
    void SetReleased(SDL_Color bgColor, SDL_Color borderColor, SDL_Color textColor);
    void AttachText(int textureID, int fontID, const char* text);
    void AttachSound(int soundID);
    SDLText* Text() const;
    void SetCurrentState(int newCurrentState);

    // AWidget interface
public:
    void Initialize() override;
    void Completed() override;
    void HandleEvent() override;
    void Render() override;

    // AEventListener interface
public:
    void OnClicked() override;
    void OnPressed() override;
    void OnLongPressed() override;
    void OnReleased() override;

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
