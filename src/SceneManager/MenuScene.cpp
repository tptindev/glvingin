#include "MenuScene.h"

MenuScene::MenuScene()
{
    this->setTitle("Menu");
    this->setWidth(640);
    this->setHeight(420);

    this->Setup();
}

void MenuScene::EventHandle()
{
    glfwSetKeyCallback(this->buffer(), [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    });
}

void MenuScene::Update()
{

}

void MenuScene::Render()
{

}
