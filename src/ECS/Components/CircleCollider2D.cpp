#include "CircleCollider2D.h"
#include <iostream>
CircleCollider2D::CircleCollider2D()
{
    this->setName(__FUNCTION__);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

CircleCollider2D::~CircleCollider2D()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}
