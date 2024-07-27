#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include "EngineEnums.h"
struct GLFWwindow;
class SceneManager;
class Engine
{
public:
    Engine(const Engine &) = delete;
    Engine(Engine &&) = delete;
    Engine &operator=(const Engine &) = delete;
    Engine &operator=(Engine &&) = delete;
    static Engine *Instance();
    static void ResetInstance();
    ~Engine();

public:
    bool Initialize(const char* title, EngineEnums::EngineMode mode);
    void Loop();
    void Quit();
    const char *title() const;

private:
    static Engine *s_instance;
    Engine();
    void GetDesktopResolution(int& width, int& height);
    void OnWindowTitleChanged(const char*title);


private:
    const char* m_title;
    GLFWwindow* m_window;
    SceneManager* m_sceneManager;
    EngineEnums::EngineMode m_mode;
    EngineEnums::EngineState m_state;
};

#endif // ENGINE_H
