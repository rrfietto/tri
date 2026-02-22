#include "Bullet.h"

// constructor and destructor
Bullet::Bullet(Vector2 initPos, float angle, Vector2 dir) : m_Pos(initPos), m_Angle(angle), m_Dir(dir) { m_Rec = {m_Pos.x, m_Pos.y, m_Height, m_Width}; }

Bullet::~Bullet() {}

// getters

Vector2 Bullet::getPos()
{
    return this->m_Pos;
}
float Bullet::getSpeed()
{
    return this->m_Speed;
}
float Bullet::getHeight()
{
    return this->m_Height;
}
float Bullet::getWidth()
{
    return this->m_Width;
}
bool Bullet::isActive()
{
    return this->m_Active;
}

Rectangle Bullet::getRec()
{
    return this->m_Rec;
}

// setters

void Bullet::setPos(Vector2 pos)
{
    this->m_Pos = pos;
}
void Bullet::setSpeed(float speed)
{
    this->m_Speed = speed;
}
void Bullet::setHeight(float height)
{
    this->m_Height = height;
}
void Bullet::setWidth(float width)
{
    this->m_Width = width;
}
void Bullet::deactivate()
{
    this->m_Active = false;
}

void Bullet::moveAndRender()
{
    m_Rec = {m_Pos.x, m_Pos.y, m_Height, m_Width};
    Vector2 normalizedDir = Vector2Normalize(m_Dir);
    m_Pos.x += normalizedDir.x * m_Speed;
    m_Pos.y += normalizedDir.y * m_Speed;

    if (!(m_Pos.x < GetRenderWidth() && m_Pos.y < GetRenderHeight() && m_Pos.x >= 0 && m_Pos.y >= 0))
    {
        this->deactivate();
        return;
    }
    DrawRectanglePro(m_Rec, {m_Rec.width / 2, m_Rec.height / 2}, m_Angle, VIOLET);
}
