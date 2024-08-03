#include "SettingScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <SceneManager.h>
#include <SceneIDs.h>
SettingScene::SettingScene()
{
    this->setId(SCENE_ID::SETTING_SCENE);
    this->setTitle("Setting");
    this->setWidth(640);
    this->setHeight(420);
    std::cout << __FUNCTION__ << ":" << this->title() << std::endl;
}

SettingScene::~SettingScene()
{
    std::cout << __FUNCTION__ << ":" << this->title() << std::endl;
}

void SettingScene::Initialize()
{

}

void SettingScene::HandleEvent()
{
}
