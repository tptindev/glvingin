#include "Transform2D.h"

Transform2D::Transform2D()
{
    glm::vec2 vec(0.0f, 0.0f);

    this->m_position = vec;
    this->m_rotation = vec;
    this->m_scale = vec;
}

Transform2D::Transform2D(glm::vec2 position, glm::vec2 rotation, glm::vec2 scale)
{
    this->m_position = std::move(position);
    this->m_rotation = std::move(rotation);
    this->m_scale = std::move(scale);
}
