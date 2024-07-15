#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <unordered_map>
#include "AScene.h"

class SceneManager
{
public:
    static SceneManager *instance();
    void LoadScene(AScene* scene);
    void RemoveScene(int id);

private:
    AScene *m_first_scene;
    AScene *m_second_scene;
    std::unordered_map<int, AScene*> m_scenes;
    static SceneManager *s_instance;
    SceneManager();
    ~SceneManager();
};

#endif // SCENEMANAGER_H
