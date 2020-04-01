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


void Donjon::initDonjon()
{

    Room piece_depart = Room();
    Room piece_arrive = Room();

    piece_depart.set_position(Vector2(20,20));
    piece_arrive.set_position(Vector2(90,50));
    this->Map.push_back(&piece_depart);
    this->Map.push_back(&piece_arrive);
    Room* LastCreate = &piece_depart;




    double distanceToFinal= piece_depart.get_position().distanceTo(piece_arrive.get_position()).lenght();




    while(distanceToFinal>piece_depart.get_roomSize().x)
    {

        cout << endl << "This end : " << distanceToFinal<< endl;






        if(LastCreate->get_position().vectorTo(piece_arrive.get_position()).x >= LastCreate->get_position().vectorTo(piece_arrive.get_position()).y)
        {

            if(LastCreate->get_position().vectorTo(piece_arrive.get_position()).x > 0)
            {

                double X =  LastCreate->get_position().x + LastCreate->get_roomSize().x + 1;
                double Y = LastCreate->get_position().y;

                Room piece_suivante = Room();
                piece_suivante.set_position(Vector2(X,Y));
                this->Map.push_back(&piece_suivante);
                LastCreate = &piece_suivante;

            }
            if(LastCreate->get_position().vectorTo(piece_arrive.get_position()).x < 0)
            {
                double X =  LastCreate->get_position().x - LastCreate->get_roomSize().x - 1;
                double Y = LastCreate->get_position().y;

                Room piece_suivante = Room();
                piece_suivante.set_position(Vector2(X,Y));
                this->Map.push_back(&piece_suivante);
                LastCreate = &piece_suivante;
            }

        }


        else if(LastCreate->get_position().vectorTo(piece_arrive.get_position()).x < LastCreate->get_position().vectorTo(piece_arrive.get_position()).y)
        {


            if(LastCreate->get_position().vectorTo(piece_arrive.get_position()).y > 0)
            {
                double X =  LastCreate->get_position().x ;
                double Y = LastCreate->get_position().y + LastCreate->get_roomSize().y + 1;


                Room piece_suivante = Room();
                piece_suivante.set_position(Vector2(X,Y));
                this->Map.push_back(&piece_suivante);
                LastCreate = &piece_suivante;
            }
            if(LastCreate->get_position().vectorTo(piece_arrive.get_position()).y < 0)
            {
                double X =  LastCreate->get_position().x ;
                double Y = LastCreate->get_position().y - LastCreate->get_roomSize().y - 1;

                Room piece_suivante = Room();
                piece_suivante.set_position(Vector2(X,Y));
                this->Map.push_back(&piece_suivante);
                LastCreate = &piece_suivante;
            }
        }

        distanceToFinal= LastCreate->get_position().distanceTo(piece_arrive.get_position()).lenght();

    }



    cout << "WIN ?! " ;



}
