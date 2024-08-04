#include "SDLButton.h"
#include <iostream>
#include <Renderer2D.h>

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
    this->m_bgColor[0] = {0xFF,0xFF,0xFF,0xFF};
    this->m_txtColor[0] = {0x0,0x0,0x0,0xFF};
    this->m_bgColor[1] = {0x0,0x0,0x0,0xFF};
    this->m_txtColor[1] = {0xFF,0xFF,0xFF,0xFF};
    this->m_bgColor[2] = {0xFF,0xFF,0xFF,0xFF};
    this->m_txtColor[2] = {0x0,0x0,0x0,0xFF};

    std::cout << __FUNCTION__ << std::endl;
}

SDLButton::~SDLButton()
{
    std::cout << __FUNCTION__ << std::endl;
}

void SDLButton::setNormal(SDL_Color bgColor, SDL_Color txtColor)
{
    this->m_bgColor[this->m_state.normal] = bgColor;
    this->m_txtColor[this->m_state.normal] = txtColor;
}

void SDLButton::setPressed(SDL_Color bgColor, SDL_Color txtColor)
{
    this->m_bgColor[this->m_state.pressed] = bgColor;
    this->m_txtColor[this->m_state.pressed] = txtColor;
}

void SDLButton::setReleased(SDL_Color bgColor, SDL_Color txtColor)
{
    this->m_bgColor[this->m_state.released] = bgColor;
    this->m_txtColor[this->m_state.released] = txtColor;
}

void SDLButton::Initialize()
{
    this->m_state.normal = 0;
    this->m_state.pressed = 1;
    this->m_state.released = 2;
}

void SDLButton::Completed()
{
    this->m_currentState = this->m_state.normal;
}

void SDLButton::HandleEvent()
{

}

void SDLButton::Render()
{
//    SDL_SetRenderDrawColor(
//        Renderer2D::Instance()->renderer(),
//        this->m_bgColor[this->m_currentState].r,
//        this->m_bgColor[this->m_currentState].g,
//        this->m_bgColor[this->m_currentState].b,
//        this->m_bgColor[this->m_currentState].a
//        );
//    SDL_RenderFillRect(Renderer2D::Instance()->renderer(), &this->m_rect);
}

void SDLButton::setCurrentState(int newCurrentState)
{
    m_currentState = newCurrentState;
}
