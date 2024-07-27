#include "Script.h"
#include <SceneManager.h>
#include "Scenes/MenuScene/MenuScene.h"
#include "Scenes/GameScene/GameScene.h"
Script *Script::s_instance = nullptr;
Script *Script::Instance()
{
    if (Script::s_instance == nullptr)
    {
        Script::s_instance = new Script();
    }
    return Script::s_instance;
}

void Script::ResetInstance()
{
    if (Script::s_instance != nullptr)
    {
        delete Script::s_instance;
        Script::s_instance = nullptr;
    }
    return;
}

Script::~Script()
{
}

Script::Script()
{
}

void Script::Initialize()
{
    SceneManager::Instance(nullptr)->LoadScene(new MenuScene(), true);
    SceneManager::Instance(nullptr)->LoadScene(new GameScene());
}
