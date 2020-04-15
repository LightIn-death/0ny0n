#include "Room.h"
#include "Monster.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <ctime>

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

void Room::base(Player* joueur)
{
    bool running = true;
    while(running)
    {
        char key_press;
        int ascii_value = 0;
        int choix = 1;
        while(ascii_value != 13){
            system("cls");
            int i = 1;
              cout << "vous avez actuellement ";
              this->Color(6,0);
              cout << joueur->Or;
              this->Color(7,0);
              cout << " pieces d'or ! \n\n\n";
            if(joueur->Or >= 50)
            {
                if (choix == i){
                    cout << "[X] ";
                }else{
                    cout << "[ ] ";
                }
                cout << " Vous pouvez augmenter votre vie de 50 PV " << endl;
                i++;
            }
            else
            {
                this->Color(4,0);
                cout <<"Vous n\'avez pas assez d'argent !" << endl;
                this->Color(7,0);
            }

            if (choix == i){
                    cout << "[X] ";
                }else{
                    cout << "[ ] ";
                }
            cout << " Retourné combattre dans la tours." << endl << endl << endl;

            key_press=_getch();
            ascii_value=key_press;

            if(ascii_value==72){
                //std::cin.clear();
                choix -= 1;
                if (choix < 1){
                    choix = i;
                }
            }else if(ascii_value==80){

                choix += 1;
                if (choix > i){
                    choix = 1;
                }
            }

        }

            if(joueur->Or >= 50 && choix == 1)
            {
                cout <<" Vous avez ajoute"
                this->Color(2,0);
                cout << "50";
                this->Color(7,0);
                cout << "pv !" << endl;
                joueur->setVie_Max(50);
                joueur->Or-=50;
            }
            else
            {
                cout << " Preparez-vous au combat !" << endl;
                running = false;
            }
            _getch();
    }
}


void Room::monstre_attaque()
{
    int m;
    for(m=0; m<this->mobs.size(); m++)
    {
        int vie_afficher = 0;
        if ((this->mobs[m]->getAttaque() - this->joueur->getDefense()) > 0){
            vie_afficher = (this->mobs[m]->getAttaque() - this->joueur->getDefense());
        }else{
            vie_afficher = 0;
        }

        this->joueur->vie -=  vie_afficher;

        cout <<" Le monstre ";
        this->Color(8,0);
        cout << this->mobs[m]->getNom();
        this->Color(7,0);
        cout <<" vous attaque avec ";
        this->Color(12,0);
        cout << this->mobs[m]->getAttaqueNom();
        this->Color(7,0);
        cout <<" et vous inflige ";
        this->Color(4,0);
        cout << vie_afficher;
        this->Color(7,0);
        cout << " points de degats ";

        if (vie_afficher == 0){
            cout << "grace a votre defense de fer ";
        }
        cout << "! " << endl;
    }
}

void Room::persoStats()
{
    system("cls");
    cout << "Prince ";
    this->Color(13,0);
    cout << this->joueur->getNom() << endl;
    this->Color(7,0);
    cout << "[Etage]   : ";
    this->Color(3,0);
    cout << this->etage << endl;
    this->Color(7,0);
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
    this->Color(7,0);
    cout << " / ";
    this->Color(2,0);
    cout << vie;
    this->Color(7,0);
    cout << "" << endl;
    cout << "[Attaque] : ";
    this->Color(4,0);
    cout << this->joueur->getAttaque() << endl;
    this->Color(7,0);
    cout << "[Defense] : ";
    this->Color(14,0);
    cout << this->joueur->getDefense() << endl;
    this->Color(7,0);
    cout << "[Coins]   : ";
    this->Color(6,0);
    cout << this->joueur->Or << endl;
    this->Color(7,0);
}

