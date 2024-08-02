#include "MenuBackground.h"
#include <iostream>
#include <EntityIDs.h>
#include <Manager.h>
#include <Components/Transform2D.h>
#include <Components/Sprite2D.h>

MenuBackground::MenuBackground()
{
    this->setId(EntityIDs::MenuScene::BACKGROUND);
    this->setName("Background");
    this->AddComponent<Transform2D>(glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f});
    this->AddComponent<Sprite2D>("res/images/bg.png", 1.0f);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

MenuBackground::~MenuBackground()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

void MenuBackground::Update(float deltaTime)
{
    SystemManager::Instance()->Update<Transform2D>(this);
    SystemManager::Instance()->Update<Sprite2D>(this);
}

void MenuBackground::Render()
{
    SystemManager::Instance()->Render<Sprite2D>(this);
}
