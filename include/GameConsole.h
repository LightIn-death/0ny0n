#ifndef GAMECONSOLE_H
#define GAMECONSOLE_H
#include <windows.h>
#include "Vector2.h"


class GameConsole
{
    public:
        GameConsole();
        virtual ~GameConsole();
        void show();

        void set_cursor(Vector2 vec);



    protected:

        int nScreenWidth = 200;
        int nScreenHeight = 200;
        wchar_t *screen;
        HANDLE hConsole;

    private:
        DWORD* dwBytesWritten;


};

#endif // GAMECONSOLE_H
