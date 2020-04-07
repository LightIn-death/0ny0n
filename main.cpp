
#include <windows.h>
#include <conio.h>
#include "Room.h"



#include <iostream>
using namespace std;


int main(){

int etage = 1;

while(1){

    Room salle = Room(etage);
    etage = salle.menu();
}


    return 0;
}






