#ifndef ENGINE3D_H
#define ENGINE3D_H

#include "IEngine.h"
struct GLWindowWrapper;
class Renderer3D;
class SceneManager;
class Engine3D: public IEngine
{
    friend SceneManager;
public:
    Engine3D(const Engine3D &) = delete;
    Engine3D(Engine3D &&) = delete;
    Engine3D &operator=(const Engine3D &) = delete;
    Engine3D &operator=(Engine3D &&) = delete;
    static Engine3D *Instance();
    static void ResetInstance();
    ~Engine3D();

    // IEngine interface
public:
    bool Initialize(const char* title) override;
    void Loop() override;
    void Quit() override;
    void Connections() override;

    // IEngine interface
private:
    void Update(float deltaTime) override;
    void Render() override;

private:
    static Engine3D *s_instance;
    Engine3D();
    void GetDesktopResolution(int& width, int& height);
    void OnWindowTitleChanged(const char*title);

private:
    const char* m_title;
    GLWindowWrapper* m_winWrapper{nullptr};
    Renderer3D* m_renderer3d{nullptr};
    SceneManager* m_sceneManager{nullptr};
};

#endif // !ENGINE3D_H
