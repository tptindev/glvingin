#include "SDLButtonIMG.h"
#include <iostream>
#include <TextureManager.h>
#include <SDLTexture.h>
#include <Renderer2D.h>
SDLButtonIMG::SDLButtonIMG(int textureID, const char *imgFilePath)
    : m_textureID(textureID), m_imgFilePath(imgFilePath), SDLButton(0, 0, 0, 0)
{
    std::cout << __FUNCTION__ << std::endl;
}

SDLButtonIMG::SDLButtonIMG(int textureID, const char *imgFilePath, int x, int y, int w, int h)
    : m_textureID(textureID), m_imgFilePath(imgFilePath), SDLButton(x, y, w, h)
{
    std::cout << __FUNCTION__ << std::endl;
}

SDLButtonIMG::~SDLButtonIMG()
{
    std::cout << __FUNCTION__ << std::endl;
}

void SDLButtonIMG::Initialize()
{
    TextureManager::Instance()->Load(std::make_shared<SDLTexture>(), this->m_textureID, this->m_imgFilePath);
}

void SDLButtonIMG::HandleEvent()
{

}

void SDLButtonIMG::Render()
{
    ITexture* texture = TextureManager::Instance()->GetTextureByID(this->m_textureID);
    Renderer2D::Instance()->Render(texture, {this->x(),this->y()}, this->width(), this->height(), false);
}
