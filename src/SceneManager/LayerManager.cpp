#include "LayerManager.h"
#include <ALayer.h>
#include <iostream>
LayerManager *LayerManager::s_instance = nullptr;
LayerManager::LayerManager()
{
    std::cout << __FUNCTION__ << std::endl;
}

LayerManager::~LayerManager()
{
    std::cout << __FUNCTION__ << std::endl;
}
void LayerManager::Layers(int sceneID, std::vector<std::shared_ptr<ALayer>>& layers)
{
    std::unordered_map<int, std::vector<std::shared_ptr<ALayer>>>::iterator it = this->m_layers.find(sceneID);
    if (it != this->m_layers.end())
    {
        layers = it->second;
    }
}

void LayerManager::AddLayer(std::shared_ptr<ALayer> layer, int sceneID)
{
    this->m_layers[sceneID].push_back(layer);
}

void LayerManager::RemoveLayer(std::shared_ptr<ALayer> layer, int sceneID)
{
    std::unordered_map<int, std::vector<std::shared_ptr<ALayer>>>::iterator it = this->m_layers.find(sceneID);
    if (it == this->m_layers.end())
    {
        return;
    }
    for (std::vector<std::shared_ptr<ALayer>>::iterator it = this->m_layers.at(sceneID).begin();
         it != this->m_layers.at(sceneID).end();
         it++)
    {
        if (layer->id() == (*it)->id())
        {
            this->m_layers[sceneID].erase(it);
        }
    }
}

void LayerManager::UpdateLayers(float deltaTime, int sceneID)
{
    std::vector<std::shared_ptr<ALayer>> layers;
    this->Layers(sceneID, layers);
    for(int i = 0; i < static_cast<int>(layers.size()); i++)
    {
        layers.at(i)->update(deltaTime);
    }
}

void LayerManager::RenderLayers(int sceneID)
{
    std::vector<std::shared_ptr<ALayer>> layers;
    this->Layers(sceneID, layers);
    for(int i = 0; i < static_cast<int>(layers.size()); i++)
    {
        layers.at(i)->render(nullptr);
    }
}

void LayerManager::CleanupLayers(int sceneID)
{
    std::vector<std::shared_ptr<ALayer>> layers;
    this->Layers(sceneID, layers);
    for(int i = 0; i < static_cast<int>(layers.size()); i++)
    {
        layers.at(i)->cleanup();
    }
}

LayerManager *LayerManager::Instance()
{
    if (LayerManager::s_instance == nullptr)
    {
        LayerManager::s_instance = new LayerManager();
    }
    return LayerManager::s_instance;
}

void LayerManager::ResetInstance()
{
    if (LayerManager::s_instance != nullptr)
    {
        delete LayerManager::s_instance;
        LayerManager::s_instance = nullptr;
    }
    return;
}
#include "LayerManager.h"
