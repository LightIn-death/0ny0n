#include "Monster.h"

Monster::Monster(){
    //ctor
}

Monster::~Monster(){
    //dtor
}

void Monster::setNom(string val) { nom = val; }
void Monster::setVie(int val) { vie = val; }
void Monster::setDefense(int val) { defense = val; }
void Monster::setAttaque(int val) { attaque = val; }

string Monster::getNom() { return nom; }
int Monster::getVie() { return vie; }
int Monster::getDefense() { return defense; }
int Monster::getAttaque() { return attaque; }


Zombie::Zombie()
{
    //ctor
}

Zombie::~Zombie()
{
    //dtor
}

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}
