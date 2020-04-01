#include <iostream>
#include <windows.h>
#include "Menu.h"
#include <conio.h>
#include "Game.h"


using namespace std;



int main()
{



    Menu* menu = new Menu();
    int debut_game = menu->menuPricipal();

//Nouvelle partie == 1    |   Charger partie == 0
    if(debut_game == 0){
        Game game = Game();
            while (debut_game == 1){
                game._update_delta();
                cout << "1" << endl;
                if(GetAsyncKeyState(VK_ESCAPE)){
                   menu->ClearConsoleInputBuffer();
                   debut_game = menu->menuPause();
                }
            }
            menu->ClearConsoleInputBuffer();
            menu->menuPricipal();

    }else if(debut_game == 1) {

    }

    return 0;
}

