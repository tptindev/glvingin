#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <AScene.h>
struct GLFWwindow;
class GameScene : public AScene
{
public:
    GameScene();
    ~GameScene();
    // AScene interface
public:
    void Initialize() override;
    void EventHandle(GLFWwindow *window, int key, int scancode, int action, int mods) override;
    void Update() override;
    void Render() override;
};

#endif // GAMESCENE_H
