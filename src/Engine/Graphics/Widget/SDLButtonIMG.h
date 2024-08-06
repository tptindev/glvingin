#ifndef SDLBUTTONIMG_H
#define SDLBUTTONIMG_H

#include <unordered_map>
#include <memory>
#include <SDL2/SDL_pixels.h>
#include "SDLButton.h"
#include "SDLImage.h"

class SDLButtonIMG : public SDLButton
{
public:
    explicit SDLButtonIMG();
    explicit SDLButtonIMG(int x, int y, int w = 0, int h = 0);
    ~SDLButtonIMG();

    void SetNormal(std::shared_ptr<SDLImage> image_ptr, SDL_Color textColor = { 255, 255, 255, 255});
    void SetPressed(std::shared_ptr<SDLImage> image_ptr, SDL_Color textColor = { 255, 255, 255, 255});
    void SetReleased(std::shared_ptr<SDLImage> image_ptr, SDL_Color textColor = { 255, 255, 255, 255});

    // AWidget interface
public:
    void Initialize() override;
    void Completed() override;
    void HandleEvent() override;
    void Render() override;

    // AEventListener interface
public:
    void OnClicked() override;
    void OnPressed() override;
    void OnLongPressed() override;
    void OnReleased() override;

private:
    std::unordered_map<int, std::shared_ptr<SDLImage>> m_bgImgState;
};

#endif // SDLBUTTONIMG_H
