#include "AnimatedSprite2D.h"

AnimatedSprite2D::AnimatedSprite2D():
    m_sourceDir(""),
    m_frameWidth(0),
    m_frameHeight(0),
    m_frameCount(0),
    m_z_order(1),
    m_frameRate(0.0),
    m_running(false)
{

}

AnimatedSprite2D::AnimatedSprite2D(const char *sourceDir, int frameWidth, int frameHeight, int frameCount, int z_order, float frameRate, bool running) : m_sourceDir(sourceDir),
    m_frameWidth(frameWidth),
    m_frameHeight(frameHeight),
    m_frameCount(frameCount),
    m_z_order(z_order),
    m_frameRate(frameRate),
    m_running(running)
{}
