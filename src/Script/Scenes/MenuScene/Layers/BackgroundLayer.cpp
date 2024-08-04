#include "BackgroundLayer.h"
#include <iostream>
#include <LayerIDs.h>
#include <TextureManager.h>
#include <SDLTexture.h>
#include <TextureIDs.h>
#include <Renderer2D.h>
#include <Widget/SDLImage.h>

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
    this->m_bg->setTextureID(MENU_BG_TEXTURE_ID);
    this->m_bg->Completed();
}

void BackgroundLayer::Update(float deltaTime)
{

}

void BackgroundLayer::Render(IRenderer *renderer)
{
    this->m_bg->Render();
}

void BackgroundLayer::Cleanup()
{

}
