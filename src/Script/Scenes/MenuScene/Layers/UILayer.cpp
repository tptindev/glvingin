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
    this->m_btnStart = std::make_shared<SDLButton>(50, 50, 125, 50);
    this->m_btnStart->Initialize();
    this->m_btnStart->setNormal({215, 178, 20}, {255, 255, 255});
    this->m_btnStart->setPressed({255, 255, 255}, {215, 178, 20});
    this->m_btnStart->setReleased({215, 178, 20}, {255, 255, 255});
    this->m_btnStart->attachText(TextureIDs::MENU_BG_TEXT_HELLO_1, FONT_RAINYHEARTS_32, "Start");
    this->m_btnStart->Completed();

    this->m_btnAbout = std::make_shared<SDLButton>(50, 120, 125, 50);
    this->m_btnAbout->Initialize();
    this->m_btnAbout->setNormal({215, 178, 20}, {255, 255, 255});
    this->m_btnAbout->setPressed({255, 255, 255}, {215, 178, 20});
    this->m_btnAbout->setReleased({215, 178, 20}, {255, 255, 255});
    this->m_btnAbout->attachText(TextureIDs::MENU_BG_TEXT_HELLO_2, FONT_RAINYHEARTS_32, "About");
    this->m_btnAbout->Completed();
}

void UILayer::Update(float deltaTime)
{

}

void UILayer::Render(IRenderer *renderer)
{
    this->m_btnStart->Render();
    this->m_btnAbout->Render();
}

void UILayer::Cleanup()
{

}
