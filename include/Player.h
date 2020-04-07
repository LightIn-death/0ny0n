#ifndef PLAYER_H
#define PLAYER_H

#include "Item.h"
#include "vector"

using std::vector;
using namespace std;

class Player
{
    public:
        Player();
        virtual ~Player();
        int attaque = 10;
         void recupper(Item* item);
         int pv = 100;

    protected:
        vector<Item*> inventaire;

    private:
};


#endif // PLAYER_H
