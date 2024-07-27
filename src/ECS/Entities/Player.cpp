#include "Player.h"
#include <iostream>
#include "../../IDs/EntityIDs.h"

Player::Player()
{
    this->setId(ENTITY_PLAYER);
    this->setName("Player");
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
