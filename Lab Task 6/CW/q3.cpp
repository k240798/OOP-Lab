#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Employee {
public:
    int id;
    string name;

    Employee(int id, const string& name) : id(id), name(name) {}

    virtual void performRole() = 0;

    virtual ~Employee() = default;
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() = default;
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() = default;
};

class IBiller {
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() = default;
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int id, const string& name) : Employee(id, name) {}

    void takeOrder() override {
        cout << name << " is taking the order." << endl;
    }

    void performRole() override {
        takeOrder();
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int id, const string& name) : Employee(id, name) {}

    void prepareOrder() override {
        cout << name << " is preparing the order." << endl;
    }

    void performRole() override {
        prepareOrder();
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int id, const string& name) : Employee(id, name) {}

    void generateBill() override {
        cout << name << " is generating the bill." << endl;
    }

    void performRole() override {
        generateBill();
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int id, const string& name) : Employee(id, name) {}

    void takeOrder() override {
        cout << name << " is taking the order." << endl;
    }

    void generateBill() override {
        cout << name << " is generating the bill." << endl;
    }

    void performRole() override {
        takeOrder();
        generateBill();
    }
};

class Menu {
public:
    virtual double calculateTotal() = 0;
    virtual ~Menu() = default;
};

class FoodMenu : public Menu {
private:
    vector<double> foodItems;

public:
    FoodMenu(const vector<double>& items) : foodItems(items) {}

    double calculateTotal() override {
        double total = 0;
        for (double price : foodItems) {
            total += price;
        }
        return total;
    }
};

class BeverageMenu : public Menu {
private:
    vector<double> beverageItems;

public:
    BeverageMenu(const vector<double>& items) : beverageItems(items) {}

    double calculateTotal() override {
        double total = 0;
        for (double price : beverageItems) {
            total += price;
        }
        return total * 1.15; 
    }
};

int main() {
    Waiter waiter(1, "Alice");
    Chef chef(2, "Bob");
    Cashier cashier(3, "Charlie");
    Manager manager(4, "Dave");

    vector<Employee*> employees = { &waiter, &chef, &cashier, &manager };

    for (Employee* employee : employees) {
        employee->performRole();  
    }

    vector<double> foodItems = { 10.0, 15.5, 7.0 };  
    vector<double> beverageItems = { 5.0, 3.5, 4.0 }; 

    FoodMenu foodMenu(foodItems);
    BeverageMenu beverageMenu(beverageItems);

    cout << "Total cost for food menu: $" << foodMenu.calculateTotal() << endl;
    cout << "Total cost for beverage menu: $" << beverageMenu.calculateTotal() << endl;

    return 0;
}
