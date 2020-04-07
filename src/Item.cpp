#include "Item.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <time.h>

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



          string position[17] = {"est posé sur le sol","est posé contre le mur","est accrocher au plafond","est sur un vieux cadavre","est fixer a la porte"
        ,"depasse d\'un troue dans le sol","est dans un vieux coffre au centre de la piece","est cacher dans un creux du mur","se sent seul dans un coin"
        ,"est a coter de toi","te regarder bizarement","traine dans la poussiere","est recuperable","ne peut pas se manger","a un coter retro"
        ,"t'irais bien","te passionne"};
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
            "A laire etrange et permimer, je ne boirais pas ca si j\'etais toi",
            "Un liquide visqueux rougeatre se trouve dans une fiole en verre",
            "le bouchons semble perdu depuis longtemps... je ne sais pas depuis combiens de temps c\'est ouvert !",
            "Si je la bois, la princesse te trouvera peut etre plus mignon"};
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
            "Une bien etrange chemise retrouver a coter d'un cadavre, il manque juste les lunette de soleil",
            "Cette chemise est facinante tant elle est belle.. tu pourrais oublier la princesse",
            "Il y a peut etre des poches pour mettre des sous dans cette chemise ?",
            "Il semble manquer un bouton ! On peux presque voir ton torse royal."};
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
            "Tu savais que le kevelar s\'inspire des toiles d\'arraigner ? ca donne moins envie...",
            "Un gilet par balle ?! Pour quoi faire ? les monstre n\'on pas de balles !",
            "Tu pense que la princesse aimera le style que ca te procure ?"};
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
            "On dirait l\'armure des gens de ton peuple... Mais c\'est deja ça !",
            "Ca pese super lourd ! pourquoi on garde cette chose encombrante ?!",
            "Je pourrais la teindre en violet, ca irais avec mes chaussettes ! ",
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
            "C\'est un baton... Que veut tu que je te dise ?",
            "Tu compte vraiment tuer des monstres... Avec un BATON en BOIS ?!",
            "Ce baton pourais me servir pour me gratter le dos ! il est juste a la bonne longueur",
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
            "Une relique etrange venu du future ? Bien etrange objet!",
            "Il y a probablement des restes de nouriture coincer dedans, car il y a une drole d\'odeur",
            "je me demande pourquois ce bouclier en plastique a une queue paralellipipede rectange !",
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
            "Enfin une vrais Arme dans ce jeu ! c'est pas trop tot !",
            "La lame n\'est pas bien aiguise mais ca devrais suffir pour reconquerir la princesse",
            "Imaginer qu\'un forgeron y a passer des heures pour que ca finisse rouiller au millieux d\'une tour",
            "Pourquoi la lame n'est pas aussi jolie quand dans les histoire pour enfants ?"};
        int alea = rand() % 4;
    this->description = description[alea];
}
