#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include "Vector2.h"
#include <iostream>
#include <ctime>


using namespace std;


class Room : public Entity
{
    public:
        Room();
        virtual ~Room();

        Vector2 get_roomSize();
        void show();



    protected:

    private:
        Vector2 roomSize = Vector2(3,3);
};

#endif // ROOM_H
