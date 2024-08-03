#include "MenuScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <SceneIDs.h>
#include <LayerManager.h>
#include "Layers/BackgroundLayer.h"
#include "Layers/UILayer.h"

MenuScene::MenuScene()
{
    this->setId(SCENE_ID::MENU_SCENE);
    this->setTitle("Menu");
    this->setWidth(640);
    this->setHeight(420);
    std::cout << __FUNCTION__ << ":" << this->title() << std::endl;
}

MenuScene::~MenuScene()
{
    std::cout << __FUNCTION__ << ":" << this->title() << std::endl;
}

void MenuScene::Initialize()
{
    LayerManager::Instance()->AddLayer(std::make_shared<BackgroundLayer>(), this->id());
    LayerManager::Instance()->AddLayer(std::make_shared<UILayer>(), this->id());
}

void MenuScene::HandleEvents()
{
}
