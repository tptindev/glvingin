#ifndef UILAYER_H
#define UILAYER_H

#include <memory>
#include <ALayer.h>

class SDLButton;
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

private:
    std::shared_ptr<SDLButton> m_btnStart;
    std::shared_ptr<SDLButton> m_btnAbout;
};

#endif // UILAYER_H
