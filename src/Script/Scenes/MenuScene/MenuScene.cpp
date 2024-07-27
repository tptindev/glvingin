#include "MenuScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <SceneManager.h>
#include <SceneIDs.h>

MenuScene::MenuScene()
{
    this->setId(SCENE_ID::SCENE_MENU);
    this->setTitle("Menu");
    this->setWidth(640);
    this->setHeight(420);
    std::cout << __FUNCTION__ << ":" << this->title() << std::endl;
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
        SceneManager::Instance(nullptr)->Transition(SCENE_ID::SCENE_GAME);
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
