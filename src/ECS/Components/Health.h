#ifndef HEALTH_H
#define HEALTH_H

#include <AComponent.h>

class Health: public AComponent
{
public:
    Health();
    Health(float max);
    Health(float current, float max);

private:
    float m_current;
    float m_max;
};

#endif // HEALTH_H
