#include "Engine.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../SceneManager/MenuScene.h"
#include "../SceneManager/SceneManager.h"


Engine *Engine::s_instance = nullptr;
Engine *Engine::instance()
{
    if (Engine::s_instance == nullptr)
    {
        Engine::s_instance = new Engine();
    }
    return Engine::s_instance;
}

bool Engine::Initialize()
{
    if (!glfwInit())
    {
        return false;
    }

//    if (glewInit() != GLEW_OK)
//    {
//        return false;
//    }

    this->m_sceneManager = SceneManager::instance();
    if (this->m_sceneManager == nullptr)
    {
        return false;
    }

    this->m_sceneManager->LoadScene(new MenuScene());

    this->m_state = EngineEnums::ENGINE_RUNNING;
    return true;
}

void Engine::Loop()
{
    while (this->m_state != EngineEnums::ENGINE_STOPED)
    {
        if (this->m_state == EngineEnums::ENGINE_RUNNING)
        {
            this->m_sceneManager->UpdateScenes();
        }
        else if (this->m_state == EngineEnums::ENGINE_PAUSED)
        {
            // Do nothing
        }
        this->m_sceneManager->RenderScenes();
    }
}

void Engine::Quit()
{
    glfwTerminate();
}

Engine::Engine()
{

}

Engine::~Engine()
{
}
