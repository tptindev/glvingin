#include "SceneManager.h"

SceneManager *SceneManager::s_instance = nullptr;
SceneManager *SceneManager::instance()
{
    if (SceneManager::s_instance == nullptr)
    {
        SceneManager::s_instance = new SceneManager();
    }
    return SceneManager::s_instance;
}

void SceneManager::LoadScene(AScene *scene)
{
    if (scene != nullptr)
    {
        this->m_scenes[scene->id()] = scene;
    }
}

void SceneManager::RemoveScene(int id)
{
    if (this->m_scenes[id] != nullptr)
    {
        this->m_scenes.erase(this->m_scenes.find(id), this->m_scenes.end());
    }
}

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}
