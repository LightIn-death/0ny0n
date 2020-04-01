#ifndef GAMECONSOLE_H
#define GAMECONSOLE_H
#include <windows.h>

class GameConsole
{
    public:
        GameConsole();
        virtual ~GameConsole();
        void show();

    protected:

        int nScreenWidth = 200;
        int nScreenHeight = 200;
        wchar_t *screen;

    private:
        DWORD* dwBytesWritten;
        HANDLE hConsole;

};

#endif // GAMECONSOLE_H
