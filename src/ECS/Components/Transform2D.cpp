#include "Transform2D.h"
#include <iostream>

Transform2D::Transform2D()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
    this->setName(__FUNCTION__);
}
