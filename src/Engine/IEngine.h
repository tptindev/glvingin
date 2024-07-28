#ifndef IENGINE_H
#define IENGINE_H

class IEngine
{
public:
    virtual bool Initialize(const char* title) = 0;
    virtual void Loop() = 0;
    virtual void Quit() = 0;
    virtual void Connections();
};

#endif // IENGINE_H
