#ifndef TRANSFORM2D_H
#define TRANSFORM2D_H

#include "../Component.h"
#include "../../Utilities/Math/Vec2.h"

class Transform2D : public Component
{
public:
    Transform2D();
    Transform2D(Vec2<float> position, Vec2<float> rotation, Vec2<float> scale);

private:
    Vec2<float> m_position;
    Vec2<float> m_rotation;
    Vec2<float> m_scale;
};

#endif // TRANSFORM2D_H
