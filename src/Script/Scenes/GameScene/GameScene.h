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
    void HandleEvents() override;
    void Update(float deltaTime) override;
    void Render() override;
    void Cleanup() override;
};

#endif // GAMESCENE_H
