#ifndef SINGLEORDER_H
#define SINGLEORDER_H
#include <Food.h>

class SingleOrder
{
    public:
        SingleOrder();
        SingleOrder(Food & food, int quantity);

        Food getFood();
        void setFood(Food & food);

        int getQuantity();
        void setQuantity(int i);


        void increaseItem (int i);
        void decreaseItem(int i);

        ~SingleOrder();

    protected:

    private:
        Food food;
        int quantity;
};

#endif // SINGLEORDER_H
