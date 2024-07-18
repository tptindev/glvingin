#include "GameScene.h"
#include <GLFW/glfw3.h>
GameScene::GameScene(GLFWwindow* window, SceneManager* manager): AScene(window, manager)
{
    this->setTitle("Game");
    this->setWidth(640);
    this->setHeight(420);
}

void GameScene::EventHandle()
{
    glfwSetKeyCallback(this->window(), [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    });
}

void GameScene::Update()
{

}

void GameScene::Render()
{

}
