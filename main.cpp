#include <iostream>
#include <windows.h>
#include "Menu.h"
#include <conio.h>
using namespace std;

int main()
{

    Menu* debut = new Menu();
    int debut_game = debut->menuPricipal();

//Nouvelle partie == 0    |   Charger partie == 1
    if(debut_game == 0){

    }else if(debut_game == 1) {

    }

    return 0;
}

