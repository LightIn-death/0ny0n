#include "Vector2.h"
#include <math.h>
#include  <stdlib.h>

using namespace std;

Vector2::Vector2()
{
    //ctor
}


Vector2::Vector2(double x, double y)
{
    this->x = x;
    this->y = y;
}


Vector2::~Vector2()
{
    //dtor
}


void Vector2::normalize()
{
    this->x = this->x / lenght();
    this->y = this->y / lenght();
}



double Vector2::lenght()
{
    double lenght;
    double x;
    double y;
    x = this->x;
    y = this->y;
    lenght = sqrt((x*x)+(y*y));
    return lenght;
}



Vector2 Vector2::distanceTo(Vector2 vect)
{
    return Vector2(abs(vect.x-this->x),abs(vect.y-this->y));
}

Vector2 Vector2::vectorTo(Vector2 vect)
{
    return Vector2((vect.x-this->x),(vect.y-this->y));
}







