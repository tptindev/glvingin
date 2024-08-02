#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include <AEntity.h>

class ExitButton : public AEntity
{
public:
    ExitButton();
    ~ExitButton();

    // AEntity interface
public:
    void Update(float deltaTime) override;
    void Render() override;
};

#endif // EXITBUTTON_H
