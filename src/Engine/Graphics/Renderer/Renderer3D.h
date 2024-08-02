#ifndef RENDERER3D_H
#define RENDERER3D_H

#include "ARenderer.h"

class Renderer3D : public ARenderer
{
public:
    Renderer3D();

    // ARenderer interface
public:
    void Initialize() override;
    void SetDrawColor() override;
    void Clear() override;
    void Present() override;
};

#endif // RENDERER3D_H
