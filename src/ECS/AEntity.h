#ifndef AENTITY_H
#define AENTITY_H

#include <functional>
#include <unordered_map>
#include <bitset>
#include "AComponent.h"
class AEntity
{
public:
    typedef struct
    {
        std::bitset<32> bits; // max 32 Components/1 Entity
        std::unordered_map<const char*, int> names;
        std::unordered_map<int, AComponent*> comps;
    } Components;

    AEntity();
    AEntity(const AEntity &);
    AEntity(AEntity &&);
    AEntity &operator=(const AEntity &);
    AEntity &operator=(AEntity &&);
    virtual ~AEntity();

    template<typename T>
    T* GetComponent()
    {
        T comp;
        const char* name = comp.name();
        const int idx = this->m_components.names.at(name);
        return (T*)(this->m_components.comps[idx]);
    }

    template<typename T>
    bool HasComponent()
    {
        const T* comp = GetComponent<T>();
        return (comp != nullptr);
    }

    template<typename T, typename ...Args>
    void AddComponent(Args&& ...args)
    {
        AComponent* comp = new T(std::forward<Args>(args)...);
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


    int id() const;
    void setId(int newId);

    const char *name() const;
    void setName(const char *newName);


    virtual void Update();
    virtual void Render();

private:
    int m_id;
    const char* m_name;
    Components m_components;
};

#endif // AENTITY_H
