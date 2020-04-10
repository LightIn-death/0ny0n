#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

class Item // ||||||||||||||||||||||||
{
public:
    Item();
    virtual ~Item();

    virtual void setNom(string val);
    virtual void setVie(int val);
    virtual void setDefense(int val);
    virtual void setAttaque(int val);

    virtual string getNom();
    virtual string getPosition();
    virtual string getDesciption();
    virtual int getVie();
    virtual int getDefense();
    virtual int getAttaque();
    virtual void generatePosition();


protected:   //héritage wsh
    string nom="Item de base";
    string position="position de base";
    string description="description de base";
    int vie=0;
    int defense=0;
    int attaque=0;


};

class Potion : public Item // ||||||||||||||||||||||||
{
public:
    Potion();
};

class Armure : public Item // ||||||||||||||||||||||||
{
public:
    Armure();
};

class Chemise : public Armure
{
public:
    Chemise();
};

class Kevlar : public Armure
{
public:
    Kevlar();
};

class Cuirasse : public Armure
{
public:
    Cuirasse();
};

class Arme : public Item // ||||||||||||||||||||||||
{
public:
    Arme();
};

class Baton : public Arme
{
public:
    Baton();
};

class Clavier : public Arme
{
public:
    Clavier();
};

class Epee : public Arme
{
public:
    Epee();
};

#endif // MONSTER_H

