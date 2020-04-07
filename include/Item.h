#ifndef ITEM_H
#define ITEM_H


class Item{
    public:
        Monster();
        virtual ~Monster();

        void setNom(string val);
        void setVie(int val);
        void setDefense(int val);
        void setAttaque(int val);

        string getNom();
        int getVie();
        int getDefense();
        int getAttaque();

    protected:   //héritage wsh
        string nom;
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
        int defense = 5;
        int attaque = 0;
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
