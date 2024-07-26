#include "ECSManager.h"
#include <iostream>


EntityManager *EntityManager::s_instance = nullptr;
EntityManager *EntityManager::instance()
{
    if (EntityManager::s_instance == nullptr)
    {
        EntityManager::s_instance = new EntityManager();
    }
    return EntityManager::s_instance;
}

EntityManager::~EntityManager()
{

}

AEntity *EntityManager::CreateEntity(const char *name)
{
    return nullptr;
}

void EntityManager::DestroyEntity(AEntity *entity)
{

}

EntityManager::EntityManager()
{
    std::cout << __FUNCTION__  << std::endl;
}
