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
    void HandleEvents() override;
    void Update(float deltaTime) override;
    void Render() override;
    void Cleanup() override;
};

#endif // MENUSCENE_H
