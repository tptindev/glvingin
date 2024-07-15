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

AScene::AScene()
{

}

AScene::~AScene()
{

}
