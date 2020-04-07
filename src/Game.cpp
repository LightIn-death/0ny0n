#include "Game.h"
#include "Donjon.h"
#include "GameConsole.h"
#include <chrono>
#include <iostream>
using namespace std;


using namespace std::chrono;

Game::Game()
{
    this->newtime=steady_clock::now();
}

Game::~Game() {}


void Game::_ready()
{
    system("cls");
    this->console = GameConsole();


    int i;
    for(i=0; i<this->Map.get_Map().size(); i++)
    {
        this->Map.get_Map()[i]->show();
    }
}




void Game::_process()
{




//this->console.show();


}



void Game::_update_delta()
{
    this->oldtime=this->newtime;
    this->newtime=steady_clock::now();
    this->delta=float( duration_cast<microseconds>(newtime - oldtime).count()) / 10000;
}


















