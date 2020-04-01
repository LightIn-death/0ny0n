#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include "Vector2.h"


class Room : public Entity
{
    public:
        Room();
        virtual ~Room();

        Vector2 get_roomSize();



    protected:

    private:
        Vector2 roomSize = Vector2(10,10);
};

#endif // ROOM_H
