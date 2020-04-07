
#include <windows.h>
#include <conio.h>
#include "Room.h"
#include "Player.h"
#include <iostream>
using namespace std;


int main()
{

    int etage = 1;
    int etage_old;
    Player joueur = Player();

    while(1)
    {
        etage_old = etage;
        Room salle = Room(etage,joueur);
        while(etage == etage_old)
        {
            etage = salle.menu();
        }
        if(etage==0){
            //base
            cout << "la base na pas encore ete implementer\n\n";
            etage++;
        }
    }




    return 0;
}






