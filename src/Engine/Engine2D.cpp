#include "Engine2D.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <functional>
#include <SceneManager.h>
#include <SDLWindow.h>
#include <Renderer2D.h>

Engine2D *Engine2D::s_instance = nullptr;
Engine2D *Engine2D::Instance()
{
    if (Engine2D::s_instance == nullptr)
    {
        Engine2D::s_instance = new Engine2D();
    }
    return Engine2D::s_instance;
}

Engine2D::Engine2D()
{
    std::cout << __FUNCTION__ << std::endl;
}

Engine2D::~Engine2D()
{
    std::cout << __FUNCTION__ << std::endl;
}

void Engine2D::Connections()
{
    this->m_sceneManager->NotifyWindowTitleChanged().Connect(
        SceneManager::NOTIFY_SCENE_CHANGED,
        std::bind(&Engine2D::OnWindowTitleChanged, this, std::placeholders::_1)
        );
}

void Engine2D::Update(float deltaTime)
{
    this->m_sceneManager->UpdateScenes(deltaTime);
}

void Engine2D::Render()
{
    this->m_renderer2d->SetDrawColor();
    this->m_renderer2d->Clear();
    this->m_sceneManager->RenderScenes(this->m_renderer2d);
    this->m_renderer2d->Present();
}

void Engine2D::ResetInstance()
{
    if (Engine2D::s_instance != nullptr)
    {
        delete Engine2D::s_instance;
        Engine2D::s_instance = nullptr;
    }
    return;
}

bool Engine2D::Initialize(const char* title)
{
    this->m_title = title;

    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cerr << "Failed to initialize SDL2: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
    {
        return false;
    }

    if (TTF_Init() < 0)
    {
        return false;
    }

    this->m_window = new SDLWindow();
    if (this->m_window == nullptr)
    {
        return false;
    }
    this->m_window->CreateWindow(640, 480, title);

    this->m_renderer2d = new Renderer2D();
    if (this->m_renderer2d == nullptr)
    {
        return false;
    }
    this->m_renderer2d->Initialize(this->m_window);

    this->m_sceneManager = SceneManager::Instance();
    if (this->m_sceneManager == nullptr)
    {
        return false;
    }

    this->Connections();

    this->m_running = true;
    return true;
}

void Engine2D::Loop()
{
    SDL_Event e;
    while (m_running == true)
    {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                m_running = false;
            }
        }
        this->Update(0.0f);
        this->Render();
    }
}

void Engine2D::Quit()
{
    SceneManager::ResetInstance();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    this->m_renderer2d->Destroy();
    this->m_window->DestroyWindow();
}

void Engine2D::GetDesktopResolution(int &width, int &height)
{
}

void Engine2D::OnWindowTitleChanged(const char *title)
{
//    char buffer[255];
//    sprintf(&buffer[0], this->m_title, title);
//    SDL_SetWindowTitle(this->m_window, buffer);
}
