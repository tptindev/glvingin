#include "MenuBackground.h"
#include <iostream>
#include <EntityIDs.h>
#include <Components/Transform2D.h>
#include <Components/Sprite2D.h>

MenuBackground::MenuBackground()
{
    this->setId(EntityIDs::MenuScene::BACKGROUND);
    this->setName("Background");
    this->AddComponent<Transform2D>(glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f});
    this->AddComponent<Sprite2D>("res/images/bg.png", 0.5f);
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
