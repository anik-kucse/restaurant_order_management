#ifndef FOOD_H
#define FOOD_H
#include <SubMenu.h>
#include <string>

class Food: public SubMenu
{
    public:
        Food();
        Food(std::string foodName, int price, int quantity, std::string subMenu, std::string menu);
        ~Food();

        std::string getName();
        void setName(std::string foodName);

        int getPrice();
        void setPrice(int foodPrice);

        int getQuantity();
        void setQunatity(int foodQuantity);

    protected:

    private:
        std::string name;
        int price;
        int quantity;
};

#endif // FOOD_H
