#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct MenuItem {
    string name;
    double price;
    string type; 
};

class CoffeeShop {
private:
    const string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName, vector<MenuItem> menuItems) : name(shopName), menu(menuItems) {}

    string getName() const {
        return name;
    }

    string addOrder(string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string fulfilledItem = orders.front();
            orders.erase(orders.begin());
            return "The " + fulfilledItem + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() const {
        return orders;
    }

    double dueAmount() const {
        double total = 0;
        for (const string& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        if (menu.empty()) return "Menu is empty!";
        double minPrice = numeric_limits<double>::max();
        string cheapest;
        for (const auto& item : menu) {
            if (item.price < minPrice) {
                minPrice = item.price;
                cheapest = item.name;
            }
        }
        return cheapest;
    }

    vector<string> drinksOnly() const {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() const {
        vector<string> foods;
        for (const auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main(int argc, char* argv[]) {
    vector<MenuItem> menu = {
        {"Espresso", 2.5, "drink"},
        {"Cappuccino", 3.0, "drink"},
        {"Latte", 3.5, "drink"},
        {"Croissant", 4.0, "food"},
        {"Bagel", 2.0, "food"},
        {"Muffin", 3.0, "food"}
    };

    CoffeeShop myShop("Java Haven", menu);

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <command> [item]\n";
        cerr << "Commands: add <item>, fulfill, list, due, cheapest, drinks, food\n";
        return 1;
    }

    string command = argv[1];

    if (command == "add") {
        if (argc < 3) {
            cerr << "Error: Please provide an item name to add.\n";
            return 1;
        }
        string itemName = argv[2];
        cout << myShop.addOrder(itemName) << endl;
    } 
    else if (command == "fulfill") {
        cout << myShop.fulfillOrder() << endl;
    } 
    else if (command == "list") {
        vector<string> orders = myShop.listOrders();
        if (orders.empty()) {
            cout << "No orders currently.\n";
        } else {
            cout << "Current Orders:\n";
            for (const string& order : orders) {
                cout << "- " << order << endl;
            }
        }
    } 
    else if (command == "due") {
        cout << "Total Amount Due: $" << myShop.dueAmount() << endl;
    } 
    else if (command == "cheapest") {
        cout << "Cheapest Item: " << myShop.cheapestItem() << endl;
    } 
    else if (command == "drinks") {
        vector<string> drinks = myShop.drinksOnly();
        cout << "Drinks Available:\n";
        for (const string& drink : drinks) {
            cout << "- " << drink << endl;
        }
    } 
    else if (command == "food") {
        vector<string> foods = myShop.foodOnly();
        cout << "Food Available:\n";
        for (const string& food : foods) {
            cout << "- " << food << endl;
        }
    } 
    else {
        cerr << "Invalid command. Use 'add', 'fulfill', 'list', 'due', 'cheapest', 'drinks', or 'food'.\n";
        return 1;
    }

    return 0;
}
