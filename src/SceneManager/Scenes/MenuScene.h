#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "../AScene.h"

struct GLFWwindow;
class MenuScene : public AScene
{
public:
    MenuScene(GLFWwindow *surface, SceneManager *manager);
    ~MenuScene();
    // AScene interface
public:
    virtual void EventHandle() override;
    virtual void Update() override;
    virtual void Render() override;
};

#endif // MENUSCENE_H
