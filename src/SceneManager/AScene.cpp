#include "AScene.h"

int AScene::id() const
{
    return m_id;
}

const char *AScene::name() const
{
    return m_name;
}

void AScene::EventHandle()
{

}

void AScene::Update()
{

}

void AScene::Render()
{

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

AScene::AScene(int width, int height, const char *title)
    : m_width{width}, m_height{height}, m_name{title}
{
    this->m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (this->m_window == nullptr)
    {
        glfwTerminate();
    }
    else
    {
        /* Make the window's context current */
        glfwMakeContextCurrent(this->m_window);
    }
}

AScene::~AScene()
{

}
