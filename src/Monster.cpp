#include "Monster.h"


Monster::Monster(){
    //ctor
}

Monster::~Monster(){
    //dtor
}

void Monster::degat(int force){
    this->vie -= force;
}

void Monster::setNom(string val) { this->nom = val; }
void Monster::setVie(int val) { this->vie = val; }
void Monster::setDefense(int val) { this->defense = val; }
void Monster::setAttaque(int val) { this->attaque = val; }

string Monster::getNom() { return this->nom; }
string Monster::getAttaqueNom() { return this->atk_nom; }
int Monster::getVie() { return this->vie; }
int Monster::getDefense() { return this->defense; }
int Monster::getAttaque() { return this->attaque; }


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
void
Player::recupper(Item* item){
this->inventaire.push_back(item);
}


