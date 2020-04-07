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
    int choix;
    cout << "[etage "<< this->etage <<"]\n1 : hello toi \n2 : Ok.\n>";
    cin >> choix;

    return this->etage+1;
}
