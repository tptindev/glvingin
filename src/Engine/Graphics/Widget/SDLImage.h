#ifndef SDLIMAGE_H
#define SDLIMAGE_H

#include <bitset>
#include "AWidget.h"

class SDLImage : public AWidget
{
public:
    explicit SDLImage(int textureID, const char *source);
    explicit SDLImage(int textureID, const char *source, float scale);
    explicit SDLImage(int textureID, const char *source, int x, int y);
    explicit SDLImage(int textureID, const char *source, int x, int y, int w, int h);
    ~SDLImage();

    // AWidget interface
public:
    void Initialize() override;
    void Completed() override;
    void HandleEvent() override;
    void Render() override;

    float scale() const;
    void setScale(float newScale);

    int textureID() const;
    void setTextureID(int newTextureID);

private:
    int m_textureID;
    const char* m_source;
    bool m_clip{false};
    float m_scale{1.0f};
};

#endif // SDLIMAGE_H
