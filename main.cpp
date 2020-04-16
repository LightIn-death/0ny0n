#include <windows.h>
#include "Menu.h"
#include <mmsystem.h>
#include <iostream>
#include <conio.h>
#include "Room.h"
#include <thread>
using namespace std;
#include <ctime>



void music(){

PlaySound(TEXT("song.wav"),NULL,SND_ASYNC | SND_LOOP);

}

int main()
{
    srand (time(NULL));
    //thread snd(music);
    //snd.join();

    Menu* menu = new Menu();
    int selection;
    int debut_game = 0;
    system("cls");
    selection = menu->menuPricipal();
    //Nouvelle partie == 1    |   Charger partie == 0
    if (selection == 0)
    {


        int etage = 1;
        int etage_old;
        Player joueur = Player();


        while(etage<=10)
        {

            etage_old = etage;
            Room salle = Room(etage,&joueur);
            while(etage == etage_old)
            {
                etage = salle.menu();
            }
            if(etage==0)
            {
                //base
                salle.base(&joueur);
                //cout << "la base na pas encore ete implementer\n\n";
                joueur.soigner();
                etage++;
            }
        }

        cout << "vous avez fini le jeux" << endl;

        system("pause");
    }
    else if(selection == 3)
    {
        system("exit");
    }
    return 0;
}
