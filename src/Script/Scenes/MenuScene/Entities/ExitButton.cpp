#include "ExitButton.h"
#include <iostream>
#include <EntityIDs.h>
#include <Components/Transform2D.h>

ExitButton::ExitButton()
{
    this->setId(EntityIDs::MenuScene::EXIT_BUTTON);
    this->setName("Exit");
    this->AddComponent<Transform2D>(glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f});

    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

ExitButton::~ExitButton()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

void ExitButton::Update(float deltaTime)
{
    
}

void ExitButton::Render()
{
    
}
