#include "UILayer.h"
#include <iostream>
#include <LayerIDs.h>
#include <TextureManager.h>
#include <SDLTexture.h>
#include <TextureIDs.h>
#include <Renderer2D.h>
#include <Widget/SDLImage.h>
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
    this->m_btnStart = std::make_shared<SDLButtonIMG>(50, 50, 125, 50);
    this->m_btnStart->Initialize();
    this->m_btnStart->setNormal(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_NORMAL_TEXTURE_ID, "./res/Images/released.png"));
    this->m_btnStart->setPressed(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_PRESSED_TEXTURE_ID, "./res/Images/pressed.png"));
    this->m_btnStart->setReleased(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_RELEASED_TEXTURE_ID, "./res/Images/released.png"));
    this->m_btnStart->attachText(TextureIDs::MENU_BTN_START_LBL, FONT_RAINYHEARTS_32, "Start");
    this->m_btnStart->Completed();

    this->m_btnSetting = std::make_shared<SDLButtonIMG>(50, 120, 125, 50);
    this->m_btnSetting->Initialize();
    this->m_btnSetting->setNormal(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_NORMAL_TEXTURE_ID, "./res/Images/released.png"));
    this->m_btnSetting->setPressed(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_PRESSED_TEXTURE_ID, "./res/Images/pressed.png"));
    this->m_btnSetting->setReleased(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_RELEASED_TEXTURE_ID, "./res/Images/released.png"));
    this->m_btnSetting->attachText(TextureIDs::MENU_BTN_SETTING_LBL, FONT_RAINYHEARTS_32, "Setting");
    this->m_btnSetting->Completed();

    this->m_btnAbout = std::make_shared<SDLButtonIMG>(50, 190, 125, 50);
    this->m_btnAbout->Initialize();
    this->m_btnAbout->setNormal(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_NORMAL_TEXTURE_ID, "./res/Images/released.png"));
    this->m_btnAbout->setPressed(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_PRESSED_TEXTURE_ID, "./res/Images/pressed.png"));
    this->m_btnAbout->setReleased(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_RELEASED_TEXTURE_ID, "./res/Images/released.png"));
    this->m_btnAbout->attachText(TextureIDs::MENU_BTN_ABOUT_LBL, FONT_RAINYHEARTS_32, "About");
    this->m_btnAbout->Completed();

    this->m_btnQuit = std::make_shared<SDLButtonIMG>(50, 260, 125, 50);
    this->m_btnQuit->Initialize();
    this->m_btnQuit->setNormal(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_NORMAL_TEXTURE_ID, "./res/Images/released.png"));
    this->m_btnQuit->setPressed(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_PRESSED_TEXTURE_ID, "./res/Images/pressed.png"));
    this->m_btnQuit->setReleased(std::make_shared<SDLImage>(TextureIDs::MENU_BTN_RELEASED_TEXTURE_ID, "./res/Images/released.png"));
    this->m_btnQuit->attachText(TextureIDs::MENU_BTN_QUIT_LBL, FONT_RAINYHEARTS_32, "Quit");
    this->m_btnQuit->Completed();
}

void UILayer::Update(float deltaTime)
{

}

void UILayer::Render(IRenderer *renderer)
{
    this->m_btnStart->Render();
    this->m_btnSetting->Render();
    this->m_btnAbout->Render();
    this->m_btnQuit->Render();
}

void UILayer::Cleanup()
{

}
