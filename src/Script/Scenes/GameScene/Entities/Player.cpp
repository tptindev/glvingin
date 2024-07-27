#include "Player.h"
#include <iostream>
#include <EntityIDs.h>
#include <Components/Transform2D.h>
#include <Components/Health.h>

Player::Player()
{
    this->setId(EntityIDs::GameScene::PLAYER);
    this->setName("Player");
    this->AddComponent<Transform2D>(glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f});
    this->AddComponent<Health>(100.0f);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

Player::~Player()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

void Player::Update()
{

}

void Player::Render()
{

}
