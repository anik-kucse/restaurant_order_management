#ifndef ORDER_H
#define ORDER_H
#include <SingleOrder.h>
#include <string>

class Order
{
    public:
        static int orderNumber;
        Order();
        ~Order();

    protected:

    private:
        int id;
        std::string customerName;
        SingleOrder orderList[1000];
};

#endif // ORDER_H
