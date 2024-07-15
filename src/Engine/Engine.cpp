#include "Engine.h"

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
    this->m_state = EngineEnums::ENGINE_RUNNING;
    return true;
}

void Engine::Loop()
{
    while (this->m_state != EngineEnums::ENGINE_STOPED)
    {
        if (this->m_state == EngineEnums::ENGINE_RUNNING)
        {

        }
        else if (this->m_state == EngineEnums::ENGINE_PAUSED)
        {

        }
    }
}

void Engine::Quit()
{

}

Engine::Engine()
{

}

Engine::~Engine()
{

}
