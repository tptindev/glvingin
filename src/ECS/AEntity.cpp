#include "AEntity.h"
#include <iostream>
AEntity::AEntity()
{
    std::cout << __FUNCTION__ << std::endl;
}

AEntity::~AEntity()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
    for (size_t i = 0; i < this->m_components.bits.size(); i++)
    {
        RemoveComponent(i);
    }
}

void AEntity::RemoveComponent(int index)
{
    if (this->m_components.bits[index] == 1)
    {
        AComponent* comp = this->m_components.comps[index];
        this->m_components.bits.set(index, 0);
        this->m_components.names.erase(this->m_components.names.find(comp->name()));
        this->m_components.comps.erase(this->m_components.comps.find(index));
        if (comp != nullptr)
        {
            delete comp;
            comp = nullptr;
        }
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
