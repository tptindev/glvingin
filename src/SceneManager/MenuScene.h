#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "AScene.h"

class MenuScene : public AScene
{
public:
    MenuScene();

    // AScene interface
public:
    virtual void EventHandle() override;
    virtual void Update() override;
    virtual void Render() override;
};

#endif // MENUSCENE_H
