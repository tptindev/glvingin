#include "AEntity.h"
#include <iostream>
AEntity::AEntity()
{
    std::cout << __FUNCTION__ << std::endl;
}

AEntity::AEntity(const AEntity &copy)
{
    this->m_id = copy.m_id;
    this->m_name = copy.m_name;
    this->m_components = copy.m_components;
}

AEntity::AEntity(AEntity &&move)
{
    this->m_id = std::move(move.m_id);
    this->m_name = std::move(move.m_name);
    this->m_components = std::move(move.m_components);
}

AEntity &AEntity::operator=(const AEntity &copy)
{
    this->m_id = copy.m_id;
    this->m_name = copy.m_name;
    this->m_components = copy.m_components;
    return (*this);
}

AEntity &AEntity::operator=(AEntity &&move)
{
    this->m_id = std::move(move.m_id);
    this->m_name = std::move(move.m_name);
    this->m_components = std::move(move.m_components);
    return (*this);
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

int AEntity::id() const
{
    return m_id;
}

void AEntity::setId(int newId)
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
