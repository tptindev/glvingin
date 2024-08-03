#ifndef MANAGER_H
#define MANAGER_H


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
    static EntityManager *Instance();
    static void ResetInstance();
    ~EntityManager();

public:
    void LoadEntity(AEntity* entity, int layerID);
    std::unordered_map<int, AEntity*>& GetEntities(int layerID);
    void DestroyEntity(AEntity* entity, int layerID);
    void DestroyEntities();

private:
    static EntityManager* s_instance;
    EntityManager();
    std::unordered_map<int, std::unordered_map<int, AEntity*>> m_entities;

};

class SystemManager
{
public:
    SystemManager(const SystemManager &) = delete;
    SystemManager(SystemManager &&) = delete;
    SystemManager &operator=(const SystemManager &) = delete;
    SystemManager &operator=(SystemManager &&) = delete;
    static SystemManager *Instance();
    static void ResetInstance();
    ~SystemManager();

    template<typename T>
    void Update(AEntity* entity)
    {
        T* component = entity->GetComponent<T>();
        return;
    }

    template<typename T>
    void Render(AEntity* entity)
    {
        T* component = entity->GetComponent<T>();
        return;
    }

private:
    static SystemManager* s_instance;
    SystemManager();
};

#endif // MANAGER_H
