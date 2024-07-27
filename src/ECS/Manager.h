#ifndef MANAGER_H
#define MANAGER_H


#include <unordered_map>
#include <vector>
#include "Entity.h"


class EntityManager
{
public:
    EntityManager(const EntityManager &) = delete;
    EntityManager(EntityManager &&) = delete;
    EntityManager &operator=(const EntityManager &) = delete;
    EntityManager &operator=(EntityManager &&) = delete;
    static EntityManager *instance();
    ~EntityManager();

public:
    void LoadEntity(Entity* entity, void* scene);
    void DestroyEntity(Entity* entity, void* scene);
    void DestroyEntities();

private:
    static EntityManager* s_instance;
    EntityManager();
    std::unordered_map<void*, std::unordered_map<int, Entity*>> m_entities;

};

#endif // MANAGER_H
