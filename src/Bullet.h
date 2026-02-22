#ifndef BULLET_CLASS
#define BULLLET_CLASS
#include <raylib.h>
#include <raymath.h>

class Bullet
{
private:
    Vector2 m_Pos;
    float m_Speed = 0.2f;
    float m_Height = 10;
    float m_Width = 10;
    float m_Angle;
    Vector2 m_Dir;
    Rectangle m_Rec;
    bool m_Active = true;

public:
    // constructor and destructor
    Bullet(Vector2 initPos, float angle, Vector2 dir);
    ~Bullet();

    // getters

    Vector2 getPos();
    float getSpeed();
    float getHeight();
    float getWidth();
    Rectangle getRec();
    bool isActive();

    // setters

    void setPos(Vector2 pos);
    void setSpeed(float speed);
    void setHeight(float height);
    void setWidth(float width);

    void deactivate(); // a bullet can never be activated

    // methods

    void moveAndRender();
};

#endif
