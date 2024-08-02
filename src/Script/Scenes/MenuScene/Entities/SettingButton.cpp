#include "SettingButton.h"
#include <iostream>
#include <EntityIDs.h>
#include <Components/Transform2D.h>
SettingButton::SettingButton()
{
    this->setId(EntityIDs::MenuScene::SETTING_BUTTON);
    this->setName("Setting");
    this->AddComponent<Transform2D>(glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f});
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

SettingButton::~SettingButton()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

void SettingButton::Update(float deltaTime)
{
    
}

void SettingButton::Render()
{
    
}
