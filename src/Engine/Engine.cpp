#include "Engine.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "../SceneManager/Scenes/MenuScene.h"
#include "../SceneManager/Scenes/GameScene.h"
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

bool Engine::Initialize(const char* title, EngineEnums::EngineMode mode)
{
    this->m_title = title;
    this->m_mode = mode;
    glfwSetErrorCallback([](int error, const char* description)
                         {
                             fprintf(stderr, "Error: %s\n", description);
                         });

    if (!glfwInit())
    {
        return false;
    }

    this->m_window = glfwCreateWindow(640, 480, this->m_title, NULL, NULL);
    if (this->m_window == nullptr)
    {
        glfwTerminate();
        return false;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(this->m_window);

    if (glewInit() != GLEW_OK)
    {
        return false;
    }

    if (this->m_mode == EngineEnums::MODE_2D)
    {
        // Initialize SDL2
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
            std::cerr << "Failed to initialize SDL2: " << SDL_GetError() << std::endl;
            return false;
        }
    }

    this->m_sceneManager = SceneManager::instance();
    if (this->m_sceneManager == nullptr)
    {
        return false;
    }

    this->m_sceneManager->NotifyWindowTitleChanged().Connect(
        SceneManager::NOTIFY_SCENE_CHANGED,
        std::bind(&Engine::OnWindowTitleChanged, this, std::placeholders::_1)
        );

    this->m_sceneManager->LoadScene(new MenuScene(this->m_window, this->m_sceneManager), true);
    this->m_sceneManager->LoadScene(new GameScene(this->m_window, this->m_sceneManager));

    return true;
}

void Engine::Loop()
{
    while (!glfwWindowShouldClose(this->m_window))
    {
        this->m_state = EngineEnums::ENGINE_RUNNING;
        /* Poll for and process events */
        glfwPollEvents();

        /* Update Logics in scenes*/
        this->m_sceneManager->UpdateScenes();

        this->m_sceneManager->RenderScenes();

        /* Swap front and back buffers */
        glfwSwapBuffers(this->m_window);
    }
}

void Engine::Quit()
{
    delete this->m_sceneManager;
    this->m_sceneManager = nullptr;
    SDL_Quit();
    glfwDestroyWindow(this->m_window);
    glfwTerminate();
}

const char *Engine::title() const
{
    return m_title;
}

Engine::Engine()
{

}

Engine::~Engine()
{
}

void Engine::OnWindowTitleChanged(const char *title)
{
    char buffer[255];
    sprintf(&buffer[0], this->title(), title);
    glfwSetWindowTitle(this->m_window, buffer);
}
