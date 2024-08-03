#ifndef RENDERER3D_H
#define RENDERER3D_H

#include "IRenderer.h"
class GLWindowWrapper;
class Renderer3D : public IRenderer
{
public:
    Renderer3D(const Renderer3D &) = delete;
    Renderer3D(Renderer3D &&) = delete;
    Renderer3D &operator=(const Renderer3D &) = delete;
    Renderer3D &operator=(Renderer3D &&) = delete;
    static Renderer3D* Instance();
    static void ResetInstance();
    ~Renderer3D();

    // ARenderer interface
public:
    bool Initialize(IWindowWrapper* window) override;
    void SetDrawColor() override;
    void Clear() override;
    void Present() override;
    void Destroy() override;

private:
    static Renderer3D* s_instance;
    Renderer3D();
    GLWindowWrapper* m_winWrapper{nullptr};
};

#endif // RENDERER3D_H
