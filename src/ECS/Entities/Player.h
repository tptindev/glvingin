#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity.h"

class Player : public Entity
{
public:
    Player();
    ~Player();

    // AEntity interface
public:
    virtual void Update() override;
    virtual void Render() override;
};

#endif // PLAYER_H
