#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <unordered_map>
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

    void Load(int id, const char* path);
    void Render();
    void RenderFrame();
    void Clean();

private:
    static TextureManager *s_instance;
    TextureManager();

    std::unordered_map<int, ATexture*> m_textures;
};

#endif // TEXTUREMANAGER_H
