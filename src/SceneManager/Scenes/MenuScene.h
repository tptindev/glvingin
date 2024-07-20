#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "../AScene.h"

struct GLFWwindow;
class MenuScene : public AScene
{
public:
    explicit MenuScene(GLFWwindow *surface, SceneManager *manager);
    ~MenuScene();
    // AScene interface
public:
    virtual void EventHandle(GLFWwindow *window, int key, int scancode, int action, int mods) override;
    virtual void Update() override;
    virtual void Render() override;
};

#endif // MENUSCENE_H
