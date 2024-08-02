#ifndef GLWINDOWWRAPPER_H
#define GLWINDOWWRAPPER_H

#include "IWindowWrapper.h"
struct GLFWwindow;
class GLWindowWrapper : public IWindowWrapper
{
public:
    GLWindowWrapper();
    ~GLWindowWrapper();
    GLFWwindow *window() const;

    // IWindow interface
public:
    bool CreateWindow(int width, int height, const char *title) override;
    void DestroyWindow() override;

private:
    GLFWwindow* m_window;
};

#endif // GLWINDOWWRAPPER_H
