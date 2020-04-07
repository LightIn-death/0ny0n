#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void
Player::recupper(Item* item){
this->inventaire.push_back(item);
}
