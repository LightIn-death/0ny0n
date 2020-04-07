#include <windows.h>
#include "Menu.h"
#include <conio.h>
#include <iostream>
#include "Room.h"
#include "Player.h"
#include <iostream>
using namespace std;


int main(){


    Menu* menu = new Menu();
    int selection;
    int debut_game = 0;
        system("cls");
        selection = menu->menuPricipal();
    //Nouvelle partie == 1    |   Charger partie == 0
        if (selection == 0){


    int etage = 1;
    int etage_old;
    Player joueur = Player();

    while(etage<100)
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

    cout << "vous avez fini le jeux";




            system("pause");
		}else if(selection == 3){
            system("exit");
        }
	return 0;

}













