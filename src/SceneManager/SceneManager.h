#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <unordered_map>
#include <memory>
#include <mutex>
#include <IOC.h>
#include "AScene.h"

struct SDL_Window;
struct GLFWwindow;
class IRenderer;
class SceneManager
{
public:
    SceneManager(const SceneManager &) = delete;
    SceneManager(SceneManager &&) = delete;
    SceneManager &operator=(const SceneManager &) = delete;
    SceneManager &operator=(SceneManager &&) = delete;
    static SceneManager *Instance();

    static void ResetInstance();
    ~SceneManager();
public:
    void LoadScene(std::shared_ptr<AScene> scene, bool active = false);
    void UpdateScenes(float deltaTime);
    void RenderScenes(IRenderer* renderer);
    void RemoveScene(int id);
    void Transition(int id);
    enum SignalID
    {
        NOTIFY_SCENE_CHANGED
    };

    Signal<void, const char *> &NotifyWindowTitleChanged();

private:
    static SceneManager *s_instance;
    SceneManager();

    void SetEventHandle(AScene* scene);

private:
    std::mutex m_mutex;
    AScene *m_first_scene{nullptr};
    AScene *m_second_scene{nullptr};
    std::unordered_map<int, std::shared_ptr<AScene>> m_scenes;
    Signal<void, const char*> m_NotifyWindowTitleChanged;
};

#endif // SCENEMANAGER_H
