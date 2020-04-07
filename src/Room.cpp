#include "Room.h"
#include "Monster.h"
#include "Item.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;
using std::vector;


Room::Room(int etage,Player joueur)
{
    srand (time(NULL));
    this->etage = etage;
    this->joueur = joueur;

    //(rand() % (2+etage) + 1)


    for(int i=0; i<(rand() % (2+etage) + 1); i++)
    {
        int alea = (rand() % (etage)+1);
        Monster* monstre;

        if(alea>40)
        {
            monstre = new Chmod777();
        }
        else if(alea>30)
        {
            monstre = new Hydre();
        }
        else if(alea>20)
        {
            monstre = new Dracula();
        }
        else if(alea>15)
        {
            monstre = new Vegan();
        }
        else if(alea>10)
        {
            monstre = new Zombie();
        }
        else if(alea>5)
        {
            monstre = new ChauveSouris();
        }
        else
        {
            monstre = new Chat();
        }


        this->mobs.push_back(monstre);
    }

    for(int i=0; i<(rand() % (etage) ); i++)
    {
        Item* crystal = new Item();
        this->loots.push_back(crystal);
    }

}

//###########################################################################################
//###########################################################################################
//###########################################################################################
//###########################################################################################
//###########################################################################################


Room::~Room()
{
    //dtor
}

void Room::Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void Room::monstre_attaque()
{
    int m;
    for(m=0; m<this->mobs.size(); m++)
    {
        cout << " Le monstre "<< this->mobs[m]->getNom()
             <<" vous inflige " << this->mobs[m]->getAttaque() << " points de degats avec l'attaque"
             << this->mobs[m]->getAttaqueNom() << " !\n";

        this->joueur.vie -= this->mobs[m]->getAttaque();
    }
}



int Room::menu()
{


    system("cls");
    cout << "[etage "<< this->etage <<"] ";
    cout << "[vie:";

    float vie = this->joueur.getVie_Max();

    if (this->joueur.vie <= (vie*0.2))
    {

        this->Color(4,0);
        cout << this->joueur.vie;
        this->Color(7,0);
    }
    else if (this->joueur.vie <= (vie*0.4))
    {
        this->Color(6,0);
        cout << this->joueur.vie;

        this->Color(7,0);
    }
    else
    {
        this->Color(2,0);
        cout << this->joueur.vie;
        this->Color(7,0);
    }


    cout << "]\n\n";


    bool etage_clear=false;
    bool invotory=false;
    int ext_choice = this->mobs.size()+this->loots.size();
    int choix = 0;
    int m;
    int i;
    for(m=0; m<this->mobs.size(); m++)
    {

        cout << m+1 <<" : monstre = "<< this->mobs[m]->getNom() <<"  //";
        if (this->mobs[m]->getVie() <= (this->mobs[m]->getVie_Max()*0.2))
        {

            this->Color(4,0);
            cout << this->mobs[m]->getVie();
            this->Color(7,0);
        }

        else if (this->mobs[m]->getVie() <= (this->mobs[m]->getVie_Max()*0.4))
        {
            this->Color(6,0);
            cout << this->mobs[m]->getVie();
            this->Color(7,0);
        }

        else
        {
            this->Color(2,0);
            cout << this->mobs[m]->getVie();
            this->Color(7,0);
        }
        cout << " pv/" << this->mobs[m]->getAttaque() << " atk// \n";
    }
    for(i=0; i<this->loots.size(); i++)
    {
        cout << m+i+1 <<" : loot = "<< this->loots[i]->getNom()  <<" \n";
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

    if(choix < this->mobs.size())
    {
        mob_choice = choix;
    }

    else if(choix < this->mobs.size()+ this->loots.size())

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


    if(mob_choice!= -1)
    {
        this->mobs[mob_choice]->degat(this->joueur.getAttaque());
        if(this->mobs[mob_choice]->getVie()<=0)
        {
            cout << this->mobs[mob_choice]->getNom()<< " est mort\n";
            this->mobs.erase(mobs.begin()+(mob_choice));
        }
    }
    else if(loot_choice!= -1)
    {
        this->joueur.recupper(this->loots[loot_choice]);
        cout << this->loots[loot_choice]->getNom()<< " a ete recuperer\n";
        this->loots.erase(loots.begin()+(loot_choice));
    }
    else if(choix== ext_choice+1)
    {
        invotory=true;
        cout << "L'inventaire n'a pas encore ete implementer\n";
    }
    else if(choix== ext_choice+2)
    {
        return 0;
    }
    else if(choix== ext_choice+3 && etage_clear)
    {
        return this->etage+1;
    }
    else
    {
        cout << "\n Choix Invalide, merci de ne pas essayer de casser le jeux.\n"
             <<"Les montre vous attaquent comme punition\n\n";
    }
    if(!invotory)
    {
        this->monstre_attaque();
    }
    if(this->joueur.vie<=0)
    {
        cout << "vous etes mort";
        _getch();
        return 0;
    }

    _getch();
    return this->etage;




}
















