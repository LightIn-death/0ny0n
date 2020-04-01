#include "Room.h"

#include <iostream>
#include <ctime>


using namespace std;
Room::Room()
{
    //ctor
}

Room::~Room()
{
    //dtor
}


Vector2 Room::get_roomSize()
{
    return this->roomSize;
}


void Room::show()
{
    //
  //  int i;
    //for(i=0;i<int(this->get_roomSize().x);i++){
      //  wsprintf(&screen[(int(this->position.y) *nScreenWidth) +int(this->position.x) + i ], L"#");
    //}



    //wsprintf(&screen[nScreenWidth + 5], L"www.OneLoneCoder.com - S N A K E ! !                SCORE: %d", 10);
/*

    cout    << "x de " << this->position.x <<" a "<< this->roomSize.x +this->position.x
            << " | et y de " <<  this->position.y
            <<" a " << this->roomSize.y + this->position.y
            <<endl;*/
}
