#ifndef TRANSFORM2D_H
#define TRANSFORM2D_H

#include <AComponent.h>
#include <glm/glm.hpp>

class Transform2D : public AComponent
{
public:
    Transform2D();
    ~Transform2D();
    explicit Transform2D(glm::vec2 position, glm::vec2 rotation, glm::vec2 scale);

private:
    glm::vec2 m_position;
    glm::vec2 m_rotation;
    glm::vec2 m_scale;
};

#endif // TRANSFORM2D_H
