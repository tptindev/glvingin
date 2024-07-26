#ifndef ECSMANAGER_H
#define ECSMANAGER_H


#include <unordered_map>
#include <vector>
#include "AEntity.h"


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
    AEntity* CreateEntity(const char* name);
    void DestroyEntity(AEntity* entity);

private:
    static EntityManager* s_instance;
    EntityManager();
    std::unordered_map<const char*, AEntity*> m_entities;

};

#endif // ECSMANAGER_H
