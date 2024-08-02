#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <AEntity.h>

class StartButton : public AEntity
{
public:
    StartButton();
    ~StartButton();

    // AEntity interface
public:
    void Update(float deltaTime) override;
    void Render() override;
};

#endif // STARTBUTTON_H
