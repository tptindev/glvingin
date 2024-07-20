#include "GameScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "../SceneManager.h"
GameScene::GameScene(GLFWwindow* surface, SceneManager* manager): AScene(surface, manager)
{
    this->setTitle("Game");
    this->setWidth(640);
    this->setHeight(420);
}

GameScene::~GameScene()
{
    std::cout << __FUNCTION__ << std::endl;
}

void GameScene::EventHandle()
{
    glfwSetKeyCallback(this->surface(), [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            GameScene::manager()->Transition(0);
        }
    });
}

void GameScene::Update()
{

}

void GameScene::Render()
{

}
