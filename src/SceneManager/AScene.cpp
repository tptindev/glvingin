#include "AScene.h"

int AScene::id() const
{
    return m_id;
}

const char *AScene::title() const
{
    return m_title;
}

void AScene::setId(int newId)
{
    m_id = newId;
}

GLFWwindow *AScene::window() const
{
    return m_window;
}

int AScene::width() const
{
    return m_width;
}

void AScene::setWidth(int newWidth)
{
    m_width = newWidth;
}

int AScene::height() const
{
    return m_height;
}

void AScene::setHeight(int newHeight)
{
    m_height = newHeight;
}

void AScene::setTitle(const char *newTitle)
{
    m_title = newTitle;
}

float AScene::opacity() const
{
    return m_opacity;
}

void AScene::setOpacity(float newOpacity)
{
    m_opacity = newOpacity;
}

bool AScene::visible() const
{
    return m_visible;
}

void AScene::setVisible(bool newVisible)
{
    m_visible = newVisible;
}

bool AScene::enable() const
{
    return m_enable;
}

void AScene::setEnable(bool newEnable)
{
    m_enable = newEnable;
}

AScene::AScene(GLFWwindow* window)
{
    this->m_window = window;
}

AScene::~AScene()
{

}
