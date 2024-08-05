#include "SDLButton.h"
#include <iostream>
#include <Renderer2D.h>
#include "SDLText.h"
SDLButton::SDLButton()
{
    std::cout << __FUNCTION__ << std::endl;
}

SDLButton::SDLButton(int x, int y, int w, int h)
{
    this->setX(x);
    this->setY(y);
    this->setWidth(w);
    this->setHeight(h);

    this->m_rect = {x, y, w, h};

    std::cout << __FUNCTION__ << std::endl;
}

SDLButton::~SDLButton()
{
    std::cout << __FUNCTION__ << std::endl;
}

void SDLButton::setBorderWidth(int width)
{
    this->m_borderWidth = width;
}

void SDLButton::setNormal(SDL_Color bgColor)
{
    this->m_bgColorState[NORMAL] = bgColor;
}

void SDLButton::setPressed(SDL_Color bgColor)
{
    this->m_bgColorState[PRESSED] = bgColor;
}

void SDLButton::setReleased(SDL_Color bgColor)
{
    this->m_bgColorState[RELEASED] = bgColor;
}

void SDLButton::setNormal(SDL_Color bgColor, SDL_Color borderColor)
{
    this->m_bgColorState[NORMAL] = bgColor;
    this->m_borderColorState[NORMAL] = borderColor;
}

void SDLButton::setPressed(SDL_Color bgColor, SDL_Color borderColor)
{
    this->m_bgColorState[PRESSED] = bgColor;
    this->m_borderColorState[PRESSED] = borderColor;
}

void SDLButton::setReleased(SDL_Color bgColor, SDL_Color borderColor)
{
    this->m_bgColorState[RELEASED] = bgColor;
    this->m_borderColorState[RELEASED] = borderColor;
}

void SDLButton::attachText(std::shared_ptr<SDLText> text)
{
    text->setX(this->x() + text->x());
    text->setY(this->y() + text->y());
    this->m_text = text;
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
    SDL_Renderer* renderer = Renderer2D::Instance()->renderer();
    SDL_Color &bgColor = this->m_bgColorState[this->m_currentState];
    // Set the background color and fill the button's rectangle
    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
    SDL_RenderFillRect(renderer, &this->m_rect);

    SDL_Color &borderColor = this->m_borderColorState[this->m_currentState];
    // Set the border color and draw the button's border
    SDL_SetRenderDrawColor(renderer, borderColor.r, borderColor.g, borderColor.b, borderColor.a);
    SDL_RenderDrawRect(renderer, &this->m_rect);

    if (this->m_text != nullptr)
    {
        this->m_text->Render();
    }
}

void SDLButton::setCurrentState(int newCurrentState)
{
    m_currentState = newCurrentState;
}
