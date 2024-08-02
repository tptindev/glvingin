#ifndef PLAYER_H
#define PLAYER_H

#include <AEntity.h>

class Player : public AEntity
{
public:
    Player();
    ~Player();

    // AEntity interface
public:
    virtual void Update(float deltaTime) override;
    virtual void Render() override;
};

#endif // PLAYER_H
