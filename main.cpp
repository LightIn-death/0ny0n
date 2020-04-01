#include <iostream>
#include <windows.h>

using namespace std;

int main()
{

        int touche[5];

        for (int i=0; i<5; i++){
            touche[i]=i;
        }

        int selection = 0;

    while (1) {
        for (int i=0; i<5; i++){
            cout << "choix " << i << " [";
            if (selection == i ){
                cout << "X]" << endl;;
            }else{
                cout << " ]" << endl;;
            }
        }

        if(GetAsyncKeyState(VK_UP)){

        }else if(GetAsyncKeyState(VK_DOWN)){

        }
    system("cls");

    }
    cout << "Hello world" << endl;
    return 0;
}
