#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include "EngineEnums.h"
struct GLFWwindow;
class SceneManager;
class Engine
{
public:
    static Engine *instance();
    bool Initialize(const char* title, EngineEnums::EngineMode mode);
    void Loop();
    void Quit();

    const char *title() const;
    void setTitle(const char *newTitle);

private:
    const char* m_title;
    GLFWwindow* m_window;
    SceneManager* m_sceneManager;
    EngineEnums::EngineMode m_mode;
    EngineEnums::EngineState m_state;
    static Engine *s_instance;
    Engine();
    ~Engine();
    void OnWindowTitleChanged(const char*title);
};

#endif // ENGINE_H
