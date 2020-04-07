#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "Item.h"
using namespace std;
using std::vector;

class Room
{
    public:
        Room(int etage,Player joueur);
        virtual ~Room();
        int menu();
    protected:
      void monstre_attaque();


    private:
        Player joueur;
        vector<Monster*> mobs;
        vector<Item*> loots;
        int etage;
};

#endif // ROOM_H
