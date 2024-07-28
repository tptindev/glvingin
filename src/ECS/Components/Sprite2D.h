#ifndef SPRITE2D_H
#define SPRITE2D_H

#include <AComponent.h>

class Sprite2D : public AComponent
{
public:
    Sprite2D();
    ~Sprite2D();
    explicit Sprite2D(const char* path, float offset = 0.5f, int z_order = 1, bool flip = false);

private:
    const char* m_path;
    float m_offset;
    int m_z_order;
    bool m_flip;
};

#endif // SPRITE2D_H
