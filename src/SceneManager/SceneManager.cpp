#include "SceneManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <iostream>
#include <LayerManager.h>

SceneManager *SceneManager::s_instance = nullptr;
SceneManager *SceneManager::Instance()
{
    if (SceneManager::s_instance == nullptr)
    {
        SceneManager::s_instance = new SceneManager();
    }
    return SceneManager::s_instance;
}

void SceneManager::ResetInstance()
{
    if (SceneManager::s_instance != nullptr)
    {
        delete SceneManager::s_instance;
        SceneManager::s_instance = nullptr;
    }
    return;
}

void SceneManager::LoadScene(std::shared_ptr<AScene> scene, bool active)
{
    if (scene != nullptr)
    {
        scene->Initialize();
        this->m_scenes[scene->id()] = scene;
        if (active == true)
        {
            SetEventHandle(scene.get());
            this->NotifyWindowTitleChanged().Emit(NOTIFY_SCENE_CHANGED, scene->title());

            if (this->m_first_scene == nullptr)
            {
                this->m_first_scene = scene.get();
            }
        }
    }
}

void SceneManager::UpdateScenes(float deltaTime)
{
    std::vector<std::thread> scene_threads;
    scene_threads.push_back(std::thread([&](AScene *scene) {
        if (scene == nullptr) return;
        if (scene->enable() && scene->visible())
        {
            scene->Update(deltaTime);
        }
    }, this->m_first_scene));

    scene_threads.push_back(std::thread([&](AScene *scene) {
        if (scene == nullptr) return;
        if (scene->enable() && scene->visible())
        {
            scene->Update(deltaTime);
        }
    }, this->m_second_scene));

    for (int i = 0; i < static_cast<int>(scene_threads.size()); i++)
    {
        scene_threads.at(i).join();
    }
}

void SceneManager::RenderScenes(IRenderer* renderer)
{
    std::vector<std::thread> scene_threads;
    scene_threads.push_back(std::thread([&](AScene *scene) {
        if (scene == nullptr) return;
        if (scene->visible())
        {
            scene->Render(renderer);
        }
    }, this->m_first_scene));

    scene_threads.push_back(std::thread([&](AScene *scene) {
        if (scene == nullptr) return;
        if (scene->visible())
        {
            scene->Render(renderer);
        }
    }, this->m_second_scene));

    for (int i = 0; i < static_cast<int>(scene_threads.size()); i++)
    {
        scene_threads.at(i).join();
    }
}

void SceneManager::RemoveScene(int id)
{
    decltype(this->m_scenes)::iterator it = this->m_scenes.find(id);
    if (it != this->m_scenes.end())
    {
        if (this->m_scenes[id] != nullptr)
        {
            this->m_scenes.erase(this->m_scenes.find(id));
        }
    }
}

void SceneManager::Transition(int id)
{
    this->m_mutex.lock();
    decltype(this->m_scenes)::iterator it = this->m_scenes.find(id);
    if (it != this->m_scenes.end())
    {
        AScene *scene = this->m_scenes[id].get();
        if (scene == nullptr)
        {
            return;
        }
        if (this->m_first_scene == nullptr)
        {
            this->m_first_scene = scene;
        }
        else if (this->m_second_scene == nullptr)
        {
            this->m_first_scene->setEnable(false);
            this->m_second_scene = scene;
        }
        else
        {
            this->m_first_scene = scene;
            this->m_second_scene = nullptr;
        }
        SetEventHandle(scene);

        this->NotifyWindowTitleChanged().Emit(NOTIFY_SCENE_CHANGED, scene->title());
    }
    this->m_mutex.unlock();
}

void SceneManager::SetEventHandle(AScene *scene)
{
    if (scene != nullptr)
    {
        scene->setEnable(true);
        if (scene->enable())
        {
            scene->HandleEvent();
        }
    }
}

Signal<void, const char *> &SceneManager::NotifyWindowTitleChanged()
{
    return m_NotifyWindowTitleChanged;
}

SceneManager::SceneManager()
{
    std::cout << __FUNCTION__ << std::endl;
}

SceneManager::~SceneManager()
{
    LayerManager::ResetInstance();
    decltype(this->m_scenes)::iterator it = this->m_scenes.begin();
    while (it != this->m_scenes.end())
    {
        this->m_scenes.erase(it);
        ++it;
    }
    std::cout << __FUNCTION__ << std::endl;
}
