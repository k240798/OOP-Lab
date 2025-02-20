#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

enum ItemType { FOOD, DRINK };

class MenuItem {
public:
    string name;
    ItemType type;
    double price;

    MenuItem(string n, ItemType t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;                            
    vector<MenuItem> menu;                 
    vector<string> orders;                 

public:
    CoffeeShop(string shopName) : name(shopName) {}

    void addMenuItem(const string& itemName, ItemType itemType, double price) {
        menu.push_back(MenuItem(itemName, itemType, price));
    }

    void addOrder(const string& itemName) {
        bool itemFound = false;
        for (const auto& item : menu) {
            if (item.name == itemName) {
                itemFound = true;
                orders.push_back(itemName);
                cout << itemName << " has been added to your order." << endl;
                return;
            }
        }
        cout << "This item is currently unavailable." << endl;
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string order = orders.front();
            orders.erase(orders.begin());
            return "The " + order + " is ready";
        } else {
            return "All orders have been fulfilled";
        }
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0.0;
        for (const string& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "";
        
        MenuItem cheapest = menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == DRINK) {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foodItems;
        for (const auto& item : menu) {
            if (item.type == FOOD) {
                foodItems.push_back(item.name);
            }
        }
        return foodItems;
    }

    void displayMenu() {
        cout << "Menu:" << endl;
        for (const auto& item : menu) {
            cout << item.name << " (" << (item.type == DRINK ? "Drink" : "Food") << ") - $" << item.price << endl;
        }
    }
};

void parseArguments(int argc, char* argv[], CoffeeShop& shop) {
    int i = 1;
    
    if (argc > 1) {
        string shopName = argv[i++];
        shop = CoffeeShop(shopName);
    }

    while (i < argc) {
        string itemName = argv[i++];
        string itemType = argv[i++];
        double price = stod(argv[i++]);

        ItemType type = (itemType == "drink") ? DRINK : FOOD;
        shop.addMenuItem(itemName, type, price);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: ./coffeeShop <ShopName> <MenuItems>" << endl;
        return 1;
    }

    CoffeeShop myShop("");
    parseArguments(argc, argv, myShop);

    myShop.displayMenu();

    myShop.addOrder("Latte");
    myShop.addOrder("Bagel");
    myShop.addOrder("Smoothie"); 

    cout << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl; 

    vector<string> currentOrders = myShop.listOrders();
    cout << "Remaining Orders: ";
    for (const string& order : currentOrders) {
        cout << order << " ";
    }
    cout << endl;

    cout << "Total amount due: $" << myShop.dueAmount() << endl;

    cout << "The cheapest item on the menu: " << myShop.cheapestItem() << endl;

    vector<string> drinks = myShop.drinksOnly();
    cout << "Drinks only: ";
    for (const string& drink : drinks) {
        cout << drink << " ";
    }
    cout << endl;

    vector<string> foodItems = myShop.foodOnly();
    cout << "Food only: ";
    for (const string& food : foodItems) {
        cout << food << " ";
    }
    cout << endl;

    return 0;
}
