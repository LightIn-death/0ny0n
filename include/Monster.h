#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
using namespace std;


class Monster
{
    public:
        Monster();
        virtual ~Monster();

        void degat(int force);

        string nom = "Monstre Generic";
        int atk = 3;
        string atk_nom = "giffle";
        int pv = 25;

    protected:



    private:
};

#endif // MONSTER_H
