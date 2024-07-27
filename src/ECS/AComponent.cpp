#include "AComponent.h"
#include <iostream>

AComponent::AComponent()
{
    std::cout << __FUNCTION__ << std::endl;
}

void AComponent::setName(const char *newName)
{
    m_name = newName;
}

AComponent::~AComponent()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

const char *AComponent::name() const
{
    return m_name;
}
