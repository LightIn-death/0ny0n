#include <iostream>
#include <windows.h>
#include "Menu.h"


using namespace std;

int main(){
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





