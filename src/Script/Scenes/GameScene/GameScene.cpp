#include "GameScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <SceneManager.h>
#include <SceneIDs.h>

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
}

void GameScene::HandleEvent()
{

}
