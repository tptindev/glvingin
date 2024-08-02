#ifndef IWINDOWWRAPPER_H
#define IWINDOWWRAPPER_H

class IWindowWrapper
{
public:
    virtual bool CreateWindow(int width, int height, const char* title) = 0;
    virtual void DestroyWindow() = 0;
};

#endif // IWINDOWWRAPPER_H
