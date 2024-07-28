#ifndef ENGINE2D_H
#define ENGINE2D_H

#include "IEngine.h"
struct SDL_Window;
struct SDL_Surface;
struct SDL_Renderer;
class SceneManager;
class Engine2D: public IEngine
{
    friend SceneManager;
public:
    Engine2D(const Engine2D &) = delete;
    Engine2D(Engine2D &&) = delete;
    Engine2D &operator=(const Engine2D &) = delete;
    Engine2D &operator=(Engine2D &&) = delete;
    static Engine2D *Instance();
    static void ResetInstance();
    ~Engine2D();

    // IEngine interface
public:
    bool Initialize(const char *title) override;
    void Loop() override;
    void Quit() override;
    void Connections() override;

    // IEngine interface
private:
    void Update() override;
    void Render() override;

private:
    static Engine2D *s_instance;
    Engine2D();
    void GetDesktopResolution(int& width, int& height);
    void OnWindowTitleChanged(const char*title);

private:
    const char* m_title;
    SDL_Window* m_window{nullptr};
    SDL_Renderer* m_renderer{nullptr};
    SceneManager* m_sceneManager{nullptr};
    bool m_running{false};


};

#endif // !ENGINE2D_H
