#include "Menu.h"
#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>

using namespace std;
Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

void Menu::Color(int couleurDuTexte,int couleurDeFond){
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void Menu::menuPricipal(){
    std::cin.clear();
    int selection = 0;
    char key_press;
    int ascii_value;
    while (ascii_value!=13){
        std::cin.clear();
            system("cls");
            for (int i=0; i<4; i++){
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
                case 3:
                    cout << "Exit    [";
                    break;
                    }
                if (selection == i ){
                    cout << "X]" << endl;;
                }else{
                    cout << " ]" << endl;;
                }
            }
            key_press=getch();
            ascii_value=key_press;

            if(ascii_value==72){
                std::cin.clear();
                selection -= 1;

                if (selection < 0){
                    selection = 3;
                }
            }else if(ascii_value==80){
                std::cin.clear();
                selection += 1;

                if (selection > 3){
                    selection = 0;
                }
            }
            std::cin.clear();
        }
        switch(selection){
        case 0:
            std::cin.clear();
            this->menuJouer();
            break;
        case 1:
            std::cin.clear();
            this->menuHistoire();
            break;
        case 2:
            std::cin.clear();
            this->menuCredits();
            break;
        case 3:
            system("exit");
            break;
    }
}

void Menu::ClearConsoleInputBuffer(){
    // If you happen to have any trouble clearing already cleared buffer, uncomment the section below.
    /* keybd_event('S', 0, 0, 0);
    keybd_event('S', 0,KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0, 0, 0);
    keybd_event(VK_BACK, 0,KEYEVENTF_KEYUP, 0); */
    PINPUT_RECORD ClearingVar1 = new INPUT_RECORD[1];
    DWORD ClearingVar2;
    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),ClearingVar1,1,&ClearingVar2);
    delete[] ClearingVar1;
}

void Menu::menuJouer(){
    std::cin.clear();
    int selection = 0;
    char key_press;
    int ascii_value;
        while (ascii_value!=13){
            std::cin.clear();
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
            key_press=getch();
            ascii_value=key_press;

            if(ascii_value==72){
                std::cin.clear();
                selection -= 1;

                if (selection < 0){
                    selection = 2;
                }
            }else if(ascii_value==80){
                std::cin.clear();
                selection += 1;

                if (selection > 2){
                    selection = 0;
                }
            }
        }
        switch(selection){
        case 0:
            std::cin.clear();
            cout << "Nouvelle Partie !" << endl;
            break;
        case 1:
            std::cin.clear();
            cout << "Partie Charge !" << endl;
            break;
        case 2:
            std::cin.clear();
            this->menuPricipal();
            break;
    }
}

void Menu::menuHistoire(){
    std::cin.clear();
    char key_press;
    int ascii_value;
    while (ascii_value!=13){

        system("cls");
        cout << "Vous etes le jeune prince du royaume d'Onyon malheureusemment" << endl;
        cout << "votre promise a ete kidnape et enmene 10 pieds sous terre." << endl;
        cout << "Votre objectif ? Conquerir tous les etages afin de la sauver, mais garde " << endl;
        cout << "aux differents obstacles qui pourront vous barrez le passage." << endl;
        key_press=getch();
        ascii_value=key_press;
    }
    this->menuPricipal();
}
void Menu::menuCredits(){
const char rocket[] =
"                                           \n\
                                             \n\
         Il y a bien longtemps dans une contree lointaine tres lointaine... \n\
\n\
\n\
                            PROLOGUE\n\
\n\
                              0ny0n\n\
                        \n\
                        \n\
                        Designe par : Breval\n\
                        \n\
                        Developpe par : Breval\n\
                        \n\
                        Invente par : Breval\n\
                        \n\
                        Decouvert par : Breval\n\
                        \n\
                    A Emerge du cerveau de : Breval\n\
                        \n\
                    Avec l'asstistance de : Breval\n\
                        \n\
                    Sans oublie le genie de : Breval\n\
                                Fin\n\
                                \n\
                                \n\
                                \n\
                                \n\
                                \n\
                                \n\
                                \n\
                                \n\
                                \n\
                                \n\
                    (ah oui y a Erwan qui a fait le menu)\n\
";


    for (int i = 0; i < 70; i ++) printf("\n"); // jump to bottom of console
    this->Color(6,0);
    printf("%s", rocket);
    this->Color(7,0);
    int j = 300000;
    for (int i = 0; i < 40; i ++) {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9995); // so sleep less each time
        printf("\n"); // move rocket a line upward
    }
    this->menuPricipal();
}
