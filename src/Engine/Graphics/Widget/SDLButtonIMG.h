#ifndef SDLBUTTONIMG_H
#define SDLBUTTONIMG_H

#include <unordered_map>
#include <memory>
#include "SDLButton.h"
#include "SDLImage.h"

class SDLButtonIMG : public SDLButton
{
public:
    explicit SDLButtonIMG();
    explicit SDLButtonIMG(int x, int y, int w, int h);
    ~SDLButtonIMG();

    void setNormal(std::shared_ptr<SDLImage> image_ptr);
    void setPressed(std::shared_ptr<SDLImage> image_ptr);
    void setReleased(std::shared_ptr<SDLImage> image_ptr);

    // AWidget interface
public:
    void Initialize() override;
    void Completed() override;
    void HandleEvent() override;
    void Render() override;

private:
    std::unordered_map<int, SDLImage*> m_bgImgState;
};

#endif // SDLBUTTONIMG_H
