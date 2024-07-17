#include "GameScene.h"

GameScene::GameScene()
{
    this->setTitle("Game");
    this->setWidth(640);
    this->setHeight(420);

    this->Setup();
}

void GameScene::EventHandle()
{
    glfwSetKeyCallback(this->buffer(), [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    });
}

void GameScene::Update()
{

}

void GameScene::Render()
{

}
