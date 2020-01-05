#ifndef ORDER_H
#define ORDER_H
#include <SingleOrder.h>
#include <string>

class Order
{
    public:
        SingleOrder orderList[1000];

        Order();

        Order(int orderNumber, std::string name);

        void setOrderNumber(int orderNumber);
        int getOrderNumber();

        void setName(std::string name);
        std::string getName();

        void addOrder(SingleOrder order);
        void removeOrder(int position);

        int getSize();

        ~Order();

    protected:

    private:
        int orderNumber;
        int size;
        std::string customerName;

};

#endif // ORDER_H
