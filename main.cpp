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

    while (!GetAsyncKeyState(VK_)) {
        for (int i=0; i<5; i++){
            cout << "choix " << i << " [";
            if (selection == i ){
                cout << "X]" << endl;;
            }else{
                cout << " ]" << endl;;
            }
        }

        if(GetAsyncKeyState(VK_UP)){
            selection -= 1;

            if (selection < 0){
                selection = 4;
            }
        }else if(GetAsyncKeyState(VK_DOWN)){
            selection += 1;

            if (selection > 4){
                selection = 0;
            }
        }

    system("cls");

    }
    cout << "Choix " << selection << " selectionne" << endl;

    return 0;
}
