#include "GameScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <SceneManager.h>
#include <SceneIDs.h>
#include <Manager.h>
#include "Entities/Player.h"

GameScene::GameScene()
{
    this->setId(SCENE_ID::SCENE_GAME);
    this->setTitle("Game");
    this->setWidth(640);
    this->setHeight(420);
    std::cout << __FUNCTION__ << ":" << this->title() << std::endl;
}

GameScene::~GameScene()
{
    std::cout << __FUNCTION__ << ":" << this->title() << std::endl;
}

void GameScene::Initialize()
{
    AEntity* player = new Player();

    EntityManager::Instance()->LoadEntity(player, this);
}

void GameScene::EventHandle(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        SceneManager::Instance(nullptr)->Transition(SCENE_ID::SCENE_MENU);
    }
}

void GameScene::Update()
{

}

void GameScene::Render()
{
}
