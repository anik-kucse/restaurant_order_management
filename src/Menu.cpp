#include "Menu.h"
#include <string>
#include <iostream>
Menu::Menu(){}

Menu::Menu(std::string menu)
{
    menuType = menu;
}

std::string Menu::getMenuType()
{
    return menuType;
}

void Menu::setMenuTyoe(std::string type)
{
    menuType = type;
}

Menu::~Menu()
{
    std::cout << getMenuType() << " destroyed\n";
}
