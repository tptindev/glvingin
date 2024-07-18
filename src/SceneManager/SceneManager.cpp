#include "SceneManager.h"
#include <vector>
#include <thread>
#include <GLFW/glfw3.h>
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
        scene->setId(m_scenes.size());
        this->m_scenes[scene->id()] = scene;

        if (active == true)
        {

            if (this->m_first_scene == nullptr)
            {
                this->m_first_scene = scene;
                this->m_first_scene->EventHandle();

                const char* title = glfwGetWindowTitle(this->m_first_scene->window());
                char newTitle[255];
                sprintf(newTitle, "%s[%s]", title, this->m_first_scene->title());
                glfwSetWindowTitle(this->m_first_scene->window(), newTitle);
            }
        }
    }
}

void SceneManager::UpdateScenes()
{
    std::vector<std::thread> scene_threads;
    scene_threads.push_back(std::thread([](AScene *scene) {
        if (scene == nullptr) return;
        if (scene->enable() && scene->visible())
        {
            scene->Update();
        }
    }, this->m_first_scene));

    scene_threads.push_back(std::thread([](AScene *scene) {
        if (scene == nullptr) return;
        if (scene->enable() && scene->visible())
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
        scene->Render();
    }, this->m_first_scene));

    scene_threads.push_back(std::thread([](AScene *scene) {
        if (scene == nullptr) return;
        scene->Render();
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
        this->m_scenes.erase(this->m_scenes.find(id), this->m_scenes.end());
        delete this->m_scenes[id];
        this->m_scenes[id] = nullptr;
    }
}

void SceneManager::Transition(int id)
{
    AScene *scene = this->m_scenes[id];
    if (scene == nullptr) return;
    if (this->m_first_scene == nullptr)
    {
        this->m_first_scene = scene;
    }
    else
    {
        this->m_second_scene = scene;
    }
    scene->EventHandle();
    const char* title = glfwGetWindowTitle(scene->window());
    char newTitle[255];
    sprintf(newTitle, "%s[%s]", title, scene->title());
    glfwSetWindowTitle(scene->window(), newTitle);
}

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}
