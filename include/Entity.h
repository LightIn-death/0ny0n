#ifndef ENTITY_H
#define ENTITY_H

#include "Vector2.h"


class Entity
{

    public:
        Entity();
        virtual ~Entity();

        Vector2 get_position();
        void set_position(Vector2 pos);

    protected:
        Vector2 position = Vector2();


    private:
};

#endif // ENTITY_H
