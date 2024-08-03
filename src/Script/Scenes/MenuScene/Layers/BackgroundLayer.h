#ifndef BACKGROUNDLAYER_H
#define BACKGROUNDLAYER_H

#include <ALayer.h>

class BackgroundLayer : public ALayer
{
public:
    BackgroundLayer();
    ~BackgroundLayer();

    // ALayer interface
public:
    void Initialize() override;
    void Update(float deltaTime) override;
    void Render(IRenderer *renderer) override;
    void Cleanup() override;
};

#endif // BACKGROUNDLAYER_H
