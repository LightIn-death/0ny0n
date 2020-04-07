#include "Room.h"


#include <iostream>
using namespace std;


Room::Room(int etage)
{

    this->etage = etage;

}

Room::~Room()
{
    //dtor
}


int Room::menu(){
    int nombres_de_choix_possibles_dans_le_menu = nbrMonstres + 2;

    for (int a  = 0; a < choix; a++){
        cout << "[etage "<< this->etage <<"]\n 1 : hello toi \n2 : Ok.\n>";
    }



    cin >> choix;




    if (choix == 4){
        this->etage = -1;
    }

    return this->etage+1;
}
