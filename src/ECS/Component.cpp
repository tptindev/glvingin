#include "Component.h"
#include <iostream>

Component::Component()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

void Component::setName(const char *newName)
{
    m_name = newName;
}

Component::~Component()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

const char *Component::name() const
{
    return m_name;
}
