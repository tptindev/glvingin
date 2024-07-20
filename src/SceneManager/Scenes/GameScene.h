#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../AScene.h"
struct GLFWwindow;
struct SceneManager;
class GameScene : public AScene
{
public:
    explicit GameScene(GLFWwindow *surface, SceneManager *manager);
    ~GameScene();
    // AScene interface
public:
    virtual void EventHandle(GLFWwindow *window, int key, int scancode, int action, int mods) override;
    virtual void Update() override;
    virtual void Render() override;
};

#endif // GAMESCENE_H
