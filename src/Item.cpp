#include "Item.h"

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
    //ctor
}
Armure::~Armure(){
    //dtor
}




Arme::Arme(){
    //ctor
}
Arme::~Arme(){
    //dtor
}

Baton::Baton(){
    //ctor
}
Baton::~Baton(){
    //dtor
}

Clavier::Clavier(){
    //ctor
}
Clavier::~Clavier(){
    //dtor
}

Epee::Epee(){
    //ctor
}
Epee::~Epee(){
    //dtor
}

