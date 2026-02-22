#ifndef PLAYER_CLASS
#define PLAYER_CLASS

#include <raylib.h>
#include "Entity.h"
#include "Bullet.h"
#include <vector>

class Player : public Entity
{
protected:
    int m_Height = 30;
    int m_SideLength = 30;

public:
    // bullet vector
    std::vector<Bullet *> playerBullets;

    // constructor and destructor

    Player(Vector2 initPos);

    // methods
    virtual void computeMovement() override;
    virtual void renderEntity() override;
    virtual void attack() override;

    // setters

    void setHeight(int newHeight);
    void setSideLength(int newSideLength);

    // getters

    int getHeight();
    int getSideLength();
};

#endif
