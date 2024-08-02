#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "ARenderer.h"

class Renderer2D : public ARenderer
{
public:
    Renderer2D();

    // ARenderer interface
public:
    void Initialize() override;
    void SetDrawColor() override;
    void Clear() override;
    void Present() override;
};

#endif // RENDERER2D_H
