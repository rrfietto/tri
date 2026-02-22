#include "EnemySquare.h"
#include <raymath.h>

EnemySquare::EnemySquare(float height, float width, Vector2 initPos) : m_Height(height), m_Width(width), Entity(initPos)
{
    m_Rec = {m_Pos.x, m_Pos.y, m_Height, m_Width};
    m_Velocity = 0.02f;
}

void EnemySquare::renderEntity()
{
    DrawRectanglePro(m_Rec, Vector2{0}, 0, BLUE);
}

void EnemySquare::computeMovement()
{
    if (Vector2Length(m_Direction) > 0)
    {
        m_Direction = Vector2Normalize(m_Direction);
    }
    m_Pos.x += m_Direction.x * m_Velocity;
    m_Pos.y += m_Direction.y * m_Velocity;
    m_Rec.x = m_Pos.x;
    m_Rec.y = m_Pos.y;
}

void EnemySquare::followPlayer(Vector2 playerPos)
{
    Vector2 dest = Vector2Subtract(playerPos, m_Pos);
    this->m_Direction = dest;
}

void EnemySquare::attack()
{
    return;
}

Rectangle EnemySquare::getRec()
{
    return this->m_Rec;
}

float EnemySquare::getHeight()
{
    return this->m_Height;
}

float EnemySquare::getWidth()
{
    return this->m_Width;
}

void EnemySquare::setRec(Rectangle rec)
{
    this->m_Rec = rec;
}

void EnemySquare::setHeight(float height)
{
    this->m_Height = height;
}

void EnemySquare::setWidth(float width)
{
    this->m_Width = width;
}
