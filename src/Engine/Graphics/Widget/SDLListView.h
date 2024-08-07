#ifndef SDLLISTVIEW_H
#define SDLLISTVIEW_H

#include "AWidget.h"

class SDLListView : public AWidget
{
public:
    SDLListView();
    ~SDLListView();

    // AWidget interface
public:
    void Initialize() override;
    void Completed() override;
    void HandleEvent() override;
    void Render() override;
};

#endif // SDLLISTVIEW_H
