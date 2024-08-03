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
    void HandleEvent() override;
};

#endif // MENUSCENE_H
