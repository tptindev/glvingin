#include "HealthVisual.h"
#include <iostream>

HealthVisual::HealthVisual()
{
    this->setName(__FUNCTION__);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

HealthVisual::~HealthVisual()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}
