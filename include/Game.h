#ifndef GAME_H
#define GAME_H
#include <chrono>
#include "Donjon.h"



using namespace std::chrono;



class Game
{
    public:
        Game();
        virtual ~Game();


        void _ready();
        void _process(float delta);
        void _update_delta();
        float delta;
        int debut_game = 0;

    protected:


    private:
       steady_clock::time_point   oldtime;
       steady_clock::time_point   newtime;

Donjon Map = Donjon();
};

#endif // GAME_H
