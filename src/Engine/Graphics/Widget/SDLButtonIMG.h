#ifndef SDLBUTTONIMG_H
#define SDLBUTTONIMG_H

#include "SDLButton.h"

class SDLButtonIMG : public SDLButton
{
public:
    explicit SDLButtonIMG(int textureID, const char *imgFilePath);
    explicit SDLButtonIMG(int textureID, const char *imgFilePath, int x, int y, int w, int h);
    ~SDLButtonIMG();

    // AWidget interface
public:
    void Initialize() override;
    void HandleEvent() override;
    void Render() override;

private:
    int m_textureID;
    const char* m_imgFilePath;
};

#endif // SDLBUTTONIMG_H
