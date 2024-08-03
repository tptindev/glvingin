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
    void HandleEvent() override;
};

#endif // GAMESCENE_H
