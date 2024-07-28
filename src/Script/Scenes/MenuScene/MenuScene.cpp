#include "MenuScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <SceneManager.h>
#include <Manager.h>
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
    AEntity* bg = new MenuBackground();
    AEntity* start = new StartButton();
    AEntity* setting = new SettingButton();
    AEntity* exit = new ExitButton();

    EntityManager::Instance()->LoadEntity(bg, this);
    EntityManager::Instance()->LoadEntity(start, this);
    EntityManager::Instance()->LoadEntity(setting, this);
    EntityManager::Instance()->LoadEntity(exit, this);
}

void MenuScene::EventHandle(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
    {
        SceneManager::Instance(nullptr)->Transition(SCENE_ID::GAME_SCENE);
    }
    else if (key == GLFW_KEY_BACKSPACE && action == GLFW_PRESS)
    {
        SceneManager::Instance(nullptr)->Transition(SCENE_ID::SETTING_SCENE);
    }
    else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void MenuScene::Update()
{
    std::unordered_map<int, AEntity *>& entities = EntityManager::Instance()->GetEntities(this);
    std::unordered_map<int, AEntity *>::iterator it = entities.begin();
    while (it != entities.end())
    {
        it->second->Update();
        it++;
    }
}

void MenuScene::Render()
{
    std::unordered_map<int, AEntity *>& entities = EntityManager::Instance()->GetEntities(this);
    std::unordered_map<int, AEntity *>::iterator it = entities.begin();
    while (it != entities.end())
    {
        it->second->Render();
        it++;
    }
}
