#ifndef RENDERER3D_H
#define RENDERER3D_H

#include "IRenderer.h"
class GLWindowWrapper;
class Renderer3D : public IRenderer
{
public:
    Renderer3D();

    // ARenderer interface
public:
    bool Initialize(IWindowWrapper* window) override;
    void SetDrawColor() override;
    void Clear() override;
    void Present() override;
    void Destroy() override;

private:
    GLWindowWrapper* m_winWrapper{nullptr};
};

#endif // RENDERER3D_H
