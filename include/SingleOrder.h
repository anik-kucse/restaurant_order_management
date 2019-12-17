#ifndef SINGLEORDER_H
#define SINGLEORDER_H
#include <Food.h>

class SingleOrder
{
    public:
        SingleOrder();
        SingleOrder(int id, Food food, int quantity);

        int getId();
        void setId(int id);

        Food getFood();
        void setFood();

        int getQuantity();
        void setQuantity(int i);


        void increaseItem (int i);
        void decreaseItem(int i);

        ~SingleOrder();

    protected:

    private:
        int singleOrderId;
        Food food;
        int quantity;
};

#endif // SINGLEORDER_H
