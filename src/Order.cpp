#include "Order.h"
#include <string>
#include <iostream>
#include <SingleOrder.h>

Order::Order()
{
    //ctor
}

Order::Order(int orderNumber, std::string name)
{
    this->orderNumber = orderNumber;
    this->customerName = name;
}

void Order::setOrderNumber(int orderNumber)
{
    this->orderNumber = orderNumber;
}

int Order::getOrderNumber()
{
    return this->orderNumber;
}

void Order::setName(std::string name)
{
    this->customerName = name;
}

std::string Order::getName()
{
    return this->customerName;
}

void Order::addOrder(SingleOrder order)
{
    this->orderList[this->getSize()] = order;
    this->size++;
}

void Order::removeOrder(int position)
{
    for(int i = position; i < this->getSize(); i++)
    {
        this->orderList[i] = this->orderList[i + 1];
    }
}

int Order::getSize()
{
    return this->size;
}


Order::~Order()
{
    //dtor
}
