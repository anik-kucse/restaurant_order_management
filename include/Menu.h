#ifndef MENU_H
#define MENU_H
#include <string>

class Menu
{
    public:
        Menu();
        Menu(std::string menu);
        ~Menu();
        std::string getMenuType();
        void setMenuTyoe(std::string type);

    protected:
        std::string menuType;

    private:

};

#endif // MENU_H
