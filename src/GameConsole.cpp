#include "GameConsole.h"
#include <windows.h>
GameConsole::GameConsole()
{
    // Create Screen Buffer
	this->screen = new wchar_t[this->nScreenWidth*this->nScreenHeight];
	for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
	this->hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	this->dwBytesWritten = 0;
}

GameConsole::~GameConsole()
{
    //dtor
}


void GameConsole::show(){
WriteConsoleOutputCharacter(this->hConsole, this->screen, this->nScreenWidth * this->nScreenHeight, { 0,0 }, this->dwBytesWritten);
}






