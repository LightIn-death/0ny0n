#include <iostream>
#include <windows.h>
#include "Menu.h"

using namespace std;

int main()
{
    int selection = 0;

    Menu* debut = new Menu();

    debut->menuPricipal(selection);



    debut->ClearConsoleInputBuffer();
    cout << "Choix " << selection << " selectionne" << endl;

    return 0;
}
