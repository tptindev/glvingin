#ifndef MENUBACKGROUND_H
#define MENUBACKGROUND_H

#include <AEntity.h>

class MenuBackground : public AEntity
{
public:
    MenuBackground();
    ~MenuBackground();

    // AEntity interface
public:
    void Update() override;
    void Render() override;
};

#endif // MENUBACKGROUND_H
