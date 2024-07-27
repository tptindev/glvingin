#include "Entity.h"
#include <iostream>
Entity::Entity()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

Entity::~Entity()
{
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
    for (size_t i = 0; i < this->m_components.bits.size(); i++)
    {
        RemoveComponent(i);
    }
}

void Entity::RemoveComponent(int index)
{
    Component* comp = this->m_components.comps[index];
    this->m_components.bits.set(index, 0);
    this->m_components.names.erase(this->m_components.names.find(comp->name()));
    this->m_components.comps.erase(this->m_components.comps.find(index));
    if (comp != nullptr)
    {
        delete comp;
        comp = nullptr;
    }

}

void Entity::RemoveComponent(const char *name)
{
    std::unordered_map<const char*, int>::iterator it = this->m_components.names.find(name);
    if (it != this->m_components.names.end())
    {
        RemoveComponent(it->second);
    }
}

unsigned int Entity::id() const
{
    return m_id;
}

void Entity::setId(unsigned int newId)
{
    m_id = newId;
}

const char *Entity::name() const
{
    return m_name;
}

void Entity::setName(const char *newName)
{
    m_name = newName;
}

void Entity::Update()
{

}

void Entity::Render()
{

}
