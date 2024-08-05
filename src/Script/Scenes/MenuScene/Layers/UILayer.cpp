#include "UILayer.h"
#include <iostream>
#include <LayerIDs.h>
#include <TextureManager.h>
#include <SDLTexture.h>
#include <TextureIDs.h>
#include <Renderer2D.h>
#include <Widget/SDLButton.h>
#include <Widget/SDLButtonIMG.h>
#include <Widget/SDLText.h>
#include <FontIDs.h>

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
    std::shared_ptr<SDLText> text = std::make_shared<SDLText>("Start", 0, 0, 50, 25);
    text->Initialize();
    text->setFont(FONT_CRUX_21);
    text->setColor(0x0, 0x0, 0x0, 0xFF);
    text->setTextureID(TextureIDs::MENU_BG_TEXT_HELLO_1);
    text->Completed();
    this->m_btnStart = std::make_shared<SDLButton>(50, 50, 125, 50);
    this->m_btnStart->Initialize();
    this->m_btnStart->setNormal({100, 50, 80, 255}, {0, 0, 255, 255});
    this->m_btnStart->setPressed({80, 50, 80, 255}, {255, 0, 0, 255});
    this->m_btnStart->setNormal({100, 50, 80, 255}, {0, 0, 0, 255});
    this->m_btnStart->attachText(text);
    this->m_btnStart->Completed();

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
    this->m_btnStart->Render();
//    this->m_btnAbout->Render();
}

void UILayer::Cleanup()
{

}
