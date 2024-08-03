#include "BackgroundLayer.h"
#include <iostream>
#include <LayerIDs.h>
#include <TextureManager.h>
#include <SDLTexture.h>

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
    TextureManager::Instance()->Load(std::make_shared<SDLTexture>(), 0, "res/Images/bg.png");
}

void BackgroundLayer::Update(float deltaTime)
{

}

void BackgroundLayer::Render(IRenderer *renderer)
{

}

void BackgroundLayer::Cleanup()
{

}
