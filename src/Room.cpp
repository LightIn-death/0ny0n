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


Room::Room(int etage,Player* joueur)
{
    srand (time(NULL));
    this->etage = etage;
    this->joueur = joueur;

    //(rand() % (2+etage) + 1)


    for(int i=0; i<(rand() % (2+etage) + 1); i++)
    {
        int alea = (rand() % (etage)+1);
        Monster* monstre;

        if(alea>9)
        {
            monstre = new Chmod777();
        }
        else if(alea>7)
        {
            monstre = new Hydre();
        }
        else if(alea>5)
        {
            monstre = new Dracula();
        }
        else if(alea>4)
        {
            monstre = new Vegan();
        }
        else if(alea>3)
        {
            monstre = new Zombie();
        }
        else if(alea>2)
        {
            monstre = new ChauveSouris();
        }
        else
        {
            monstre = new Chat();
        }
        this->mobs.push_back(monstre);
    }

    for(int i=0; i<(rand() % (etage) +3); i++)
    {
        int alea = (rand() % 100);
        Item* item;

        if(alea<=1)
        {
            item = new Clavier();
        }
        else if(alea<=5)
        {
            item = new Chemise();
        }
        else if(alea<=10)
        {
            item = new Epee();
        }
        else if(alea<=15)
        {
            item = new Kevlar();
        }
        else if(alea<=20)
        {
            item = new Potion();
        }
        else if(alea<=30)
        {
            item = new Cuirasse();
        }
        else
        {
            item = new Baton();
        }



        this->loots.push_back(item);
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

        this->joueur->vie -= this->mobs[m]->getAttaque();
    }
}
void Room::persoStats()
{

    this->Color(3,0);
    system("cls");
    cout << "" << this->joueur->getNom() << endl;
    cout << "[etage]   : "<< this->etage << endl;
    cout << "[Vie]     : ";

    float vie = this->joueur->getVie_Max();

    if (this->joueur->vie <= (vie*0.2))
    {
        this->Color(4,0);
        cout << this->joueur->vie;
    }
    else if (this->joueur->vie <= (vie*0.4))
    {
        this->Color(6,0);
        cout << this->joueur->vie;
    }
    else
    {
        this->Color(2,0);
        cout << this->joueur->vie;
    }
    this->Color(3,0);
    cout << " / ";
    this->Color(2,0);
    cout << vie;
    this->Color(3,0);
    cout << "" << endl;
    cout << "[Attaque] : ";
    this->Color(4,0);
    cout << this->joueur->getAttaque();
    this->Color(3,0);
    cout <<" " <<  endl;
    cout << "[Defense] : " << this->joueur->getDefense() <<" \n\n";


}


