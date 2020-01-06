#include "Food.h"
#include <string>
#include <iostream>

Food::Food(){}

Food::Food(std::string foodName, int price, int quantity, std::string subMenu, std::string menu)
: SubMenu (subMenu, menu)
{
    this->name = foodName;
    this->price = price;
    this->quantity = quantity;
}

std::string Food::getName()
{
    return name;
}

void Food::setName(std::string foodName)
{
    name = foodName;
}

int Food::getPrice()
{
    return price;
}

void Food::setPrice(int foodPrice)
{
    price = foodPrice;
}

int Food::getQuantity()
{
    return quantity;
}

void Food::setQunatity(int foodQuantity)
{
    quantity = foodQuantity;
}


Food::~Food()
{
//    std::cout << getName() << " destroyed\n";
}
