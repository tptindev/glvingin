#include "Engine.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../SceneManager/MenuScene.h"
#include "../SceneManager/GameScene.h"
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
    glfwSetErrorCallback([](int error, const char* description)
                         {
                             fprintf(stderr, "Error: %s\n", description);
                         });

    if (!glfwInit())
    {
        return false;
    }

    //    if (glewInit() != GLEW_OK)
    //    {
    //        return false;
    //    }

    this->m_window = glfwCreateWindow(640, 480, "ViNgin", NULL, NULL);
    if (this->m_window == nullptr)
    {
        glfwTerminate();
        return false;
    }

    glfwSetKeyCallback(this->m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    });

    /* Make the window's context current */
    glfwMakeContextCurrent(this->m_window);

    this->m_sceneManager = SceneManager::instance();
    if (this->m_sceneManager == nullptr)
    {
        return false;
    }

    this->m_sceneManager->LoadScene(new MenuScene(this->m_window), true);
    this->m_sceneManager->LoadScene(new GameScene(this->m_window));

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

        /* Swap front and back buffers */
        glfwSwapBuffers(this->m_window);

        /* Poll for and process events */
        glfwPollEvents();
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
    glfwDestroyWindow(this->m_window);
}
