
#include <windows.h>
#include <MMsystem.h>
#include "Menu.h"
#include <iostream>
#include <conio.h>
#include "Room.h"
using namespace std;
#include <ctime>




int main(){
    srand (time(NULL));
    PlaySound(TEXT("song.wav"),NULL,SND_ASYNC | SND_LOOP);

void base(Player* joueur)
{

    bool running = true;


    while(running)
    {
        system("cls");
        int i = 1;

          cout << "vous avez actuellement " << joueur->Or << " pieces d'or ! \n\n\n";


        if(joueur->Or >= 50)

        etage_old = etage;
        Room salle = Room(etage,&joueur);
        while(etage == etage_old)
        {

            cout << i <<" : Vous pouvez aumenter votre vie de 50 PV \n";
            i++;

        }
        else
        {
            cout <<"Vous n\'avez pas assez d'argent ! \n";
        }

        cout << i << " : Retourné combattre dans la tours.\n\n\n>";





        int choix = 0;
        cin >> choix;

        if(joueur->Or >= 50 && choix == 1)
        {
            cout <<" Vous avez ajouter 50 pv !\n";
            joueur->setVie_Max(50);
            joueur->Or-=50;
            _getch();
        }
        else
        {

            cout << " preparer vous aux combat !\n";
            running = false;
        }


    }
}































int main()
{
    srand (time(NULL));

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

                base(&joueur);
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

















