#include "BackgroundLayer.h"
#include <iostream>
#include <LayerIDs.h>

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
