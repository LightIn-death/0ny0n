#include <iostream>
#include <windows.h>
#include "Menu.h"
#include <conio.h>
#include "Game.h"


using namespace std;

int main()
{


    Menu* debut = new Menu();
    int debut_game = debut->menuPricipal();

//Nouvelle partie == 0    |   Charger partie == 1
    if(debut_game == 0){

    }else if(debut_game == 1) {

    }

    Game game= Game();
    while(1)
    {
        game._update_delta();
        game._process();
    }




    return 0;
}

