#include "UILayer.h"
#include <iostream>
#include <LayerIDs.h>
#include <TextureManager.h>
#include <SDLTexture.h>
#include <TextureIDs.h>
#include <Renderer2D.h>

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
    TextureManager::Instance()->Load(std::make_shared<SDLTexture>(), EMIU_IMG_ID, "./res/Images/eiu.png");
}

void UILayer::Update(float deltaTime)
{

}

void UILayer::Render(IRenderer *renderer)
{
    ITexture* eiuTexture = TextureManager::Instance()->GetTextureByID(EMIU_IMG_ID);
    Renderer2D::Instance()->Render(eiuTexture, {0,0}, 721, 1002, false);
}

void UILayer::Cleanup()
{

}
