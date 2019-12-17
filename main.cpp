#include <iostream>
#include <Food.h>
#include <string>

using namespace std;

int main()
{
    Food ojb("Rice", 100, 1, "Meal", "Break fast");

    cout << ojb.getMenuType() << endl;

    return 0;
}
