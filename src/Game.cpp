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



Game::~Game()
{
    //dtor
}


void Game::_ready() {
    this->console = GameConsole();
}
void Game::_process() {
int i;
for(i=0;i<this->Map.get_Map().size();i++){
        this->Map.get_Map()[i]->show();
}

this->console.show();


}



void Game::_update_delta()
{
    this->oldtime=this->newtime;
    this->newtime=steady_clock::now();
    this->delta=float( duration_cast<microseconds>(newtime - oldtime).count()) / 10000;
}


















