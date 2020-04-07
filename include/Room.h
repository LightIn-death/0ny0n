#ifndef ROOM_H
#define ROOM_H


class Room
{
    public:
        Room(int etage);
        virtual ~Room();

        int menu();





    protected:

    private:
        int etage;
};

#endif // ROOM_H
