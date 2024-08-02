#include "AScene.h"
#include <iostream>
#include "LayerManager.h"

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

void AScene::Update(float deltaTime)
{
    LayerManager::Instance()->UpdateLayers(deltaTime, this->m_id);
}

void AScene::Render(IRenderer* renderer)
{
    LayerManager::Instance()->RenderLayers(this->m_id);
}

void AScene::Cleanup()
{
    LayerManager::Instance()->CleanupLayers(this->m_id);
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
    if (m_opacity == 0.0f) return false;
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
