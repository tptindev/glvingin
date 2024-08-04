#include "SDLText.h"
#include <SDL2/SDL_ttf.h>
#include <SDLTexture.h>
#include <FontManager.h>
#include <TextureManager.h>
#include <Renderer2D.h>

SDLText::SDLText(const char *text, int x, int y, int w, int h)
    :m_text{text}
{

}

SDLText::~SDLText()
{

}

void SDLText::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    this->m_color.r = r;
    this->m_color.g = g;
    this->m_color.b = b;
    this->m_color.a = a;
}

void SDLText::setFont(const char *fontName, int fontSize)
{
    if (fontName == nullptr || fontSize == 0) return;
    this->m_font = dynamic_cast<SDLFont*>(FontManager::Instance()->GetFont(fontName, fontSize));
}

void SDLText::Initialize()
{

}

void SDLText::Completed()
{
    TextureManager::Instance()->LoadTxt(
        std::make_shared<SDLTexture>(),
        this->m_textureID,
        this->m_text,
        this->m_font,
        this->m_color.r,
        this->m_color.g,
        this->m_color.b,
        this->m_color.a
        );
}

void SDLText::HandleEvent()
{

}

void SDLText::Render()
{
    ITexture* texture = TextureManager::Instance()->GetTextureByID(this->m_textureID);
    Renderer2D::Instance()->Render(texture, {this->x(),this->y()}, this->width(), this->height());
}

void SDLText::setTextureID(int newTextureID)
{
    m_textureID = newTextureID;
}
