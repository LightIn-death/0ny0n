#include "Donjon.h"

#include <cstdlib>
#include <iostream>
#include <ctime>


using namespace std;

Donjon::Donjon()
{

   srand( (unsigned)time(NULL) );

this->initDonjon();

}

Donjon::~Donjon()
{
    //dtor
}


void Donjon::initDonjon(){

    Room piece_depart = Room();
    Room piece_arrive = Room();

    piece_depart.set_position(Vector2(20,20));
    piece_arrive.set_position(Vector2(90,50));
    this->Map.push_back(&piece_depart);
    this->Map.push_back(&piece_arrive);




    double distanceToFinal= piece_depart.get_position().distanceTo(piece_arrive.get_position()).lenght();


    cout << endl << "This end : " << distanceToFinal<< endl;














}
