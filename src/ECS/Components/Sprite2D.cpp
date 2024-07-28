#include "Sprite2D.h"
#include <iostream>

Sprite2D::Sprite2D()
{
    this->setName(__FUNCTION__);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

Sprite2D::Sprite2D(const char *path, float offset, int z_order, bool flip)
{
    this->setName(__FUNCTION__);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}
