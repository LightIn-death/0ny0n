#include <iostream>
#include <windows.h>
#include "Menu.h"
#include <conio.h>
#include "Game.h"


using namespace std;



int main()
{

    Menu* menu = new Menu();
    int partie_en_cours = 0;
    int debut_game;
    while(debut_game != 3){
        system("cls");
        debut_game = menu->menuPricipal();
        menu->ClearConsoleInputBuffer();


    //Nouvelle partie == 1    |   Charger partie == 0
        if(debut_game == 0 ){

            Game game = Game();
            while (partie_en_cours == 0){
                game._update_delta();
                if(GetAsyncKeyState(VK_ESCAPE)){
                    partie_en_cours = menu->menuPause();

                }
            }

            partie_en_cours = 1;
            debut_game = 1;


        }else if(debut_game == 1) {
            if (partie_en_cours == 1){
                cout << "Il y a une partie en cours" << endl;
                menu->ClearConsoleInputBuffer();

            }else{
                cout << "Il n'y a pas de partie en cours" << endl;
                menu->ClearConsoleInputBuffer();

            }
        }else {
            cout << debut_game << endl;
        }
    }
    return 0;
}

