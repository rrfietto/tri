#include "Player.h"
#include <raymath.h>
#include <iostream>

Player::Player(Vector2 initPos) : Entity(initPos) {}

void Player::computeMovement()
{
    if (IsKeyDown(KEY_D))
    {
        m_Direction.x += 1;
    }
    if (IsKeyDown(KEY_A))
    {
        m_Direction.x -= 1;
    }
    if (IsKeyDown(KEY_W))
    {
        m_Direction.y -= 1;
    }
    if (IsKeyDown(KEY_S))
    {
        m_Direction.y += 1;
    }

    if (Vector2Length(m_Direction) > 0)
    {
        m_Direction = Vector2Normalize(m_Direction);
    }

    m_Pos.x += m_Direction.x * m_Velocity;
    m_Pos.y += m_Direction.y * m_Velocity;

    m_Direction = {0};
}

void Player::renderEntity()
{
    Vector2 mousePos = GetMousePosition();
    Vector2 pointPos;
    float angle = atan2(mousePos.y + m_SideLength - m_Pos.y, mousePos.x - m_Pos.x) * 180 / PI;
    DrawPoly(m_Pos, 3, m_SideLength, angle, MAROON);
}

void Player::attack()
{
    Vector2 mousePos = GetMousePosition();
    Vector2 dir = Vector2Subtract(mousePos, m_Pos);
    float angle = atan2(mousePos.y - m_Pos.y, mousePos.x - m_Pos.x) * 180 / PI;
    Bullet *b = new Bullet(m_Pos, angle, dir);
    std::cout << "pos x: " << m_Pos.x << " pos y: " << m_Pos.y << std::endl;
    std::cout << "angle: " << angle << std::endl;
    playerBullets.push_back(b);
}

int Player::getHeight()
{
    return this->m_Height;
}

int Player::getSideLength()
{
    return this->m_SideLength;
}

void Player::setHeight(int newHeight)
{
    this->m_Height = newHeight;
}

void Player::setSideLength(int newSideLength)
{
    this->m_SideLength = newSideLength;
}
