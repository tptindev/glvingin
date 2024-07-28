#include "MenuBackground.h"
#include <iostream>
#include <EntityIDs.h>
#include <Components/Transform2D.h>

MenuBackground::MenuBackground()
{
    this->setId(EntityIDs::MenuScene::BACKGROUND);
    this->setName("Background");
    this->AddComponent<Transform2D>(glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f});
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

MenuBackground::~MenuBackground()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

void MenuBackground::Update()
{

}

void MenuBackground::Render()
{

}
