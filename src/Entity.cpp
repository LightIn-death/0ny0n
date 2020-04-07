#include "Entity.h"

Entity::Entity()
{
    //ctor
}

Entity::~Entity()
{
    //dtor
}


Vector2 Entity::get_position()
{
    return this->position;

}
void Entity::set_position(Vector2 pos)
{
    this->position = pos;
}
