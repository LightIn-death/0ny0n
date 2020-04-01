#include <iostream>
#include <windows.h>
#include "Menu.h"
#include <conio.h>
#include "Game.h"


using namespace std;



int main()
{

    Menu* menu = new Menu();
    int selection;
    int debut_game = 0;
    while(selection != 3){
        system("cls");
        selection = menu->menuPricipal();
    //Nouvelle partie == 1    |   Charger partie == 0
            Game game = Game();


            if (selection == 0){
                while (selection == 0){
                    game._update_delta();
                    if(GetAsyncKeyState(VK_ESCAPE)){
                        selection = menu->menuPause();
                    }
                }
            }else if (selection == 1){
                cout << "chaussure" << endl;
            }

        }

    return 0;
}

