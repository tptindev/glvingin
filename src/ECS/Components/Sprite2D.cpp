#include "Sprite2D.h"
#include <iostream>

Sprite2D::Sprite2D(): m_path(""), m_offset(0.0f), m_z_order(1), m_flip(false)
{
    this->setName(__FUNCTION__);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}

Sprite2D::Sprite2D(const char *path, float offset, int z_order, bool flip):
    m_path(path), m_offset(offset), m_z_order(z_order), m_flip(flip)
{
    this->setName(__FUNCTION__);
    std::cout << __FUNCTION__ << ":" << this->name() << std::endl;
}
