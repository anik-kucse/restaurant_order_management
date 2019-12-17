#ifndef SUBMENU_H
#define SUBMENU_H
#include <Menu.h>
#include <string>

class SubMenu: public Menu
{
    public:
        SubMenu();
        SubMenu(std::string submenu, std::string menu);
        ~SubMenu();
        std::string getSubMenutype();
        void setSubMenuType(std::string type);

    protected:
        std::string subMenuType;

    private:

};

#endif // SUBMENU_H
