#ifndef DONJON_H
#define DONJON_H

#include <vector>
#include "Entity.h"
#include "Room.h"
using std::vector;


class Donjon : public Entity
{



    public:
        Donjon();
        virtual ~Donjon();

        void initDonjon();
        vector<Room*> get_Map();

    protected:

    private:
         vector<Room*> Map;

};

#endif // DONJON_H
