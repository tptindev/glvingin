#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <unordered_map>
#include <memory>
#include "AScene.h"

class SceneManager
{
public:
    static SceneManager *instance();
    void LoadScene(AScene* scene, bool active = false);
    void UpdateScenes();
    void RenderScenes();
    void RemoveScene(int id);
    void Transition(int id);

private:
    AScene *m_first_scene{nullptr};
    AScene *m_second_scene{nullptr};
    std::unordered_map<int, AScene*> m_scenes;
    static SceneManager *s_instance;
    SceneManager();
    ~SceneManager();
};

#endif // SCENEMANAGER_H
