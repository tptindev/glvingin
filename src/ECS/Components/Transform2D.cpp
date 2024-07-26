#include "Transform2D.h"

Transform2D::Transform2D()
{
    Vec2<float> vec;
    vec.Zero();

    this->m_position = vec;
    this->m_rotation = vec;
    this->m_scale = vec;
}

Transform2D::Transform2D(Vec2<float> position, Vec2<float> rotation, Vec2<float> scale)
{
    this->m_position = std::move(position);
    this->m_rotation = std::move(rotation);
    this->m_scale = std::move(scale);
}
