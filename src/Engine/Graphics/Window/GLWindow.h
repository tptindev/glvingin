#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "IWindow.h"

class GLWindow : public IWindow
{
public:
    GLWindow();

    // IWindow interface
public:
    bool CreateWindow(int width, int height, const char *title) override;
    void DestroyWindow() override;
};

#endif // GLWINDOW_H
