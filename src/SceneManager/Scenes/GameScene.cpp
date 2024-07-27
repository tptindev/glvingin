#include "GameScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "../SceneManager.h"
#include "../../ECS/Manager.h"
#include "../../IDs/SceneIDs.h"
#include "../../ECS/Entities/Player.h"

GameScene::GameScene(GLFWwindow* surface, SceneManager* manager): AScene(surface, manager)
{
    this->setId(SCENE_GAME);
    this->setTitle("Game");
    this->setWidth(640);
    this->setHeight(420);
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
        GameScene::manager()->Transition(0);
    }
}

void GameScene::Update()
{

}

void GameScene::Render()
{

}
