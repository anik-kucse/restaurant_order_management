#include <iostream>
#include <Food.h>
#include <string>

using namespace std;

int main()
{
//     Food(std::string foodName, int price, int quantity, std::string subMenu, std::string menu)
    Food ojb("Rice", 100, 1, "Meal", "Break fast");

    cout << ojb.getMenuType() << endl;

    return 0;
}