int Room::menu()
{

    this->persoStats();
    this->dessinerAscii();
    this->Color(7,0);

    bool etage_clear=false;
    bool invotory=false;
    int ext_choice = this->mobs.size()+this->loots.size();
    int choix = 0;
    int m;
    int i;
    for(m=0; m<this->mobs.size(); m++)
    {

        cout << m+1 <<" : "<< this->mobs[m]->getNom() << " | ";
        cout << " PV : ";
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
        cout << " / ";
        this->Color(2,0);
        cout << this->mobs[m]->getVie_Max();
        this->Color(7,0);
        cout << " | ATK :";
        this->Color(4,0);
        cout << this->mobs[m]->getAttaque();
        this->Color(7,0);
        cout << endl;
    }
    for(i=0; i<this->loots.size(); i++)
    {
        cout << m+i+1 <<" : "<< this->loots[i]->getNom() << " "<< this->loots[i]->getPosition()<< endl;
    }

    int a = this->loots.size();
    //cout << a << endl;
//<<<<<<< HEAD
    cout << i+m+1 << " : inventaire" << endl;
    cout << i+m+2 << " : retour base" << endl;
    /*=======
        if (a == 0)
        {
            cout << i+m+1 << " : inventaire" << endl;
            cout << i+m+2 << " : retour base" << endl;
        }
        else
        {
            cout << i+m+2 << " : inventaire" << endl;
            cout << i+m+3 << " : retour base" << endl;
        }
    >>>>>>> Breval
    */
    if(this->mobs.size()==0)
    {
        etage_clear = true;
        cout << i+m+3 << " : etage suivant" << endl;
    }
    this->Color(8,0);
    cout << ">" ;

    cin >> choix;
    choix -= 1;

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
        this->mobs[mob_choice]->degat(this->joueur->getAttaque());
        if(this->mobs[mob_choice]->getVie()<=0)
        {
            cout << this->mobs[mob_choice]->getNom()<< " est mort\n";
            this->mobs.erase(mobs.begin()+(mob_choice));
        }
    }
    else if(loot_choice!= -1)
    {
        this->joueur->recupper(this->loots[loot_choice]);
        cout << this->loots[loot_choice]->getNom()<< " a ete recuperer\n";
        this->loots.erase(loots.begin()+(loot_choice));
    }
    else if(choix== ext_choice)
    {
        invotory=true;
        inventaire();
        //cout << "L'inventaire n'a pas encore ete implementer\n";
    }
    else if(choix== ext_choice+1)
    {
        return 0;
    }
    else if(choix== ext_choice+2 && etage_clear)
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
    if(this->joueur->vie<=0)
    {
        cout << "vous etes mort";
        _getch();
        return 0;
    }

    _getch();
    return this->etage;




}



void Room::inventaire()
{

    system("chcp 65001");
    system("cls");
    this->persoStats();
    this->Color(6,0);
    if(this->joueur->inventaire.size()==0)
    {
        cout << "\n\nTu n'a pas d'items dans ton inventaire\n";
    }

    int i;
    for(i=0; i<this->joueur->inventaire.size(); i++)
    {
        cout<<"    ";
        for(int e=0; e<this->joueur->inventaire[i]->getNom().size(); e++)
        {
            cout << "_";
        }
        cout << "\n "<< i+1 <<" |"<< this->joueur->inventaire[i]->getNom() << "|";
//
// Ataque ? Defance ? Vie ?
        if(this->joueur->inventaire[i]->getAttaque() > 0)
        {
            cout << "/Attaque +"<<this->joueur->inventaire[i]->getAttaque()<<"/";
        }
        if(this->joueur->inventaire[i]->getDefense() > 0)
        {
            cout << "/Defense +"<<this->joueur->inventaire[i]->getDefense()<<"/";
        }
        if(this->joueur->inventaire[i]->getVie() > 0)
        {
            cout << "/vie +"<<this->joueur->inventaire[i]->getVie()<<"/";
        }
        cout << " {  "<<this->joueur->inventaire[i]->getDesciption()<<"  }";
//
//
        cout << endl<<"    ";
        for(int e=0; e<this->joueur->inventaire[i]->getNom().size(); e++)
        {
            cout << "̅";
        }
        cout << "\n";
    }





    cout << "\n>";
    _getch();


}


void Room::dessinerAscii()
{
this->Color(13,6);
    cout << "      Etage Suivant      " << endl;
    cout << "###########[X]###########" << endl;
    cout << "#                       #" << endl;
    cout << "#                       #" << endl;
    cout << "#                       #" << endl;
    cout << "#                       #" << endl;
    cout << "#                       #" << endl;
    cout << "#                       #" << endl;
    cout << "#                       #" << endl;
    cout << "#                       #" << endl;
    cout << "#          \\o/          #" << endl;
    cout << "###########[X]###########" << endl;
    cout << "     Porte d\'entrer      " << endl;


    for(int i=0; i<this->mobs.size(); i++)
    {
        int x = (rand() % 22)+1;
        int y = (rand() % 11)+8;
        COORD p = { x, y };
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
        cout <<"M";

    }
    for(int i=0; i<this->loots.size(); i++)
    {
        int x = (rand() % 22)+1;
        int y = (rand() % 11)+8;
        COORD p = { x, y };
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
        cout <<"T";
    }


    COORD p = { 0, 19 };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
}










