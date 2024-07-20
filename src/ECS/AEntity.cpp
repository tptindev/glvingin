#include "AEntity.h"
#include <iostream>
AEntity::AEntity()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

AEntity::~AEntity()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

void AEntity::RemoveComponent(unsigned int index)
{
    AComponent* comp = this->m_components.comps[index];
    this->m_components.bits.set(index, 0);
    this->m_components.names.erase(this->m_components.names.find(comp->name()), this->m_components.names.end());
    this->m_components.comps.erase(this->m_components.comps.find(index), this->m_components.comps.end());
    if (comp != nullptr)
    {
        delete comp;
        comp = nullptr;
    }

}

void AEntity::RemoveComponent(const char *name)
{
    std::unordered_map<const char*, int>::iterator it = this->m_components.names.find(name);
    if (it != this->m_components.names.end())
    {
        RemoveComponent(it->second);
    }
}

unsigned int AEntity::id() const
{
    return m_id;
}

void AEntity::setId(unsigned int newId)
{
    m_id = newId;
}

const char *AEntity::name() const
{
    return m_name;
}

void AEntity::setName(const char *newName)
{
    m_name = newName;
}

void AEntity::Update()
{

}

void AEntity::Render()
{

}
