#include <iostream>
#include <Food.h>
#include <string>
#include <stdlib.h>
#include <memory>
#include <SingleOrder.h>
#include <Order.h>
#include <vector>
#include<ios>
#include<limits>
#include <algorithm>

using namespace std;

void clearView();
string showGreatings();
int showMainMenu();
int getSubMenuSize(int menu);
bool showSubMenu(int menu, vector <unique_ptr<SingleOrder>> *cart);
int showSubMenuItem(Food subMenu[], int len);
void addOrUpdateCart(Food food, int quantity, vector<unique_ptr<SingleOrder>> *cart);
void allCartItem(vector<unique_ptr<SingleOrder>> *cart);
int viewCart(vector<unique_ptr<SingleOrder>> *cart);
void checkOut(vector<unique_ptr<SingleOrder>> *cart);
int orderDetail(string name, vector<unique_ptr<SingleOrder>> *cart);
void modifyCart(vector<unique_ptr<SingleOrder>> *cart);

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

string paymentOption[] = {"Cash", "Card", "E Wallet", "Online transfer"};

struct Payment{
    int option;
    long int cash, cardNumber;
};

struct Payment payment;

long int total;

int main()
{
    curentStage = 0; // 0 => initialize;
                     // 1 => showMainMenu;
                     // 2 => showSubMenu;
                     // 3 => viewCart;
                     // 4 => modifyCurrent order;
                     // 5 => checkOut;
                     // 6 => orderDetail;
    bool isContinue = true;
    string name;
    int currentMenu;
    vector <unique_ptr<SingleOrder>> cart;

    while (isContinue){
        switch (curentStage){
            case 0:
                name = showGreatings();
                curentStage++;
                break;
            case 1:
                currentMenu = showMainMenu();
                curentStage++;
                break;
            case 2:
                bool wantToOderMore;

                wantToOderMore = showSubMenu(currentMenu, &cart);
                if(wantToOderMore) {
                    curentStage--;
                } else {
                    curentStage++;
                }
                break;
            case 3:
                curentStage = viewCart(&cart);
                break;
            case 4:
                modifyCart(&cart);
                curentStage++;
                break;
            case 5:
                checkOut(&cart);
                curentStage++;
                break;
            case 6:
                curentStage = orderDetail(name, &cart);
                for (size_t i = 0; i < cart.size(); i++) {
                    cart[i]->~SingleOrder();
                }
                cart.clear();
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
    cout << "Main menu list" << endl;
    cout << "----------------------" << endl;
    cout << "No \tMenu Name" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < menuSize; i++) {
        cout << i + 1 << "\t" << menuList[i] << endl;
    }
    cout << "----------------------" << endl;
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

bool showSubMenu(int menu, vector <unique_ptr<SingleOrder>> *cart){
    Food currentSelectedFood;
    int subMenuSize = getSubMenuSize(menu);
    switch (menu) {
        case 1:
            currentSelectedFood = starterList[showSubMenuItem(starterList, subMenuSize) - 1];
            break;
        case 2:
            currentSelectedFood = appetizerList[showSubMenuItem(appetizerList, subMenuSize) - 1];
            break;
        case 3:
            currentSelectedFood = chickenList[showSubMenuItem(chickenList, subMenuSize) - 1];
            break;
        case 4:
            currentSelectedFood = beefList[showSubMenuItem(beefList, subMenuSize) - 1];
            break;
        case 5:
            currentSelectedFood = seeFoodList[showSubMenuItem(seeFoodList, subMenuSize) - 1];
            break;
        case 6:
            currentSelectedFood = comboList[showSubMenuItem(comboList, subMenuSize) - 1];
            break;
        case 7:
            currentSelectedFood = drinksList[showSubMenuItem(drinksList, subMenuSize) - 1];
            break;
    }
    int quantity;
    cout << "Please enter quantity of this item: ";
    cin >> quantity;
    addOrUpdateCart(currentSelectedFood, quantity, cart);
    char selection;
    cout << "Item saved :D.\nDo you want to order more? (Y/n): " << endl;
    cin >> selection;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    clearView();
    if (selection == 'Y' || selection == 'y')
        return true;
    else
        return false;
}

int showSubMenuItem(Food subMenu[], int len) {
    cout << "Current Sub menu: " << subMenu[0].getSubMenutype() << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "No \tFood Name \tQuantity \tPrice" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < len; i++) {
        cout << i + 1 << "\t" << subMenu[i].getName() << "\t" << subMenu[i].getQuantity() << "\t\t" << subMenu[i].getPrice() << " rm" << endl;
    }
    cout << "--------------------------------------------------------" << endl;
    int selection;
    cout << "Pick an item to continue: ";
    cin >> selection;
    return selection;
}

void addOrUpdateCart(Food food, int quantity, vector<unique_ptr<SingleOrder>> *cart) {

    for (size_t i = 0; i < cart->size(); i++) {
        if (cart->at(i)->getFood().getName() == food.getName()) {
            cart->at(i)->increaseItem(quantity);
            return;
        }
    }

    unique_ptr<SingleOrder> singleOrder = make_unique<SingleOrder>();
    singleOrder->setFood(food);
    singleOrder->setQuantity(quantity);
    cart->push_back(move(singleOrder));
}

void allCartItem(vector<unique_ptr<SingleOrder>> *cart) {
    total = 0;
    cout << "No.\tName\t\tQuantity\tUnit Price \tTotal Price" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    for(size_t i = 0; i < cart->size(); i++) {
        total += cart->at(i)->getQuantity() * cart->at(i)->getFood().getPrice() ;
        cout << i + 1 << "\t";
        cout << cart->at(i)->getFood().getName() << "\t";
        cout << cart->at(i)->getQuantity() << "\t\t";
        cout << cart->at(i)->getFood().getPrice() << "\t\t" ;
        cout << cart->at(i)->getQuantity() * cart->at(i)->getFood().getPrice() << endl;
    }
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\tTotal: " << total << endl;
}

int viewCart(vector<unique_ptr<SingleOrder>> *cart) {
    cout << "\t\t\t\t Cart Detail" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    allCartItem(cart);
    char selection;

    cout << "Do you want to add more Item? (Y/n): ";
    cin >> selection;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if(selection == 'Y' || selection == 'y') {
        clearView();
        return 1;
    } else {
        cout << "Do you want to modify cart? (Y/n): ";
        cin >> selection;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        clearView();
        if(selection == 'Y' || selection == 'y') {
            return 4;
        } else {
            return 5;
        }
    }



}

void checkOut(vector<unique_ptr<SingleOrder>> *cart) {
    cout << "Payment options" << endl;
    cout << "-------------------------------" << endl;
    int len = *(&paymentOption +  1) - paymentOption;
    for (int i = 0; i < len; i++) {
        cout << i + 1 << " " + paymentOption[i] << endl;
    }
    cout << "-------------------------------" << endl;
    cout << "Select Payment Option: ";
    int selection;
    cin >> selection;
    switch(selection) {
        case 1:
            payment.option = 1;
            payment.cardNumber = 0;
            cout << "Have to pay: " << total << endl;
            cout << "You wants to pay: " ;
            cin >> payment.cash;
            break;
        case 2:
        case 3:
        case 4:
            payment.option = 2;
            payment.cash = total;
            cout << "Your Card/Account number: " ;
            cin >> payment.cardNumber;
            break;
    }
    clearView();
}

int orderDetail(string name, vector<unique_ptr<SingleOrder>> *cart) {
    cout << "This invoice is generated for " << name << " for following items" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    allCartItem(cart);
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Payment option: " << paymentOption[payment.option - 1] << endl;
    if(payment.option != 1) {
       cout << "Card/Account number: " << payment.cardNumber<< endl;
    }
    cout << "Paid: " << payment.cash << endl;
    cout << "Return: " << payment.cash - total << endl;

    char selection;
    cout << "Do you want to order again? (Y/n): ";
    cin >> selection;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    clearView();
    if(selection == 'Y' || selection == 'y'){
        return 1;
    } else {
        return 0;
    }
}

void modifyCart(vector<unique_ptr<SingleOrder>> *cart){
    cout << "\t\t\t\t Cart Detail" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    allCartItem(cart);
    int selection;
    cout << "Select an item to modify: ";
    cin >> selection;
    int itemCount;
    cout << "Enter the new item count of " << cart->at(selection - 1)->getFood().getName() << ": ";
    cin >> itemCount;
    cart->at(selection - 1)->setQuantity(itemCount);
    clearView();
    viewCart(cart);
}



