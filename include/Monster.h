#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include "Item.h"
#include "vector"

using std::vector;
using namespace std;


class Monster
{
public:
    Monster();
    virtual ~Monster();


    virtual void setNom(string val);
    virtual void setVie(int val);
    virtual void setDefense(int val);
    virtual void setAttaque(int val);

    virtual string getNom();
    virtual string getAttaqueNom();
    virtual int getVie();
    virtual int getDefense();
    virtual int getAttaque();
    virtual void degat(int force);
    float getVie_Max();

protected:   //héritage wsh
    string nom= "Monstre Generic";
    int vie = 10;
    int defense = 0;
    float vie_max=10;
    int attaque= 3;
    string atk_nom = "attaque basic";
private:

};




class Zombie : public Monster
{
public:
    Zombie();

};


class Chat : public Monster
{
public:
    Chat();

};

class ChauveSouris : public Monster
{
public:
    ChauveSouris();

};

class Hydre : public Monster
{
public:
    Hydre();

};

class Chmod777 : public Monster
{
public:
    Chmod777();

};

class Dracula : public Monster
{
public:
    Dracula();


};

class Vegan : public Monster
{
public:
    Vegan();

};





class Player : public Monster
{
public:
    Player();
    virtual ~Player();
    virtual void recupper(Item* item);
    int vie = 1000;

private:
     vector<Item*> inventaire;

};








#endif // MONSTER_H
