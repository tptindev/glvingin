#include "BackgroundLayer.h"
#include <iostream>
#include <LayerIDs.h>
#include <FontIDs.h>
#include <TextureManager.h>
#include <SDLTexture.h>
#include <TextureIDs.h>
#include <Renderer2D.h>
#include <Widget/SDLImage.h>
#include <Widget/SDLText.h>

BackgroundLayer::BackgroundLayer()
{
    this->setId(LayerIDs::MENU_LAYER_0);
    std::cout << __FUNCTION__ << std::endl;
}

BackgroundLayer::~BackgroundLayer()
{
    std::cout << __FUNCTION__ << std::endl;
}

void BackgroundLayer::Initialize()
{
    this->m_bg = std::make_shared<SDLImage>("./res/Images/bg.png", 0, 0, 1360, 786);
    this->m_bg->Initialize();
    this->m_bg->setTextureID(TextureIDs::MENU_BG_TEXTURE_ID);
    this->m_bg->setScale(0.5f);
    this->m_bg->Completed();

    this->m_hello = std::make_shared<SDLText>("Van Lang", 200, 400);
    this->m_hello->Initialize();
    this->m_hello->setFont(FONT_RAINYHEARTS_32);
    this->m_hello->setColor(0x0, 0x0, 0x0, 0xFF);
    this->m_hello->setTextureID(TextureIDs::MENU_BG_TEXT_HELLO);
    this->m_hello->Completed();
}

void BackgroundLayer::Update(float deltaTime)
{

}

void BackgroundLayer::Render(IRenderer *renderer)
{
    this->m_bg->Render();
    this->m_hello->Render();
}

void BackgroundLayer::Cleanup()
{

}
