#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include <memory>
#include <vector>
#include <unordered_map>
class ALayer;
class LayerManager
{
public:
    LayerManager(const LayerManager &) = delete;
    LayerManager(LayerManager &&) = delete;
    LayerManager &operator=(const LayerManager &) = delete;
    LayerManager &operator=(LayerManager &&) = delete;
    static LayerManager *Instance();
    static void ResetInstance();
    ~LayerManager();

    ALayer* Layer(int id, int sceneID);
    void Layers(int sceneID, std::vector<std::shared_ptr<ALayer>>& layers);
    void AddLayer(std::shared_ptr<ALayer> layer, int sceneID);
    void RemoveLayer(std::shared_ptr<ALayer> layer, int sceneID);
    void UpdateLayers(float deltaTime, int sceneID);
    void RenderLayers(int sceneID);
    void CleanupLayers(int sceneID);
private:
    static LayerManager *s_instance;
    LayerManager();
    std::unordered_map<int, std::vector<std::shared_ptr<ALayer>>> m_layers;
};

#endif // LAYERMANAGER_H
