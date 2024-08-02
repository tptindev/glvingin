#include "MenuScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <SceneManager.h>
#include <SceneIDs.h>
#include "Entities/MenuBackground.h"
#include "Entities/StartButton.h"
#include "Entities/SettingButton.h"
#include "Entities/ExitButton.h"

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
}

void MenuScene::HandleEvents()
{
}
