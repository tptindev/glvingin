#include "Health.h"
#include <iostream>
Health::Health(): m_current(0.0f), m_max(0.0f)
{
    this->setName(__FUNCTION__);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

Health::~Health()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

Health::Health(float current, float max) : m_current(current), m_max(max)
{
    this->setName(__FUNCTION__);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

Health::Health(float max) : m_current(max), m_max(max)
{
    this->setName(__FUNCTION__);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}
