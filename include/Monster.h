#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
using namespace std;
#include "Item.h"
#include "vector"

using std::vector;
using namespace std;


class Monster
{

    public:
        Monster();
        virtual ~Monster();


        void setNom(string val);
        void setVie(int val);
        void setDefense(int val);
        void setAttaque(int val);

        string getNom();
        string getAttaqueNom();
        int getVie();
        int getDefense();
        int getAttaque();
        void degat(int force);

    protected:   //héritage wsh
        string nom= "Monstre Generic";
        int vie = 10;
        int defense = 0;
        int attaque= 3;
        string atk_nom = "attaque basic";
    private:






};


class Player : public Monster{
    public:
        Player();
        virtual ~Player();
        void recupper(Item* item);
    int vie = 10;

    protected:
        string nom = "Prince";

        int defense = 10;
        int attaque = 10;
        vector<Item*> inventaire;

    private:

};

class Zombie : public Monster{
    public:
        Zombie();
        virtual ~Zombie();

    protected:

    private:
        string nom = "Zombie";
        int vie = 10;
        int defense = 1;
        int attaque = 1;
};




#endif // MONSTER_H
