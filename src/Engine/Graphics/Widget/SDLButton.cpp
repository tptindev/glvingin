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
    std::cout << __FUNCTION__ << std::endl;
}

SDLButton::~SDLButton()
{
    std::cout << __FUNCTION__ << std::endl;
}

void SDLButton::Initialize()
{

}

void SDLButton::HandleEvent()
{

}

void SDLButton::Render()
{
    SDL_SetRenderDrawColor(Renderer2D::Instance()->renderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(Renderer2D::Instance()->renderer(), &this->m_rect);
}
