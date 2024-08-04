#include "SDLImage.h"
#include <TextureManager.h>
#include <SDLTexture.h>
#include <Renderer2D.h>
SDLImage::SDLImage(const char *source, int x, int y, int w, int h)
    : m_source(source)
{
    this->setX(x);
    this->setY(y);
    this->setWidth(w);
    this->setHeight(h);
}

SDLImage::~SDLImage()
{

}

void SDLImage::Initialize()
{
}

void SDLImage::Completed()
{
    TextureManager::Instance()->LoadIMG(std::make_shared<SDLTexture>(), this->m_textureID, this->m_source);
}

void SDLImage::HandleEvent()
{

}

void SDLImage::Render()
{
    ITexture* texture = TextureManager::Instance()->GetTextureByID(this->m_textureID);
    Renderer2D::Instance()->Render(texture, {this->x(),this->y()}, this->width(), this->height());
}

void SDLImage::setTextureID(int newTextureID)
{
    m_textureID = newTextureID;
}
