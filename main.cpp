#include <iostream>
#include <Food.h>
#include <string>
#include <stdlib.h>
#include <memory>
#include <SingleOrder.h>
#include <Order.h>

using namespace std;

void clearView();
string showGreatings();
int showMainMenu();
int getSubMenuSize(int menu);
unique_ptr<SingleOrder> showSubMenu(int menu);
int showSubMenuItem(Food subMenu[], int len);
unique_ptr<SingleOrder> createSingleOrder(Food food, int quantity);

int orderNumber = 1100;
int curentStage;

Food starterList [] = {
    Food("Starter_1", 100, 1, "Starter", "Meal") ,
    Food("Starter_2", 100, 1, "Starter", "Meal"),
    Food("Starter_3", 100, 1, "Starter", "Meal")
};

Food appetizerList [] = {
    Food("Appetizer_1", 100, 1, "Appetizer", "Meal"),
    Food("Appetizer_2", 100, 1, "Appetizer", "Meal")
};

Food chickenList [] = {
    Food("Chicken_1", 100, 1, "Chicken", "Meal"),
    Food("Chicken_2", 100, 1, "Chicken", "Meal")
};

Food beefList [] = {
    Food("Beef_1", 100, 1, "Beef", "Meal"),
    Food("Beef_2", 100, 1, "Beef", "Meal")
};

Food seeFoodList [] = {
    Food("Seafood_1", 100, 1, "Seafood", "Meal"),
    Food("Seafood_2", 100, 1, "Seafood", "Meal")
};

Food comboList [] = {
    Food("Combo_1", 100, 1, "Combo", "Meal"),
    Food("Combo_2", 100, 1, "Combo", "Meal")
};

Food drinksList [] = {
    Food("Drinks_1", 100, 1, "Drinks & Beverage", "Drinks"),
    Food("Drinks_2", 100, 1, "Drinks & Beverage", "Drinks")
};

string menuList[] = {"Starter", "Appetizer", "Chicken", "Beef", "Seafood", "Combo", "Drinks"};

int main()
{

    curentStage = 0; // 0 =? initialize;
                     // 1 => showMainMenu;
                     // 2 => showSubMenu;
                     // 3 => Drinks & Beverage
                     // 4 => viewCart;
                     // 5 => checkOut;singleOrder
                     // 6 => thanksScreen;
    bool isContinue = true;
    string name;
    int currentMenu;
    unique_ptr<SingleOrder> orderList[1000];
    int orderSize = 0;

    while (isContinue){
        switch (curentStage){
            case 0:
                name = showGreatings();
                curentStage++;
                break;
            case 1:
                currentMenu = showMainMenu();
                curentStage++;
                cout << currentMenu << endl;
                break;
            case 2:
                orderList[orderSize] = move(showSubMenu(currentMenu));
                curentStage--;
                cout << "*************************************************************************" << endl;

                for(int i = 0; i<= orderSize; i++) {
                    cout << "Qnt: "<<orderList[i]->getQuantity() << endl;
                    cout << "Food Name: "<<orderList[i]->getFood().getName() << endl;
                }
                orderSize++;

                break;
            default:
                isContinue = false;
                break;
        }
    }

    return 0;
}

void clearView(){
    system("CLS");
}

string showGreatings(){
    string fullName;
    cout << "Welcome to our shop.\nEnter your name to proceed: "; // edit this line.
    getline(cin, fullName);
    clearView();
    return fullName;
}

int showMainMenu(){
    int selection;
    int menuSize = *(&menuList +  1) - menuList;
    cout << "No \tMenu Name" << endl;
    for (int i = 0; i < menuSize - 1; i++) {
        cout << i + 1 << "\t" << menuList[i] << endl;
    }
    cout << "Pick a menu to continue: ";
    cin >> selection;
    clearView();
    return selection;
}

int getSubMenuSize(int menu) {
    switch(menu) {
        case 1:
            return *(&starterList +  1) - starterList;
            break;
        case 2:
            return *(&appetizerList +  1) - appetizerList;
            break;
        case 3:
            return *(&chickenList +  1) - chickenList;
            break;
        case 4:
            return *(&beefList +  1) - beefList;
            break;
        case 5:
            return *(&seeFoodList +  1) - seeFoodList;
            break;
        case 6:
            return *(&comboList +  1) - comboList;
            break;
        case 7:
            return *(&drinksList +  1) - drinksList;
            break;
        default:
            return 0;
    }
}

unique_ptr<SingleOrder> showSubMenu(int menu){
    int selection;
    Food currentSelectedFood;
    int subMenuSize = getSubMenuSize(menu);
    switch (menu) {
        case 1:
            selection = showSubMenuItem(starterList, subMenuSize);
            currentSelectedFood = starterList[selection - 1];
            break;
        case 2:
            selection = showSubMenuItem(appetizerList, subMenuSize);
            currentSelectedFood = appetizerList[selection - 1];
            break;
        case 3:
            selection = showSubMenuItem(chickenList, subMenuSize);
            currentSelectedFood = chickenList[selection - 1];
            break;
        case 4:
            selection = showSubMenuItem(beefList, subMenuSize);
            currentSelectedFood = beefList[selection - 1];
            break;
        case 5:
            selection = showSubMenuItem(seeFoodList, subMenuSize);
            currentSelectedFood = seeFoodList[selection - 1];
            break;
        case 6:
            selection = showSubMenuItem(comboList, subMenuSize);
            currentSelectedFood = comboList[selection - 1];
            break;
    }
    int quantity;
    cout << "Please enter quantity of this item: ";
    cin >> quantity;

    auto singleOrder = createSingleOrder(currentSelectedFood, quantity);
    return singleOrder;
}

int showSubMenuItem(Food subMenu[], int len) {
    cout << "Current Sub menu: " << subMenu[0].getSubMenutype() << endl;
    cout << "No \tFood Name \tQuantity \tPrice" << endl;
    for (int i = 0; i < len; i++) {
        cout << i + 1 << "\t" << subMenu[i].getName() << "\t" << subMenu[i].getQuantity() << "\t\t" << subMenu[i].getPrice() << " rm" << endl;
    }

    int selection;
    cout << "Pick an item to continue: ";
    cin >> selection;
    return selection;
}

unique_ptr<SingleOrder> createSingleOrder(Food food, int quantity) {
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    unique_ptr<SingleOrder> singleOrder = make_unique<SingleOrder>();
    singleOrder->setFood(food);
    singleOrder->setQuantity(quantity);
    return singleOrder;
}
