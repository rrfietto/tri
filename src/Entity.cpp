#include "Entity.h"

Entity::Entity(Vector2 initPos) : m_Pos(initPos) {}

Entity::~Entity() {}

void Entity::setPos(Vector2 newPos)
{
    this->m_Pos = newPos;
}

Vector2 Entity::getPos()
{
    return this->m_Pos;
}
