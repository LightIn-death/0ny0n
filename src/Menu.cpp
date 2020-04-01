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

void Menu::menuPricipal(){
    this->ClearConsoleInputBuffer();
    int selection = 0;
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
                this->ClearConsoleInputBuffer();
                selection -= 1;

                if (selection < 0){
                    selection = 2;
                }
            }else if(GetAsyncKeyState(VK_DOWN)){
                this->ClearConsoleInputBuffer();
                selection += 1;

                if (selection > 2){
                    selection = 0;
                }
            }
        }
        switch(selection){
        case 0:
            this->ClearConsoleInputBuffer();
            this->menuJouer();
            break;
        case 1:
            this->ClearConsoleInputBuffer();
            this->menuHistoire();
            break;
        case 2:
            this->ClearConsoleInputBuffer();
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
    PINPUT_RECORD ClearingVar1 = new INPUT_RECORD[100];
    DWORD ClearingVar2;
    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),ClearingVar1,100,&ClearingVar2);
    delete[] ClearingVar1;
}

void Menu::menuJouer(){

    this->ClearConsoleInputBuffer();
    int selection = 0;
        while (!GetAsyncKeyState(VK_RETURN)){
            system("cls");
            for (int i=0; i<3; i++){
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
                this->ClearConsoleInputBuffer();
                selection -= 1;

                if (selection < 0){
                    selection = 2;
                }
            }else if(GetAsyncKeyState(VK_DOWN)){
                this->ClearConsoleInputBuffer();
                selection += 1;

                if (selection > 2){
                    selection = 0;
                }
            }
        }
        switch(selection){
        case 0:
            this->ClearConsoleInputBuffer();
            cout << "Nouvelle Partie !" << endl;
            break;
        case 1:
            this->ClearConsoleInputBuffer();
            cout << "Partie Charge !" << endl;
            break;
        case 2:
            this->ClearConsoleInputBuffer();
            this->menuPricipal();
            break;
    }
}

void Menu::menuHistoire(){
    this->ClearConsoleInputBuffer();


    while (!GetAsyncKeyState(VK_RETURN)){
        system("cls");
        cout << "Vous etes le jeune princpe du royaume d'Onyon malheureusemment" << endl;
        cout << "votre promise a ete kidnape et emene 10 pieds sous terre." << endl;
        cout << "Votre objectifs ? Conquerir tous les etages afin de la sauver, mais garde " << endl;
        cout << "aux differents obstacles qui pourront vous barrer le passage." << endl;
    }

    this->menuPricipal();

}

void Menu::menuCredits(){

}
