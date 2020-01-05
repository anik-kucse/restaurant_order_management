#include "SingleOrder.h"
#include <iostream>

SingleOrder::SingleOrder(){}

SingleOrder::SingleOrder( Food & food, int quantity)
{
    this->food = food;
    this->quantity = quantity;
}

Food SingleOrder::getFood()
{
    return food;
}
void SingleOrder::setFood(Food & food)
{
    this->food = food;
}

int SingleOrder::getQuantity()
{
    return quantity;
}
void SingleOrder::setQuantity(int i)
{
    quantity = i;
}

void SingleOrder::increaseItem (int i)
{
    quantity += i;
}
void SingleOrder::decreaseItem(int i)
{
    quantity -= i;
}SingleOrder::


SingleOrder::~SingleOrder()
{
    std::cout  << "Single order Destroyed\n";
}
