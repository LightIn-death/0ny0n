#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu();
        virtual ~Menu();

        int menuPricipal();
        int menuJouer();
        void menuHistoire();
        void menuCredits();
        int menuPause();
        void ClearConsoleInputBuffer();
        void Color(int color, int color2);

    protected:

    private:



};

#endif // MENU_H
