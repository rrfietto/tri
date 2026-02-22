#include "EnemySquare.h"

EnemySquare::EnemySquare(float height, float width, Vector2 initPos) : m_Height(height), m_Width(width), Entity(initPos) { m_Rec = {m_Pos.x, m_Pos.y, m_Height, m_Width}; }

void EnemySquare::renderEntity()
{
    DrawRectanglePro(m_Rec, Vector2{0}, 0, BLUE);
}

void EnemySquare::computeMovement()
{
    return;
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
