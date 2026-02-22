#ifndef ENEMY_SQUARE_CLASS
#define ENEMY_SQUARE_CLASS

#include "Entity.h"

class EnemySquare : public Entity
{
private:
    float m_Height = 50;
    float m_Width = 50;
    Rectangle m_Rec;

public:
    // constructor/destructor
    EnemySquare(float height, float width, Vector2 initPos);

    // methods

    virtual void computeMovement() override;
    virtual void renderEntity() override;
    virtual void attack() override;

    void followPlayer(Vector2 playerPos);

    // getters
    Rectangle getRec();
    float getHeight();
    float getWidth();

    // setters
    void setRec(Rectangle rec);
    void setHeight(float height);
    void setWidth(float width);
};

#endif
