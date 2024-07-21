#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <unordered_map>
#include <memory>
#include "AScene.h"
#include "../Utilities/IOC.h"

class SceneManager
{
public:
    SceneManager(const SceneManager &) = delete;
    SceneManager(SceneManager &&) = delete;
    SceneManager &operator=(const SceneManager &) = delete;
    SceneManager &operator=(SceneManager &&) = delete;
    static SceneManager *instance();
    ~SceneManager();
public:
    void LoadScene(AScene* scene, bool active = false);
    void UpdateScenes();
    void RenderScenes();
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
    AScene *m_first_scene{nullptr};
    AScene *m_second_scene{nullptr};
    std::unordered_map<int, AScene*> m_scenes;
    Signal<void, const char*> m_NotifyWindowTitleChanged;
};

#endif // SCENEMANAGER_H
