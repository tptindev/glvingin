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
    void Update() override;
    void Render() override;
};

#endif // STARTBUTTON_H