int Room::menu()
{

    bool etage_clear=false;
    bool invotory=false;
    int ext_choice = this->mobs.size()+this->loots.size();
    int choix = 1;
    int m;
    int i;

    char key_press;
    int ascii_value = 0;

    while(ascii_value != 13){
        this->persoStats();
        this->dessinerAscii();
        this->AsciiArtMonster();

        cout << endl << endl;
        this->Color(7,0);




        for(m=0; m<this->mobs.size(); m++)
        {

            if (choix == m+1){
                cout << "[X] ";
            }else{
                cout << "[ ] ";
            }

            this->Color(8,0);
            cout << "{M} " << this->mobs[m]->getNom();
            this->Color(7,0);
            cout << " | ";
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
            cout << " | ATK : ";
            this->Color(4,0);
            cout << this->mobs[m]->getAttaque() << endl;
            this->Color(7,0);

        }
        for(i=0; i<this->loots.size(); i++)
        {
            if (choix == m+i+1){
                cout << "[X] ";
            }else{
                cout << "[ ] ";
            }
            this->Color(11,0);
            cout << "{0} " << this->loots[i]->getNom();
            this->Color(7,0);
            cout <<" "<< this->loots[i]->getPosition() << endl;
        }

        int a = this->loots.size();


        if (choix == m+i+1){
                cout << "[X] ";
            }else{
                cout << "[ ] ";
            }
        cout << "Inventaire" << endl;

        if (choix == i+m+2){
                cout << "[X] ";
            }else{
                cout << "[ ] ";
            }
        cout << "Retour a la base" << endl;

        if(this->mobs.empty())
        {
            etage_clear = true;
            if (choix == m+i+3){
                cout << "[X] ";
            }else{
                cout << "[ ] ";
            }
            cout << "Etage suivant" << endl;
        }

        if (etage_clear == true){
            if (choix == m+i+4){
                cout << "[X] ";
            }else{
                cout << "[ ] ";
            }
            cout << "Quitter " << endl;
        }else if(etage_clear == false) {
            if (choix == m+i+3){
                cout << "[X] ";
            }else{
                cout << "[ ] ";
            }
            cout << "Quitter " << endl;
        }

        std::cin.clear();

        key_press=_getch();
        ascii_value=key_press;

        if(ascii_value==72){
            //std::cin.clear();
            choix -= 1;
            if (choix < 1 && etage_clear == false){
                choix = m+i+3;
            }else if (choix < 1 && etage_clear == true){
                choix = m+i+4;
            }
        }else if(ascii_value==80){

            choix += 1;
            if (choix > m+i+3 && etage_clear == false){
                choix = 1;
            }else if (choix > m+i+4 && etage_clear == true){
                choix = 1;
            }
        }
        //std::cin.clear();

    }

    //cin >> choix;

    //PlaySound(TEXT("item.wav"),NULL,SND_ASYNC);
    choix -= 1;

    int loot_choice = -1;
    int mob_choice = -1;

    if(choix < this->mobs.size())
    {
        mob_choice = choix;
    }

    else if(choix < this->mobs.size() + this->loots.size())

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
            this->Color(8,0);
            cout << this->mobs[mob_choice]->getNom();
            this->Color(4,0);
            cout << " est mort\n";
            this->Color(7,0);

            this->mobs.erase(mobs.begin()+(mob_choice));
            int money = ( rand() % 11 ) +1;
            this->joueur->Or += money;
                 cout << "Vous avez gagne ";
                 this->Color(6,0);
                 cout << money;
                 this->Color(7,0);
                 cout <<" pieces d\'Or !\n";
                 _getch();
        }
    }
    else if(loot_choice!= -1)
    {
        this->joueur->recupper(this->loots[loot_choice]);
        this->Color(11,0);
        cout << this->loots[loot_choice]->getNom();
        this->Color(7,0);
        cout << " a ete recuperer\n";
        this->loots.erase(loots.begin()+(loot_choice));
        _getch();
    }
    else if(choix== ext_choice)
    {
        invotory=true;

        while (this->inventaire()){}

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
    else if ((choix == ext_choice+2) || (choix == ext_choice+3) ){
        return 15;
    }
    else
    {
        cout << endl <<" Choix Invalide, merci de ne pas essayer de casser le jeux.";
        cout << endl <<"Les montre vous attaquent comme punition" << endl << endl;
        _getch();
    }
    if(!invotory && this->mobs.size()!=0)
    {
        this->monstre_attaque();
             _getch();
    }
    if(this->joueur->vie<=0)
    {
        this->Color(4,0);
        cout << endl << "vous etes mort" << endl;
        this->Color(7,0);
        Sleep(2000);
        return 0;
    }

    return this->etage;
}

