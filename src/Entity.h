#ifndef ENTITY_CLASS
#define ENTITY_CLASS
#include <raylib.h>

class Entity
{
protected:
    Vector2 m_Pos;
    Vector2 m_Direction = {0};
    float m_Velocity = 0.075f;

public:
    // methods

    virtual void computeMovement() = 0;
    virtual void renderEntity() = 0;
    virtual void attack() = 0;

    void followPlayer(Vector2 playerPos);

    // constructor and destructor
    Entity(Vector2 initPos);
    virtual ~Entity();

    // sets

    void setPos(Vector2 newPos);

    // gets

    Vector2 getPos();
};

#endif
