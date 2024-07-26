#include "MenuScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "../SceneManager.h"

MenuScene::MenuScene(GLFWwindow* surface, SceneManager* manager): AScene(surface, manager)
{
    this->setTitle("Menu");
    this->setWidth(640);
    this->setHeight(420);
}

MenuScene::~MenuScene()
{
    std::cout << __FUNCTION__ << ":" << this->title() << std::endl;
}

void MenuScene::Initialize()
{

}

void MenuScene::EventHandle(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
    {
        MenuScene::manager()->Transition(1);
    }
    else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void MenuScene::Update()
{

}

void MenuScene::Render()
{

}
