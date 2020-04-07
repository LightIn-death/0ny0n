#include <windows.h>
#include "Menu.h"
#include <conio.h>
#include <iostream>
#include "Room.h"



using namespace std;

int main(){

int etage = 1;
while(etage <= 10){
    Room salle = Room(etage);
    etage = salle.menu();

}



    Menu* menu = new Menu();
    int selection;
    int debut_game = 0;
        system("cls");
        selection = menu->menuPricipal();
    //Nouvelle partie == 1    |   Charger partie == 0
        if (selection == 0){
            cout << "bravo" << endl;
            system("pause");
		}else if(selection == 3){
            system("exit");
        }
	return 0;

}

