#ifndef SETTINGSCENE_H
#define SETTINGSCENE_H

#include <AScene.h>

class SettingScene : public AScene
{
public:
    SettingScene();
    ~SettingScene();

    // AScene interface
public:
    void Initialize() override;
    void EventHandle(GLFWwindow *window, int key, int scancode, int action, int mods) override;
    void Update() override;
    void Render() override;
};

#endif // SETTINGSCENE_H
