#include "ATexture.h"

float ATexture::angle() const
{
    return m_angle;
}

void ATexture::setAngle(float newAngle)
{
    m_angle = newAngle;
}

bool ATexture::flip() const
{
    return m_flip;
}

void ATexture::setFlip(bool newFlip)
{
    m_flip = newFlip;
}
