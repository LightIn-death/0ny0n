#ifndef GAME_H
#define GAME_H
#include <chrono>
#include "Donjon.h"
#include "GameConsole.h"

using namespace std::chrono;



class Game
{
    public:
        Game();
        virtual ~Game();

        void _ready();
        void _process();
        void _update_delta();
        float delta;


    protected:



    private:
        GameConsole console;
        steady_clock::time_point oldtime;
        steady_clock::time_point newtime;

Donjon Map = Donjon();
};

#endif // GAME_H
