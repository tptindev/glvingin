#ifndef ANIMATEDSPRITE2D_H
#define ANIMATEDSPRITE2D_H

#include <vector>
#include <AComponent.h>
#include "Sprite2D.h"

class AnimatedSprite2D : public AComponent
{
public:
    AnimatedSprite2D();
    explicit AnimatedSprite2D(const char *sourceDir, int frameWidth, int frameHeight, int frameCount, int z_order, float frameRate, bool running = true);

private:
    std::vector<Sprite2D*> m_sprites;
    const char* m_sourceDir;
    int m_frameWidth;
    int m_frameHeight;
    int m_frameCount;
    int m_z_order;
    float m_frameRate;
    bool m_running;
};

#endif // ANIMATEDSPRITE2D_H
