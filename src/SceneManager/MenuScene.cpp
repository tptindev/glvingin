#include "MenuScene.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

MenuScene::MenuScene(GLFWwindow* window): AScene(window)
{
    this->setTitle("Menu");
    this->setWidth(640);
    this->setHeight(420);
}

void MenuScene::EventHandle()
{
    glfwSetKeyCallback(this->window(), [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    });
}

void MenuScene::Update()
{

}

void MenuScene::Render()
{

}
