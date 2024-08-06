#include "Script.h"
#include <memory>
#include <iostream>
#include <SDLFont.h>
#include <FontIDs.h>
#include <FontManager.h>
#include <SceneManager.h>
#include <TextureManager.h>
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
    FontManager::Instance()->Load(
        std::make_shared<SDLFont>(
            FONT_RAINYHEARTS_16,
            "./res/Fonts/rainyhearts.ttf",
            16)
        );
    FontManager::Instance()->Load(
        std::make_shared<SDLFont>(
            FONT_RAINYHEARTS_22,
            "./res/Fonts/rainyhearts.ttf",
            22)
        );
    FontManager::Instance()->Load(
        std::make_shared<SDLFont>(
            FONT_RAINYHEARTS_32,
            "./res/Fonts/rainyhearts.ttf",
            32)
        );
    FontManager::Instance()->Load(
        std::make_shared<SDLFont>(
            FONT_RAINYHEARTS_64,
            "./res/Fonts/rainyhearts.ttf",
            64)
        );
    FontManager::Instance()->Load(
        std::make_shared<SDLFont>(
            FONT_RAINYHEARTS_72,
            "./res/Fonts/rainyhearts.ttf",
            72)
        );
    FontManager::Instance()->Load(
        std::make_shared<SDLFont>(
            FONT_RAINYHEARTS_80,
            "./res/Fonts/rainyhearts.ttf",
            80)
        );
    FontManager::Instance()->Load(
        std::make_shared<SDLFont>(
            FONT_CRUX_21,
            "./res/Fonts/crux.otf",
            21)
        );

    SceneManager::Instance()->LoadScene(std::make_shared<MenuScene>(), true);
    SceneManager::Instance()->LoadScene(std::make_shared<SettingScene>());
    SceneManager::Instance()->LoadScene(std::make_shared<GameScene>());
    std::cout << TextureManager::Instance()->Total() << std::endl;
}
