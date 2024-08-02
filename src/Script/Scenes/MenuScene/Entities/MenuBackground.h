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
    void Update(float deltaTime) override;
    void Render() override;
};

#endif // MENUBACKGROUND_H
