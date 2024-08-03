#include "LayerManager.h"
#include <iostream>
#include <algorithm>
#include <ALayer.h>
#include <Manager.h>
LayerManager *LayerManager::s_instance = nullptr;
LayerManager::LayerManager()
{
    std::cout << __FUNCTION__ << std::endl;
}

LayerManager::~LayerManager()
{
    EntityManager::ResetInstance();
    std::cout << __FUNCTION__ << std::endl;
}

ALayer *LayerManager::Layer(int id, int sceneID)
{
    return nullptr;
}
void LayerManager::Layers(int sceneID, std::vector<std::shared_ptr<ALayer>> &layers)
{

    decltype(this->m_layers)::iterator found = this->m_layers.find(sceneID);
    if (found == this->m_layers.end())
    {
        return;
    }
    else
    {
        decltype(found->second)::iterator it = found->second.begin();
        while (it != found->second.end())
        {
            layers.emplace_back(it->second);
            it++;
        }
        std::sort(layers.begin(), layers.end(), [](std::shared_ptr<ALayer> a, std::shared_ptr<ALayer> b) -> bool{
            return a->id() < b->id();
        });
    }
    return;
}

void LayerManager::AddLayer(std::shared_ptr<ALayer> layer, int sceneID)
{
    if (layer != nullptr)
    {
        this->m_layers[sceneID][layer->id()] = layer;
    }
    return;
}

void LayerManager::RemoveLayer(std::shared_ptr<ALayer> layer, int sceneID)
{
    decltype(this->m_layers)::iterator found = this->m_layers.find(sceneID);
    if (found == this->m_layers.end())
    {
        return;
    }
    else
    {
        decltype(found->second)::iterator it = found->second.begin();
        while (it != found->second.end())
        {
            if (layer->id() == it->second->id())
            {
                this->m_layers[sceneID].erase(it);
            }
            it++;
        }
    }
}

void LayerManager::InitializedLayers(int sceneID)
{
    if (this->m_layerBuffer.empty())
    {
        this->Layers(sceneID, this->m_layerBuffer);
    }
    for(int i = 0; i < static_cast<int>(this->m_layerBuffer.size()); i++)
    {
        this->m_layerBuffer.at(i)->Initialize();
    }
}

void LayerManager::UpdateLayers(float deltaTime, int sceneID)
{
    if (this->m_layerBuffer.empty())
    {
        this->Layers(sceneID, this->m_layerBuffer);
    }
    for(int i = 0; i < static_cast<int>(this->m_layerBuffer.size()); i++)
    {
        this->m_layerBuffer.at(i)->Update(deltaTime);
    }
}

void LayerManager::RenderLayers(int sceneID)
{
    if (this->m_layerBuffer.empty())
    {
        this->Layers(sceneID, this->m_layerBuffer);
    }
    for(int i = 0; i < static_cast<int>(this->m_layerBuffer.size()); i++)
    {
        this->m_layerBuffer.at(i)->Render(nullptr);
    }
}

void LayerManager::CleanupLayers(int sceneID)
{
    std::vector<std::shared_ptr<ALayer>> layers;
    this->Layers(sceneID, layers);
    for(int i = 0; i < static_cast<int>(layers.size()); i++)
    {
        layers.at(i)->Cleanup();
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
