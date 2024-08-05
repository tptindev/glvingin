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
    this->m_text = text;
}

void SDLButton::Initialize()
{
}

void SDLButton::Completed()
{
}

void SDLButton::HandleEvent()
{

}

void SDLButton::Render()
{
    if (this->m_text != nullptr)
    {
        this->m_text->Render();
    }

    SDL_SetRenderDrawColor(Renderer2D::Instance()->renderer(), 0, 0, 0, 0);
    SDL_RenderFillRect(Renderer2D::Instance()->renderer(), &this->m_rect);
}

void SDLButton::setCurrentState(int newCurrentState)
{
    m_currentState = newCurrentState;
}
