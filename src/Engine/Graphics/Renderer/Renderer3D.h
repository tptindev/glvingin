#ifndef RENDERER3D_H
#define RENDERER3D_H

#include "IRenderer.h"

class Renderer3D : public IRenderer
{
public:
    Renderer3D();

    // ARenderer interface
public:
    bool Initialize(IWindow* window) override;
    void SetDrawColor() override;
    void Clear() override;
    void Present() override;
    void Destroy() override;
};

#endif // RENDERER3D_H
