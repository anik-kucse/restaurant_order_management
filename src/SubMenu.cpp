#include "SubMenu.h"
#include <string>
#include <iostream>

SubMenu::SubMenu(){}

SubMenu::SubMenu(std::string submenu, std::string menu) : Menu(menu)
{
    subMenuType = submenu;
}

std::string SubMenu::getSubMenutype()
{
    return subMenuType;
}

void SubMenu::setSubMenuType(std::string type)
{
    subMenuType = type;
}

SubMenu::~SubMenu()
{
//    std::cout << getSubMenutype() << " destroyed\n";
}
