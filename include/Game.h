#ifndef GAME_H
#define GAME_H
#include <chrono>

using namespace std::chrono;


class Game
{
    public:
        Game();
        virtual ~Game();


        void _ready();
        void _process(delta);
        void _update_delta();
        float delta;


    protected:


    private:
       steady_clock::time_point   oldtime;
       steady_clock::time_point   newtime;
};

#endif // GAME_H
