#include "Room.h"
#include <iostream>
#include <ctime>
#include "Entity.h"




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


    //this->set_cursor(Vector2(10,10));

   int i;
   for(i=0;i<int(this->get_roomSize().x);i++){

       this->set_cursor(Vector2(int(this->position.y),int(this->position.x)+i));
        cout << "#";
   }


      for(i=0;i<int(this->get_roomSize().x);i++){

       this->set_cursor(Vector2(int(this->position.y)+int(this->get_roomSize().y),int(this->position.x)+i));
        cout << "#";
   }





   for(i=0;i<int(this->get_roomSize().y);i++){

       this->set_cursor(Vector2(int(this->position.y)+i,int(this->position.x)));
        cout << "#";
   }


      for(i=0;i<int(this->get_roomSize().y);i++){

       this->set_cursor(Vector2(int(this->position.y)+i,int(this->position.x)+int(this->get_roomSize().x)));
        cout << "#";
   }














}


























