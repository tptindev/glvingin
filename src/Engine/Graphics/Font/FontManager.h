#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <memory>
#include <unordered_map>
class AFont;
class FontManager
{
public:
    FontManager(const FontManager &) = delete;
    FontManager(FontManager &&) = delete;
    FontManager &operator=(const FontManager &) = delete;
    FontManager &operator=(FontManager &&) = delete;
    static FontManager *Instance();
    static void ResetInstance();
    ~FontManager();

    AFont* Load(std::shared_ptr<AFont> font);
    AFont* GetFont(const char* fontName, int fontSize);
    void Clean();

private:
    static FontManager *s_instance;
    FontManager();

    std::unordered_map<const char*, std::shared_ptr<AFont>> m_fonts;
};

#endif // FONTMANAGER_H
