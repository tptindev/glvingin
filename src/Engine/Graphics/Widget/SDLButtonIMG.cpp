#include "SDLButtonIMG.h"
#include <iostream>
#include <TextureManager.h>
#include <SDLTexture.h>
#include <Renderer2D.h>
SDLButtonIMG::SDLButtonIMG():SDLButton(0, 0, 0, 0)
{
    std::cout << __FUNCTION__ << std::endl;
}

SDLButtonIMG::SDLButtonIMG(int x, int y, int w, int h): SDLButton(x, y, w, h)
{
    std::cout << __FUNCTION__ << std::endl;
}

SDLButtonIMG::~SDLButtonIMG()
{
    std::cout << __FUNCTION__ << std::endl;
}

void SDLButtonIMG::Initialize()
{
}

void SDLButtonIMG::Completed()
{
//    TextureManager::Instance()->Load(std::make_shared<SDLTexture>(), this->m_state.normal, this->m_imgFilePath);
//    TextureManager::Instance()->Load(std::make_shared<SDLTexture>(), this->m_state.pressed, this->m_imgFilePath);
//    TextureManager::Instance()->Load(std::make_shared<SDLTexture>(), this->m_state.released, this->m_imgFilePath);
}

void SDLButtonIMG::HandleEvent()
{

}

void SDLButtonIMG::Render()
{
//    ITexture* texture = TextureManager::Instance()->GetTextureByID(this->m_currentState);
//    Renderer2D::Instance()->Render(texture, {this->x(),this->y()}, this->width(), this->height());
}
