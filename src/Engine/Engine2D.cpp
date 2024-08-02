#include "Engine2D.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <functional>
#include <SceneManager.h>

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
    SDL_SetRenderDrawColor(this->m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(this->m_renderer);
    this->m_sceneManager->RenderScenes();
    SDL_RenderPresent(this->m_renderer);
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

    this->m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    if (this->m_window == nullptr)
    {
        return false;
    }

    this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED);
    if (this->m_renderer == nullptr)
    {
        return false;
    }

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
    SDL_DestroyWindow(this->m_window);
    SDL_DestroyRenderer(this->m_renderer);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Engine2D::GetDesktopResolution(int &width, int &height)
{
}

void Engine2D::OnWindowTitleChanged(const char *title)
{
    char buffer[255];
    sprintf(&buffer[0], this->m_title, title);
    SDL_SetWindowTitle(this->m_window, buffer);
}
