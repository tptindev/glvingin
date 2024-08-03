#include "UILayer.h"
#include <iostream>
#include <LayerIDs.h>

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

}

void UILayer::Update(float deltaTime)
{

}

void UILayer::Render(IRenderer *renderer)
{

}

void UILayer::Cleanup()
{

}
