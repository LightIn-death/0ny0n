#ifndef MONSTER_H
#define MONSTER_H


class Monster{
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

class Player : public Monster{
    public:
        Player();
        virtual ~Player();

    protected:
        string nom = "Prince";
        int vie = 10;
        int defense = 10;
        int attaque = 1;
    private:

};

class Zombie : public Monster{
    public:
        Zombie();
        virtual ~Zombie();

    protected:

    private:
        string nom = "Zombie";
        int vie = 10;
        int defense = 1;
        int attaque = 1;
};




#endif // MONSTER_H
