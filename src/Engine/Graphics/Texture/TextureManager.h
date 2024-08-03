#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <unordered_map>
#include <memory>
#include "ATexture.h"

class TextureManager
{
public:
    TextureManager(const TextureManager &) = delete;
    TextureManager(TextureManager &&) = delete;
    TextureManager &operator=(const TextureManager &) = delete;
    TextureManager &operator=(TextureManager &&) = delete;
    static TextureManager *Instance();
    static void ResetInstance();
    ~TextureManager();

    void Load(std::shared_ptr<ATexture> buffer, int id, const char* path);
    void Render();
    void RenderFrame();
    void Clean();

private:
    static TextureManager *s_instance;
    TextureManager();

    std::unordered_map<int, std::shared_ptr<ATexture>> m_textures;
};

#endif // TEXTUREMANAGER_H
