#ifndef SDLBUTTONIMG_H
#define SDLBUTTONIMG_H

#include <unordered_map>
#include "SDLButton.h"

class SDLButtonIMG : public SDLButton
{
public:
    explicit SDLButtonIMG();
    explicit SDLButtonIMG(int x, int y, int w, int h);
    ~SDLButtonIMG();

    // AWidget interface
public:
    void Initialize() override;
    void Completed() override;
    void HandleEvent() override;
    void Render() override;

private:
    std::unordered_map<int, const char*> m_sources;
    const char* m_imgFilePath;
};

#endif // SDLBUTTONIMG_H
