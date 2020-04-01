#include <iostream>
#include <windows.h>
#include "Menu.h"

using namespace std;

int main()
{

    Menu* debut = new Menu();
    debut->menuPricipal();
    debut->ClearConsoleInputBuffer();



    return 0;
}
