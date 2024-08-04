#include "UILayer.h"
#include <iostream>
#include <LayerIDs.h>
#include <TextureManager.h>
#include <SDLTexture.h>
#include <TextureIDs.h>
#include <Renderer2D.h>
#include <Widget/SDLButton.h>
#include <Widget/SDLButtonIMG.h>

UILayer::UILayer()
{
    this->setId(LayerIDs::MENU_LAYER_1);
    std::cout << __FUNCTION__ << std::endl;
}

UILayer::~UILayer()
{
    std::cout << __FUNCTION__ << std::endl;
}

void UILayer::Initialize()
{
//    this->m_btnStart = std::make_shared<SDLButton>(50, 50, 125, 50);
//    this->m_btnStart->Initialize();
//    this->m_btnStart->Completed();

//    this->m_btnAbout = std::make_shared<SDLButtonIMG>(50, 120, 125, 50);
//    this->m_btnAbout->Initialize();
//    this->m_btnAbout->setCurrentState(MENU_BTN_ABOUT_NORMAL_TEXTURE_ID);
//    this->m_btnAbout->setNormal(MENU_BTN_ABOUT_NORMAL_TEXTURE_ID);
//    this->m_btnAbout->setPressed(MENU_BTN_ABOUT_PRESSED_TEXTURE_ID);
//    this->m_btnAbout->setReleased(MENU_BTN_ABOUT_RELEASED_TEXTURE_ID);
//    this->m_btnAbout->Completed();
}

void UILayer::Update(float deltaTime)
{

}

void UILayer::Render(IRenderer *renderer)
{
//    this->m_btnStart->Render();
//    this->m_btnAbout->Render();
}

void UILayer::Cleanup()
{

}
