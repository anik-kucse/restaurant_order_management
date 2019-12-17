#include "SingleOrder.h"
#include <iostream>

SingleOrder::SingleOrder(){}

SingleOrder::SingleOrder(int id, Food food, int quantity)
{
    this->singleOrderId = id;
    this->food = food;
    this->quantity = quantity;
}

int SingleOrder::getId()
{
    return singleOrderId;
}
void SingleOrder::setId(int id)
{
    singleOrderId = id;
}

Food SingleOrder::getFood()
{
    return food;
}
void SingleOrder::setFood()
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
    std::cout << getId() << " Destroyed\n";
}
