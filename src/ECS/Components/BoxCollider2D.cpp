#include "BoxCollider2D.h"
#include <iostream>

BoxCollider2D::BoxCollider2D()
{
    this->setName(__FUNCTION__);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}
