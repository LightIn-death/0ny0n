#include "Item.h"


#include <vector>

using namespace std;
using std::vector;


Item::Item(){
    //ctor
}
Item::~Item(){
    //dtor
}

void Item::setNom(string val) { nom = val; }
void Item::setVie(int val) { vie = val; }
void Item::setDefense(int val) { defense = val; }
void Item::setAttaque(int val) { attaque = val; }

string Item::getNom() { return nom; }
int Item::getVie() { return vie; }
int Item::getDefense() { return defense; }
int Item::getAttaque() { return attaque; }

Potion::Potion(){
    //ctor
}
Potion::~Potion(){
    //dtor
}




Armure::Armure(){
    //dtor
}
Armure::~Armure(){
    //dtor
}



Chemise::Chemise(){
    string nom = "Chemise";
    this->vie = 0;
    this->defense = 1;
    this->attaque = 0;
}

Kevlar::Kevlar(){
    string nom = "Kevlar";
    this->vie = 0;
    this->defense = 3;
    this->attaque = 0;
}

Cuirasse::Cuirasse(){
    string nom = "Cuirasse";
    this->vie = 0;
    this->defense = 5;
    this->attaque = 0;
}



Arme::Arme(){
    //ctor
}
Arme::~Arme(){
    //dtor
}



Baton::Baton(){
    string nom = "Baton";
    this->vie = 0;
    this->defense = 0;
    this->attaque = 1;
}

Clavier::Clavier(){
    string nom = "Clavier";
    this->vie = 0;
    this->defense = 0;
    this->attaque = 3;
}

Epee::Epee(){
    string nom = "Epee";
    this->vie = 0;
    this->defense = 0;
    this->attaque = 5;
}
