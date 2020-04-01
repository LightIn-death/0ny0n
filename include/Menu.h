#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu();
        virtual ~Menu();

        void menuPricipal();
        void menuJouer();
        void menuHistoire();
        void menuCredits();

        void ClearConsoleInputBuffer();
        void Color(int color, int color2);

    protected:

    private:



};

#endif // MENU_H
