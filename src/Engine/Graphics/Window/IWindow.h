#ifndef IWINDOW_H
#define IWINDOW_H

class IWindow
{
public:
    virtual bool CreateWindow(int width, int height, const char* title) = 0;
    virtual void DestroyWindow() = 0;
};

#endif // IWINDOW_H
