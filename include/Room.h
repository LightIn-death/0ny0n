#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include "Monster.h"
#include <mmsystem.h>
#include <windows.h>
#include "Menu.h"
#include <mmsystem.h>
#include <iostream>
#include <conio.h>
#include "Room.h"
using namespace std;
#include <ctime>
#include "Item.h"
using namespace std;
using std::vector;

class Room
{
    public:
        Room(int etage,Player* joueur);
        virtual ~Room();
        int menu();

        static void Color(int couleurDuTexte,int couleurDeFond);
        void base(Player* joueur);

    protected:
    void monstre_attaque();
    int inventaire();
    void persoStats();
    void dessinerAscii();
    void AsciiArtMonster();




    private:
        Player* joueur;
        vector<Monster*> mobs;
        vector<Item*> loots;
        int etage;
};

#endif // ROOM_H
