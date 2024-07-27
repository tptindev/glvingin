#include "SceneManager.h"
#include <vector>
#include <thread>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdio.h>
SceneManager *SceneManager::s_instance = nullptr;
SceneManager *SceneManager::instance()
{
    if (SceneManager::s_instance == nullptr)
    {
        SceneManager::s_instance = new SceneManager();
    }
    return SceneManager::s_instance;
}

void SceneManager::LoadScene(AScene *scene, bool active)
{
    if (scene != nullptr)
    {
        scene->Initialize();
        this->m_scenes[scene->id()] = scene;
        if (active == true)
        {
            SetEventHandle(scene);
            this->NotifyWindowTitleChanged().Emit(NOTIFY_SCENE_CHANGED, scene->title());

            if (this->m_first_scene == nullptr)
            {
                this->m_first_scene = scene;
            }
        }
    }
}

void SceneManager::UpdateScenes()
{
    std::vector<std::thread> scene_threads;
    scene_threads.push_back(std::thread([](AScene *scene) {
        if (scene == nullptr) return;
        if (scene->enable())
        {
            scene->Update();
        }
    }, this->m_first_scene));

    scene_threads.push_back(std::thread([](AScene *scene) {
        if (scene == nullptr) return;
        if (scene->enable())
        {
            scene->Update();
        }
    }, this->m_second_scene));

    for (int i = 0; i < static_cast<int>(scene_threads.size()); i++)
    {
        scene_threads.at(i).join();
    }
}

void SceneManager::RenderScenes()
{
    /* Render here */
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    std::vector<std::thread> scene_threads;
    scene_threads.push_back(std::thread([](AScene *scene) {
        if (scene == nullptr) return;
        if (scene->visible())
        {
            scene->Render();
        }
    }, this->m_first_scene));

    scene_threads.push_back(std::thread([](AScene *scene) {
        if (scene == nullptr) return;
        if (scene->visible())
        {
            scene->Render();
        }
    }, this->m_second_scene));

    for (int i = 0; i < static_cast<int>(scene_threads.size()); i++)
    {
        scene_threads.at(i).join();
    }
}

void SceneManager::RemoveScene(int id)
{
    if (this->m_scenes[id] != nullptr)
    {
        this->m_scenes.erase(this->m_scenes.find(id));
        delete this->m_scenes[id];
        this->m_scenes[id] = nullptr;
    }
}

void SceneManager::Transition(int id)
{
    AScene *scene = this->m_scenes[id];
    if (scene == nullptr) return;
    SetEventHandle(scene);
    if (this->m_first_scene == nullptr)
    {
        this->m_first_scene = scene;
    }
    if (this->m_second_scene == nullptr)
    {
        this->m_first_scene->setEnable(false);
        this->m_second_scene = scene;
    }
    this->NotifyWindowTitleChanged().Emit(NOTIFY_SCENE_CHANGED, scene->title());
}

SceneManager::SceneManager()
{

}

void SceneManager::SetEventHandle(AScene *scene)
{
    static AScene *obj = nullptr;
    if (scene != nullptr)
    {
        obj = scene;
        std::cout << __FUNCTION__ << ":" << obj->title() << std::endl;
        glfwSetKeyCallback(scene->surface(), [](GLFWwindow* window, int key, int scancode, int action, int mods){
            obj->EventHandle(window, key, scancode, action, mods);
        });
    }
}

Signal<void, const char *> &SceneManager::NotifyWindowTitleChanged()
{
    return m_NotifyWindowTitleChanged;
}

SceneManager::~SceneManager()
{
    std::cout << __FUNCTION__ << std::endl;
    std::unordered_map<int, AScene*>::iterator it = this->m_scenes.begin();
    while (it != this->m_scenes.end())
    {
        this->m_scenes.erase(it);
        delete it->second;
        it->second = nullptr;
        ++it;
    }
}
