#ifndef IENGINE_H
#define IENGINE_H

class IEngine
{
public:
    virtual bool Initialize(const char* title) = 0;
    virtual void Loop() = 0;
    virtual void Quit() = 0;
    virtual void Connections() = 0;

private:
    virtual void Update() = 0;
    virtual void Render() = 0;
};

#endif // !IENGINE_H
