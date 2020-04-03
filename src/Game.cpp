#include "Game.h"
#include "Donjon.h"
#include <chrono>
#include <iostream>
#include <windows.h>
#include "Menu.h"

using namespace std::chrono;
using namespace std;

Game::Game()
{
    this->newtime=steady_clock::now();
}


Game::~Game()
{
    //dtor
}


void Game::_ready() {



}
void Game::_process(float delta) {}



void Game::_update_delta()
{

/*
    this->oldtime=this->newtime;
    this->newtime=steady_clock::now();
    this->delta=float( duration_cast<microseconds>(newtime - oldtime).count()) / 10000;
*/
cout << debut_game++ << endl;

}


















