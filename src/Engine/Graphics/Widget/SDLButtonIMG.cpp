#include "SDLButtonIMG.h"
#include <iostream>
#include <TextureManager.h>
#include <SDLTexture.h>
#include <Renderer2D.h>
#include "SDLText.h"
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

void SDLButtonIMG::SetNormal(std::shared_ptr<SDLImage> image_ptr, SDL_Color textColor)
{
    image_ptr->Initialize();
    image_ptr->setX(this->x());
    image_ptr->setY(this->y());
    image_ptr->setWidth(this->width());
    image_ptr->setHeight(this->height());
    image_ptr->Completed();
    if (this->Text() != nullptr)
    {
        this->Text()->setColor(textColor.r, textColor.g, textColor.b, textColor.a);
    }
    this->m_bgImgState[NORMAL] = image_ptr;
}

void SDLButtonIMG::SetPressed(std::shared_ptr<SDLImage> image_ptr, SDL_Color textColor)
{
    image_ptr->Initialize();
    image_ptr->setX(this->x());
    image_ptr->setY(this->y());
    image_ptr->setWidth(this->width());
    image_ptr->setHeight(this->height());
    image_ptr->Completed();
    if (this->Text() != nullptr)
    {
        this->Text()->setColor(textColor.r, textColor.g, textColor.b, textColor.a);
    }
    this->m_bgImgState[PRESSED] = image_ptr;
}

void SDLButtonIMG::SetReleased(std::shared_ptr<SDLImage> image_ptr, SDL_Color textColor)
{
    image_ptr->Initialize();
    image_ptr->setX(this->x());
    image_ptr->setY(this->y());
    image_ptr->setWidth(this->width());
    image_ptr->setHeight(this->height());
    image_ptr->Completed();
    if (this->Text() != nullptr)
    {
        this->Text()->setColor(textColor.r, textColor.g, textColor.b, textColor.a);
    }
    this->m_bgImgState[RELEASED] = image_ptr;
}

void SDLButtonIMG::Initialize()
{
    this->m_currentState = NORMAL;
}

void SDLButtonIMG::Completed()
{

}

void SDLButtonIMG::HandleEvent()
{

}

void SDLButtonIMG::Render()
{
    int textureID = this->m_bgImgState[this->m_currentState]->textureID();
    ITexture* texture = TextureManager::Instance()->GetTextureByID(textureID);
    Renderer2D::Instance()->Render(texture, this->x(),this->y());
    if (this->Text() != nullptr)
    {
        this->Text()->Render();
    }
}

void SDLButtonIMG::OnClicked()
{
    
}

void SDLButtonIMG::OnPressed()
{
    
}

void SDLButtonIMG::OnLongPressed()
{
    
}

void SDLButtonIMG::OnReleased()
{
    
}
