#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu();
        virtual ~Menu();

        int menuPricipal(int selection);
        int menuJouer();
        void menuHistoire();
        void menuCredits();

        void ClearConsoleInputBuffer();

    protected:

    private:



};

#endif // MENU_H
