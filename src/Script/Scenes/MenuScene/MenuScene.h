#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <AScene.h>

struct GLFWwindow;
class MenuScene : public AScene
{
public:
    MenuScene();
    ~MenuScene();
    // AScene interface
public:
    void Initialize() override;
    void EventHandle(GLFWwindow *window, int key, int scancode, int action, int mods) override;
    void Update() override;
    void Render() override;
};

#endif // MENUSCENE_H
