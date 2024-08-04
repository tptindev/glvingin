#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <unordered_map>
#include <memory>
#include <glm/glm.hpp>
#include "ITexture.h"

class AFont;
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

    ITexture* GetTextureByID(int id);
    void LoadIMG(std::shared_ptr<ITexture> buffer, int id, const char* path);
    void LoadTxt(std::shared_ptr<ITexture> buffer, int id, const char* text, AFont* font, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255, uint8_t a = 255);
    void Clean();

private:
    static TextureManager *s_instance;
    TextureManager();

    std::unordered_map<int, std::shared_ptr<ITexture>> m_textures;
};

#endif // TEXTUREMANAGER_H
