#include "Menu.h"
#include <iostream>
#include <windows.h>
using namespace std;
Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

int Menu::menuPricipal(int selection){

    while (!GetAsyncKeyState(VK_RETURN)){
            system("cls");
            for (int i=0; i<3; i++){
                    switch(i){
                case 0:
                    cout << "Jouer   [";
                    break;
                case 1:
                    cout << "Lore    [" ;
                    break;
                case 2:
                    cout << "Credits [";
                    break;
                    }
                if (selection == i ){
                    cout << "X]" << endl;;
                }else{
                    cout << " ]" << endl;;
                }
            }

            if(GetAsyncKeyState(VK_UP)){
                ClearConsoleInputBuffer();
                selection -= 1;

                if (selection < 0){
                    selection = 2;
                }
            }else if(GetAsyncKeyState(VK_DOWN)){
                ClearConsoleInputBuffer();
                selection += 1;

                if (selection > 2){
                    selection = 0;
                }
            }
        }
        switch(selection){
        case 0:
            this->menuJouer();
            break;
        case 1:
            this->menuHistoire();
            break;
        case 2:
            this->menuCredits();
            break;
    }
}


void Menu::ClearConsoleInputBuffer(){
    // If you happen to have any trouble clearing already cleared buffer, uncomment the section below.
    /* keybd_event('S', 0, 0, 0);
    keybd_event('S', 0,KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0, 0, 0);
    keybd_event(VK_BACK, 0,KEYEVENTF_KEYUP, 0); */
    PINPUT_RECORD ClearingVar1 = new INPUT_RECORD[256];
    DWORD ClearingVar2;
    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),ClearingVar1,256,&ClearingVar2);
    delete[] ClearingVar1;
}

void Menu::menuJouer(int selection){

    while (!GetAsyncKeyState(VK_RETURN)){
            system("cls");
            for (int i=0; i<2; i++){
                    switch(i){
                case 0:
                    cout << "Nouvelle Partie [";
                    break;
                case 1:
                    cout << "Charger Partie  [" ;
                    break;
                case 2:
                    cout << "Retour          [";
                    break;
                    }
                if (selection == i ){
                    cout << "X]" << endl;;
                }else{
                    cout << " ]" << endl;;
                }
            }

            if(GetAsyncKeyState(VK_UP)){
                ClearConsoleInputBuffer();
                selection -= 1;

                if (selection < 0){
                    selection = 2;
                }
            }else if(GetAsyncKeyState(VK_DOWN)){
                ClearConsoleInputBuffer();
                selection += 1;

                if (selection > 2){
                    selection = 0;
                }
            }
        }
        switch(selection){
        case 0:
            cout << "Nouvelle Partie !" endl;
            break;
        case 1:
            cout << "Partie Charge !" endl;
            break;
        case 2:
            this->menuPricipal();
            break;
    }
}