int Room::inventaire()
{

    int choix = 1;

    char key_press;
    int ascii_value = 0;
    while(ascii_value != 13){

        system("cls");
        int i = 0;
        this->persoStats();

        cout << endl;
        for(; i<this->joueur->inventaire.size(); i++)
        {

             if (choix == i+1){
                cout << "[X] ";
            }else{
                cout << "[ ] ";
            }

            /*for(int e=0; e<this->joueur->inventaire[i]->getNom().size(); e++)
            {
                cout << "_";
            }

*/
            cout <<" |";
            this->Color(11,0);
            cout << this->joueur->inventaire[i]->getNom();
            this->Color(7,0);
            //
            // Ataque ? Defance ? Vie ?
            if(this->joueur->inventaire[i]->getAttaque() > 0)
            {
                cout << "| Attaque + ";
                this->Color(4,0);
                cout << this->joueur->inventaire[i]->getAttaque();
                this->Color(7,0);
                cout << "|";
            }
            if(this->joueur->inventaire[i]->getDefense() > 0)
            {
                cout << "| Defense + ";
                this->Color(14,0);
                cout << this->joueur->inventaire[i]->getDefense();
                this->Color(7,0);
                cout << "|";
            }
            if(this->joueur->inventaire[i]->getVie() > 0)
            {
                cout << "| Vie + ";
                this->Color(2,0);
                cout << this->joueur->inventaire[i]->getVie() <<" %";
                this->Color(7,0);
                cout << "|";
            }
            cout << " {  "<<this->joueur->inventaire[i]->getDesciption()<<"  }" << endl;
            //
            //
            //cout << endl <<"    ";

            /*for(int e=0; e<this->joueur->inventaire[i]->getNom().size(); e++)
            {
                cout << "¯";
            }
            */
        }
        if (choix == i+1){
                cout << "[X] ";
            }else{
                cout << "[ ] ";
            }

        cout << " Retour" << endl;


        std::cin.clear();

        key_press=_getch();
        ascii_value=key_press;

        if(ascii_value==72){
            //std::cin.clear();
            choix -= 1;
            if (choix < 1){
                choix = i+1;
            }
        }else if(ascii_value==80){
            choix += 1;
            if (choix > i+1){
                choix = 1;
            }
        }
        std::cin.clear();
    }



    choix -= 1;

    if (choix < this->joueur->inventaire.size())
    {
        this->joueur->setAttaque((this->joueur->getAttaque())+(this->joueur->inventaire[choix]->getAttaque()));
        this->joueur->setDefense((this->joueur->getDefense())+(this->joueur->inventaire[choix]->getDefense()));
        this->joueur->soigner((this->joueur->inventaire[choix]->getVie()));

        this->joueur->inventaire.erase((this->joueur->inventaire.begin()) + (choix));
        return 1;
    }else{
        return 0;
    }

    //_getch();




}

void Room::dessinerAscii()
{
this->Color(13,6);
    cout << endl;
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
        int x = (rand() % 20)+2;
        int y = (rand() % 8)+8;
        COORD p = { x, y };
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
        cout <<"M";

    }
    for(int i=0; i<this->loots.size(); i++)
    {
        int x = (rand() % 20)+2;
        int y = (rand() % 8)+8;
        COORD p = { x, y };
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
        cout <<"O";
    }


    COORD p = { 0, 19 };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
}


void Room::AsciiArtMonster()
{


string Art[20] = {   "               "
                    ,"\\()7L/ "
                    ,"  cgD                            __ _ "
                    ,"  |\\(                          .'  Y '>, "
                    ,"   \\ \\                        / _   _   \\"
                    ,"    \\\\\                       )(_) (_)(|} "
                    ,"     \\\\\\                      {  4A   } / "
                    ,"      \\\\\\                      \\uLuJJ/\\l "
                    ,"       \\\\\\                     |3    p)/ "
                    ,"        \\\\\\___ __________      /nnm_n// "
                    ,"         c7___-__,__-)\\,__)(_.  \\_>-<_/D "
                    ,"               //V     \\__-._.__G G_c__.-__<_/ ( \\"
                    ,"                           <_-._>__-,G_.___)\\   \\7\\ "
                    ,"                          (_^-.__.| \\_<.__.-_ )   \\ \\ "
                    ,"                          |-.__^\\  |^-.__.-^.\\   \\ \\ "
                    ,"                          (^-.__^^. \\^-.__.-^.|    \\_\\"
                    ,"                          \\^-.__^^|!|^-.__.-^.)     \\ \\"
                    ,"                           ^-.__^^\\_|^-.__.-Ã§./      \\ l"
                    ,"                           ^.__^^^>G>-.__.-^>       .--,_ "
                    ,"                                                          "};









                                            this->Color(11,0);
           for(int j = 0; j < 20 ; j++)

{
 COORD p = { 45, 0 + j }; // 25 19
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );



    cout << Art[j] << endl;

           }





    COORD p = { 0, 19 };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
}


