#include <iostream>
#include <windows.h>

#include "Game.h"


using namespace std;

int main()
{

    Game game= Game();
    while(1)
    {
        game._update_delta();
        game._process();
    }



    return 0;
}


