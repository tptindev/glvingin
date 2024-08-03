#ifndef UILAYER_H
#define UILAYER_H

#include <ALayer.h>

class UILayer : public ALayer
{
public:
    UILayer();
    ~UILayer();

    // ALayer interface
public:
    void Initialize() override;
    void Update(float deltaTime) override;
    void Render(IRenderer *renderer) override;
    void Cleanup() override;
};

#endif // UILAYER_H
