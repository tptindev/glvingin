#include "Engine3D.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
#include <SceneManager.h>

Engine3D *Engine3D::s_instance = nullptr;
Engine3D *Engine3D::Instance()
{
    if (Engine3D::s_instance == nullptr)
    {
        Engine3D::s_instance = new Engine3D();
    }
    return Engine3D::s_instance;
}

Engine3D::Engine3D()
{
    std::cout << __FUNCTION__ << std::endl;
}

Engine3D::~Engine3D()
{
    std::cout << __FUNCTION__ << std::endl;
}

void Engine3D::Connections()
{
    this->m_sceneManager->NotifyWindowTitleChanged().Connect(
        SceneManager::NOTIFY_SCENE_CHANGED,
        std::bind(&Engine3D::OnWindowTitleChanged, this, std::placeholders::_1)
        );
}

void Engine3D::Update()
{

}

void Engine3D::Render()
{

}

void Engine3D::ResetInstance()
{
    if (Engine3D::s_instance != nullptr)
    {
        delete Engine3D::s_instance;
        Engine3D::s_instance = nullptr;
    }
    return;
}

bool Engine3D::Initialize(const char* title)
{
    this->m_title = title;
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

    this->m_sceneManager = SceneManager::Instance();
    if (this->m_sceneManager == nullptr)
    {
        return false;
    }

    this->Connections();

    return true;
}

void Engine3D::Loop()
{
    while (!glfwWindowShouldClose(this->m_window))
    {
        /* Poll for and process events */
        glfwPollEvents();

        /* Update Logics in scenes*/
        this->m_sceneManager->UpdateScenes();

        this->m_sceneManager->RenderScenes();

        /* Swap front and back buffers */
        glfwSwapBuffers(this->m_window);
    }
}

void Engine3D::Quit()
{
    SceneManager::ResetInstance();
    glfwDestroyWindow(this->m_window);
    glfwTerminate();
}

void Engine3D::GetDesktopResolution(int &width, int &height)
{
}

void Engine3D::OnWindowTitleChanged(const char *title)
{
    char buffer[255];
    sprintf(&buffer[0], this->m_title, title);
    glfwSetWindowTitle(this->m_window, buffer);
}
