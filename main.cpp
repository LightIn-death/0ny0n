#include <iostream>
#include <windows.h>

#include "Game.h"


using namespace std;

int main()
{

    Game game= Game();

    game._ready();


   while(1){

       game._update_delta();
       //cout << game.delta << endl;


   }


    cout << "Hello world!" << endl;
    return 0;
}


