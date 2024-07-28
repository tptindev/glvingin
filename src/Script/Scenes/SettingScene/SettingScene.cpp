#include "SettingScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <SceneManager.h>
#include <Manager.h>
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

void SettingScene::EventHandle(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        SceneManager::Instance(nullptr)->Transition(SCENE_ID::MENU_SCENE);
    }
}

void SettingScene::Update()
{

}

void SettingScene::Render()
{

}
