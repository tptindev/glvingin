#include "StartButton.h"
#include <iostream>
#include <EntityIDs.h>
#include <Components/Transform2D.h>

StartButton::StartButton()
{
    this->setId(EntityIDs::MenuScene::START_BUTTON);
    this->setName("Start");
    this->AddComponent<Transform2D>(glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f});
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

StartButton::~StartButton()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

void StartButton::Update(float deltaTime)
{
    
}

void StartButton::Render()
{
    
}
