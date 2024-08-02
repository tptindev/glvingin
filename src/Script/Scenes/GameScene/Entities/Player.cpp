#include "Player.h"
#include <iostream>
#include <Manager.h>
#include <EntityIDs.h>
#include <Components/Transform2D.h>
#include <Components/Health.h>
#include <Components/HealthVisual.h>
#include <Components/CircleCollider2D.h>
#include <Components/AnimatedSprite2D.h>
Player::Player()
{
    this->setId(EntityIDs::GameScene::PLAYER);
    this->setName("Player");
    this->AddComponent<Transform2D>(glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{0.0f, 0.0f});
    this->AddComponent<CircleCollider2D>();
    this->AddComponent<Health>(100.0f);
    this->AddComponent<HealthVisual>();
    this->AddComponent<AnimatedSprite2D>("", 0, 0, 0, 1, 0.0f);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

Player::~Player()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

void Player::Update(float deltaTime)
{
    SystemManager::Instance()->Update<Transform2D>(this);
    SystemManager::Instance()->Update<CircleCollider2D>(this);
    SystemManager::Instance()->Update<Health>(this);
    SystemManager::Instance()->Update<HealthVisual>(this);
    SystemManager::Instance()->Update<AnimatedSprite2D>(this);
}

void Player::Render()
{
    SystemManager::Instance()->Render<HealthVisual>(this);
    SystemManager::Instance()->Render<AnimatedSprite2D>(this);
}
