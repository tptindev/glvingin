#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "AScene.h"
struct GLFWwindow;
class GameScene : public AScene
{
public:
    GameScene(GLFWwindow* window);

    // AScene interface
public:
    virtual void EventHandle() override;
    virtual void Update() override;
    virtual void Render() override;
};

#endif // GAMESCENE_H
