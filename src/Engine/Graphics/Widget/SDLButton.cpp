#include "SDLButton.h"
#include <iostream>
#include <Renderer2D.h>
#include <SDLEventDispatcher.h>
#include "SDLText.h"
SDLButton::SDLButton()
{
    SDLEventDispatcher::Instance()->AddListener(this);
    std::cout << __FUNCTION__ << std::endl;
}

SDLButton::SDLButton(int x, int y, int w, int h)
{
    this->setX(x);
    this->setY(y);
    this->setWidth(w);
    this->setHeight(h);

    this->m_rect = {x, y, w, h};
    SDLEventDispatcher::Instance()->AddListener(this);
    std::cout << __FUNCTION__ << std::endl;
}

SDLButton::~SDLButton()
{
    std::cout << __FUNCTION__ << std::endl;
}

void SDLButton::SetBorderWidth(int width)
{
    this->m_borderWidth = width;
}

void SDLButton::SetNormal(SDL_Color color)
{
    this->m_bgColorState[NORMAL] = color;
    this->m_borderColorState[NORMAL] = color;
    this->m_textColorState[NORMAL] = color;
}

void SDLButton::SetActive(SDL_Color color)
{
    this->m_bgColorState[ACTIVE] = color;
    this->m_borderColorState[ACTIVE] = color;
    this->m_textColorState[ACTIVE] = color;
}

void SDLButton::SetPressed(SDL_Color color)
{
    this->m_bgColorState[PRESSED] = color;
    this->m_borderColorState[PRESSED] = color;
    this->m_textColorState[PRESSED] = color;
}

void SDLButton::SetReleased(SDL_Color color)
{
    this->m_bgColorState[RELEASED] = color;
    this->m_borderColorState[RELEASED] = color;
    this->m_textColorState[RELEASED] = color;
}

void SDLButton::SetNormal(SDL_Color bgColor, SDL_Color textColor)
{
    this->m_bgColorState[NORMAL] = bgColor;
    this->m_textColorState[NORMAL] = textColor;
}

void SDLButton::SetActive(SDL_Color bgColor, SDL_Color textColor)
{
    this->m_bgColorState[ACTIVE] = bgColor;
    this->m_textColorState[ACTIVE] = textColor;
}

void SDLButton::SetPressed(SDL_Color bgColor, SDL_Color textColor)
{
    this->m_bgColorState[PRESSED] = bgColor;
    this->m_textColorState[PRESSED] = textColor;
}

void SDLButton::SetReleased(SDL_Color bgColor, SDL_Color textColor)
{
    this->m_bgColorState[RELEASED] = bgColor;
    this->m_textColorState[RELEASED] = textColor;
}

void SDLButton::SetNormal(SDL_Color bgColor, SDL_Color borderColor, SDL_Color textColor)
{
    this->m_bgColorState[NORMAL] = bgColor;
    this->m_borderColorState[NORMAL] = borderColor;
    this->m_textColorState[NORMAL] = textColor;
}

void SDLButton::SetActive(SDL_Color bgColor, SDL_Color borderColor, SDL_Color textColor)
{
    this->m_bgColorState[ACTIVE] = bgColor;
    this->m_borderColorState[ACTIVE] = borderColor;
    this->m_textColorState[ACTIVE] = textColor;
}

void SDLButton::SetPressed(SDL_Color bgColor, SDL_Color borderColor, SDL_Color textColor)
{
    this->m_bgColorState[PRESSED] = bgColor;
    this->m_borderColorState[PRESSED] = borderColor;
    this->m_textColorState[PRESSED] = textColor;
}

void SDLButton::SetReleased(SDL_Color bgColor, SDL_Color borderColor, SDL_Color textColor)
{
    this->m_bgColorState[RELEASED] = bgColor;
    this->m_borderColorState[RELEASED] = borderColor;
    this->m_textColorState[RELEASED] = textColor;
}

void SDLButton::AttachText(int textureID, int fontID, const char* text)
{
    this->m_text = std::make_shared<SDLText>(textureID, text, 0, 0);
    this->m_text->Initialize();
    this->m_text->setFont(fontID);
    this->m_text->setColor(
        this->m_textColorState[this->m_currentState].r,
        this->m_textColorState[this->m_currentState].g,
        this->m_textColorState[this->m_currentState].b,
        this->m_textColorState[this->m_currentState].a
        );
    this->m_text->Completed();
    this->m_text->setX(this->x() + this->width() / 2  - this->m_text->width() / 2);
    this->m_text->setY(this->y() + this->height() / 2 - this->m_text->height() / 2);
}

void SDLButton::AttachSound(int soundID)
{

}

void SDLButton::Initialize()
{
    this->m_currentState = NORMAL;
}

void SDLButton::Completed()
{
}

void SDLButton::HandleEvent()
{

}

void SDLButton::Render()
{
    decltype(this->m_bgColorState)::iterator it = this->m_bgColorState.find(this->m_currentState);
    if (it != this->m_bgColorState.end())
    {
        SDL_Renderer* renderer = Renderer2D::Instance()->renderer();
        SDL_Color &bgColor = this->m_bgColorState[this->m_currentState];
        // Set the background color and fill the button's rectangle
        SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
        SDL_RenderFillRect(renderer, &this->m_rect);

        if (this->m_borderWidth > 0)
        {
            decltype(this->m_borderColorState)::iterator it = this->m_borderColorState.find(this->m_currentState);
            if (it !=this->m_borderColorState.end())
            {
                SDL_Color &borderColor = this->m_borderColorState[this->m_currentState];
                // Set the border color and draw the button's border
                SDL_SetRenderDrawColor(renderer, borderColor.r, borderColor.g, borderColor.b, borderColor.a);
                SDL_RenderDrawRect(renderer, &this->m_rect);
            }
        }

    }
    if (this->m_text != nullptr)
    {
        this->m_text->Render();
    }
}

void SDLButton::OnMouseStateChanged(const int &x, const int &y, int type, int button, int state, int clicks)
{
    if ((this->x() <= x && this->y() <= y) && (x <= this->x() + this->width() && y <= this->y() + this->height()))
    {
        this->m_currentState = ACTIVE;
        if (type == SDL_MOUSEBUTTONDOWN)
        {
            this->m_currentState = PRESSED;
        }
        else if (type == SDL_MOUSEBUTTONUP)
        {
            this->m_currentState = RELEASED;
        }
    }
    else
    {
        this->m_currentState = NORMAL;
    }
}

SDLText* SDLButton::Text() const
{
    return m_text.get();
}

void SDLButton::SetCurrentState(int newCurrentState)
{
    m_currentState = newCurrentState;
}
