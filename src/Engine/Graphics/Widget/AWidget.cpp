#include "AWidget.h"
int AWidget::x() const
{
    return m_x;
}

void AWidget::setX(int newX)
{
    m_x = newX;
}

int AWidget::y() const
{
    return m_y;
}

void AWidget::setY(int newY)
{
    m_y = newY;
}

int AWidget::width() const
{
    return m_width;
}

void AWidget::setWidth(int newWidth)
{
    m_width = newWidth;
}

int AWidget::height() const
{
    return m_height;
}

void AWidget::setHeight(int newHeight)
{
    m_height = newHeight;
}

bool AWidget::enable() const
{
    return m_enable;
}

void AWidget::setEnable(bool newEnable)
{
    m_enable = newEnable;
}

bool AWidget::visible() const
{
    return m_visible;
}

void AWidget::setVisible(bool newVisible)
{
    m_visible = newVisible;
}
