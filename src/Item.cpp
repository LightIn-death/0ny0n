#include "Item.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <vector>

using namespace std;
using std::vector;

Item::Item()
{
    //ctor
}
Item::~Item()
{
    //dtor
}

void Item::setNom(string val)
{
    this->nom = val;
}



void Item::setVie(int val)
{
    this->vie = val;
}
void Item::setDefense(int val)
{
    this->defense = val;
}
void Item::setAttaque(int val)
{
    this->attaque = val;
}

string Item::getNom()
{
    return this->nom;
}

string Item::getPosition()
{
     return this->position;
}

string Item::getDesciption()
{
     return this->description;
}
int Item::getVie()
{
    return this->vie;
}
int Item::getDefense()
{
    return this->defense;
}
int Item::getAttaque()
{
    return this->attaque;
}

  void Item::generatePosition(){



          string position[17] = {"est pose sur le sol","est pose contre le mur","est accroche au plafond","est sur un vieux cadavre","est fixe a la porte"
        ,"depasse d\'un trou dans le sol","est dans un vieux coffre au centre de la piece","est cache dans un creu du mur","se sent seul dans un coin"
        ,"est a cote de toi","te regarde bizarement","traine dans la poussiere","est recuperable","ne peut pas se manger","a un cote retro"
        ,"t'irait bien","te passionne"};
        int alea = rand() % 17;
    this->position = position[alea];

  }



Potion::Potion()
{


    this->nom = "Potion";
    this->vie = 10;
    this->defense = 0;
    this->attaque = 0;
    this->generatePosition();

    string description[4] = {
            "A l\'aire etrange et permime, je ne boirais pas ca si j\'etais toi",
            "Un liquide visqueux rougeatre se trouve dans une fiole en verre",
            "le bouchon semble perdu depuis longtemps... je ne sais pas depuis combien de temps c\'est ouvert !",
            "Si je la bois, la princesse me trouvera peut etre plus mignon"};
        int alea = rand() % 4;
    this->description = description[alea];


}






Armure::Armure()
{
    //dtor
}


Chemise::Chemise()
{
    this->nom = "Chemise";
    this->vie = 0;
    this->defense = 1;
    this->attaque = 0;
       this->generatePosition();

    string description[4] = {
            "Une bien etrange chemise retrouve a cote d'un cadavre, il manque juste les lunettes de soleil",
            "Cette chemise est facinante tant elle est belle.. je pourrais en oublier la princesse",
            "Il y a peut etre des poches pour mettre des sous dans cette chemise ?",
            "Il semble manquer un bouton ! On peut presque voir ton torse royal."};
        int alea = rand() % 4;
    this->description = description[alea];


}

Kevlar::Kevlar()
{
    this->nom = "Kevlar";
    this->vie = 0;
    this->defense = 3;
    this->attaque = 0;
       this->generatePosition();

           string description[4] = {
            "Voici une protection digne d\'un garde du corps",
            "Tu savais que le kevlar s\'inspire des toiles d\'araignee ? ca donne moins envie...",
            "Un gilet par balle ?! Pour quoi faire ? Les monstre n\'ont pas de balles !",
            "Tu penses que la princesse aimera le style que ca te procure ?"};
        int alea = rand() % 4;
    this->description = description[alea];
}

Cuirasse::Cuirasse()
{
   this->nom= "Cuirasse";
    this->vie = 0;
    this->defense = 5;
    this->attaque = 0;
       this->generatePosition();


           string description[4] = {
            "On dirait l\'armure des gens de ton peuple... Mais c\'est deja ca !",
            "Ca pese super lourd ! Pourquoi on garde cette chose encombrante ?!",
            "Je pourrais la teindre en violet, ca irais bien avec mes chaussettes ! ",
            "Et pourquoi pas le decouper pour faire un masque ?"};
        int alea = rand() % 4;
    this->description = description[alea];
}



Arme::Arme()
{
    //ctor
}



Baton::Baton()
{
    this->nom = "Baton";
    this->vie = 0;
    this->defense = 0;
    this->attaque = 1;
       this->generatePosition();


               string description[4] = {
            "C\'est un baton... Que veux-tu que je te dise ?",
            "Tu comptes vraiment tuer des monstres... Avec un BATON en BOIS ?!",
            "Ce baton pourrais me servir pour me gratter le dos ! Il est juste a la bonne longueur",
            "J\'ai soudainement envie de faire du feux.. Et meme de manger de la VIANDE"};
        int alea = rand() % 4;
    this->description = description[alea];
}

Clavier::Clavier()
{
this->nom = "Clavier";
    this->vie = 0;
    this->defense = 0;
    this->attaque = 3;
       this->generatePosition();

                    string description[4] = {
            "Une relique etrange venu du future ? Un bien etrange objet!",
            "Il y a probablement des restes de nourritures coincees dedans, avec cette drole d\'odeur",
            "Je me demande pourquoi ce bouclier en plastique a une queue paralellipipede rectange !",
            "Cette plache ne serais pas pratique pour decouper du saucisson !"};
        int alea = rand() % 4;
    this->description = description[alea];
}

Epee::Epee()
{
    this->nom= "Epee";
    this->vie = 0;
    this->defense = 0;
    this->attaque = 5;
       this->generatePosition();
                     string description[4] = {
            "Enfin une vrais arme dans ce jeu ! c'est pas trop tot !",
            "La lame n\'est pas bien aiguisee mais ca devrais suffir pour reconquerir la princesse",
            "Imaginer qu\'un forgeron y a passé des heures pour que ca finisse rouillé au milieu d\'une tour",
            "Pourquoi la lame n'est pas aussi jolie comme dans les histoires pour enfants ?"};
        int alea = rand() % 4;
    this->description = description[alea];
}
