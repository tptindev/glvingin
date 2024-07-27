#ifndef ENTITY_H
#define ENTITY_H

#include <functional>
#include <unordered_map>
#include <bitset>
#include "Component.h"

class Entity
{
public:
    typedef struct
    {
        std::bitset<32> bits; // max 32 Components/1 Entity
        std::unordered_map<const char*, int> names;
        std::unordered_map<int, Component*> comps;
    } Components;

    Entity();
    virtual ~Entity();

    template<typename T>
    T* GetComponent() const
    {
        T comp;
        const char* name = comp.name();
        int idx = this->m_components.names.at(name);
        return this->m_components.comps.at(idx);
    }

    template<typename T, typename ...Args>
    void AddComponent(Args&& ...args)
    {
        Component* comp = new T(std::forward<Args>(args)...);
        for (size_t i = 0; i < this->m_components.bits.size(); ++i)
        {
            if (this->m_components.bits[i] == 0)
            {
                this->m_components.bits.set(i);
                this->m_components.names[comp->name()] = i;
                this->m_components.comps[i] = std::move(comp);
                break;
            }
        }
        return;
    }

    void RemoveComponent(int index);
    void RemoveComponent(const char* name);


    unsigned int id() const;
    void setId(unsigned int newId);

    const char *name() const;
    void setName(const char *newName);


    virtual void Update();
    virtual void Render();

private:
    int m_id;
    const char* m_name;
    Components m_components;
};

#endif // ENTITY_H
