#include "Monster.h"

Monster::Monster()
{
    //ctor
}

Monster::~Monster()
{
    //dtor
}


void Monster::degat(int force){
    this->pv -= force;
}
