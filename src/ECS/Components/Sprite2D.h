#ifndef SPRITE2D_H
#define SPRITE2D_H

#include <AComponent.h>

class Sprite2D : public AComponent
{
public:
    Sprite2D();
    Sprite2D(const char* path, float offset, int z_order = 1, bool flip = false);
};

#endif // SPRITE2D_H
