#include "Room.h"
#include "Monster.h"
#include "Item.h"
#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;
using std::vector;


Room::Room(int etage,Player joueur)
{
    this->etage = etage;
    this->joueur = joueur;

    for(int i=0; i<3; i++)
    {
        Monster* zombie = new Monster();
        this->mobs.push_back(zombie);
    }

    for(int i=0; i<3; i++)
    {
        Item* crystal = new Item();
        this->loots.push_back(crystal);
    }


}

Room::~Room()
{
    //dtor
}


void Room::monstre_attaque(){
    int m;
    for(m=0; m<this->mobs.size(); m++)
    {
        cout << " Le monstre "<< this->mobs[m]->nom
             <<" vous inflige " << this->mobs[m]->atk << " points de degats avec l'attaque"
             << this->mobs[m]->atk_nom << " !\n";

        this->joueur.pv -= this->mobs[m]->atk;
    }
}




int Room::menu()
{
    cout << "[etage "<< this->etage <<"] ";
    cout << "[vie:"<<this->joueur.pv<<"]\n\n";


    bool etage_clear=false;
     int ext_choice = this->mobs.size()+this->loots.size();
    int choix = 0;
    int m;
    int i;
    for(m=0; m<this->mobs.size(); m++)
    {
        cout << m+1 <<" : monstre = "<< this->mobs[m]->nom
             <<"  //" << this->mobs[m]->pv << " pv/"
             << this->mobs[m]->atk << " atk// \n";
    }
    for(i=0; i<this->loots.size(); i++)
    {
        cout << m+i+1 <<" : loot = "<< this->loots[i]->nom  <<" \n";
    }
    cout << i+m+1+1 << " : inventaire\n" ;
    cout << i+m+1+2 << " : retour base\n" ;
    if(ext_choice==0)
    {
        etage_clear = true;
        cout << i+m+1+3 << " : etage suivant\n" ;
    }
    cout << ">" ;
    cin >> choix;
    choix--;




    int loot_choice = -1;
    int mob_choice = -1;

    if(choix< this->mobs.size())
    {
        mob_choice = choix;
    }
    else if(choix<= this->mobs.size()+ this->loots.size())
    {
        loot_choice = choix - this->mobs.size();
    }


/*
        DEBUGAGE
    cout << "mob = "<< mob_choice<< endl;
    cout << "loot = "<< loot_choice<< endl;
    cout << "ext = "<<ext_choice << endl;
    cout << "choix = "<<  choix<< endl;
*/


    if(mob_choice!= -1 )
    {
        this->mobs[mob_choice]->degat(this->joueur.attaque);
        if(this->mobs[mob_choice]->pv<=0)
        {
            cout << this->mobs[mob_choice]->nom<< " est mort\n";
            this->mobs.erase(mobs.begin()+(mob_choice-1));
        }
    }
    else if(loot_choice!= -1)
    {
        this->joueur.recupper(this->loots[loot_choice]);
        cout << this->loots[loot_choice]->nom<< " a ete recuperer\n";
        this->loots.erase(loots.begin()+(loot_choice));
    }
    else if(choix== ext_choice+1) {cout << "L'inventaire n'a pas encore ete implementer\n";}
    else if(choix== ext_choice+2) {return 0;}
    else if(choix== ext_choice+3 && etage_clear)
    {
        return this->etage+1;
    }
    else
    {
        cout << "\n Choix Invalide, merci de ne pas essayer de casser le jeux.\n"
        <<"Les montre vous attaque comme punition\n\n";
    }
    this->monstre_attaque();


    return this->etage;



}
















