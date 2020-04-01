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

    protected:

    private:



};

#endif // MENU_H
