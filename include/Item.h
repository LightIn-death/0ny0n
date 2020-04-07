#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

class Item
{


public:
    Item();
    virtual ~Item();

    void setNom(string val);
    void setVie(int val);
    void setDefense(int val);
    void setAttaque(int val);

    string getNom();
    int getVie();
    int getDefense();
    int getAttaque();



protected:   //héritage wsh
    string nom="Item de base";
    int vie;
    int defense;
    int attaque;
private:
};

class Potion : public Item
{
public:
    Potion();
    virtual ~Potion();

protected:

private:
    string nom = "Potion";
    int vie = 10;
    int defense = 0;
    int attaque = 0;
};

class Armure : public Item
{
public:
    Armure();
    virtual ~Armure();

protected:
    string nom = "Armure";
    int vie = 0;
    int defense;
    int attaque = 0;
private:

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


class Arme : public Item
{
public:
    Arme();
    virtual ~Arme();

protected:

private:

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

