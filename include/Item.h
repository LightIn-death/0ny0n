#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;


class Item{


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

class Potion : public Item{
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

class Armure : public Item{
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

class Chemise : public Armure{
    public:
        Chemise();
        virtual ~Chemise();

    protected:
        string nom = "Chemise";
        int defense = 1;
    private:

};

class Kevlar : public Armure{
    public:
        Kevlar();
        virtual ~Kevlar();

    protected:
        string nom = "Armure";
        int defense = 3;
    private:

};

class Cuirasse : public Armure{
    public:
        Cuirasse();
        virtual ~Cuirasse();

    protected:
        string nom = "Cuirasse";
        int defense = 5;
    private:

};


class Arme : public Item{
    public:
        Arme();
        virtual ~Arme();

    protected:
        string nom;
        int vie = 0;
        int defense = 0;
        int attaque;
    private:

};

class Baton : public Arme{
    public:
        Baton();
        virtual ~Baton();

    protected:

    private:
        string nom = "Baton";
        int attaque = 1;
};

class Clavier : public Arme{
    public:
        Clavier();
        virtual ~Clavier();

    protected:

    private:
        string nom = "Clavier";
        int attaque = 3;
};

class Epee : public Arme{
    public:
        Epee();
        virtual ~Epee();


    protected:

    private:

        string nom = "Epee";
        int attaque = 5;
};

#endif // MONSTER_H

