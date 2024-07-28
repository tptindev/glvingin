#include "GameScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <SceneManager.h>
#include <SceneIDs.h>
#include <Manager.h>
#include "Entities/Player.h"

GameScene::GameScene()
{
    this->setId(SCENE_ID::GAME_SCENE);
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
        SceneManager::Instance()->Transition(SCENE_ID::MENU_SCENE);
    }
}

void GameScene::Update()
{
    std::unordered_map<int, AEntity *>& entities = EntityManager::Instance()->GetEntities(this);
    std::unordered_map<int, AEntity *>::iterator it = entities.begin();
    while (it != entities.end())
    {
        it->second->Update();
        it++;
    }
}

void GameScene::Render()
{
    std::unordered_map<int, AEntity *>& entities = EntityManager::Instance()->GetEntities(this);
    std::unordered_map<int, AEntity *>::iterator it = entities.begin();
    while (it != entities.end())
    {
        it->second->Render();
        it++;
    }
}
