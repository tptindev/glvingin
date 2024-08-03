#include "BackgroundLayer.h"
#include <iostream>
#include <LayerIDs.h>
#include <TextureManager.h>
#include <SDLTexture.h>
#include <TextureIDs.h>
#include <Renderer2D.h>

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
    TextureManager::Instance()->Load(std::make_shared<SDLTexture>(), MENU_BG_TEXTURE_ID, "./res/Images/bg.png");
}

void BackgroundLayer::Update(float deltaTime)
{

}

void BackgroundLayer::Render(IRenderer *renderer)
{
    ITexture* bgTexture = TextureManager::Instance()->GetTextureByID(MENU_BG_TEXTURE_ID);
    Renderer2D::Instance()->Render(bgTexture, {0,0}, 1360, 786, false);
}

void BackgroundLayer::Cleanup()
{

}
