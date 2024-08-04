#include "Script.h"
#include <memory>
#include <SDLFont.h>
#include <FontManager.h>
#include <SceneManager.h>
#include "Scenes/MenuScene/MenuScene.h"
#include "Scenes/SettingScene/SettingScene.h"
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
    FontManager::Instance()->Load(std::make_shared<SDLFont>("RainyHearts", "./res/Fonts/rainyhearts/rainyhearts.ttf", 16));
    SceneManager::Instance()->LoadScene(std::make_shared<MenuScene>(), true);
    SceneManager::Instance()->LoadScene(std::make_shared<SettingScene>());
    SceneManager::Instance()->LoadScene(std::make_shared<GameScene>());
}
