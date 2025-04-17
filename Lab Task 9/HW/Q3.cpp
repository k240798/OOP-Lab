#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    virtual void getData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    virtual void displayData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    virtual void calculateBonus() = 0;  
};

class Admin : virtual public Person {
protected:
    double salary;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayData() override {
        Person::displayData();
        cout << "Salary: " << salary << endl;
    }

    void calculateBonus() override {
        double bonus = salary * 0.10;  
        cout << "Bonus for Admin: " << bonus << endl;
    }
};

class Account : virtual public Person {
protected:
    double salary;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayData() override {
        Person::displayData();
        cout << "Salary: " << salary << endl;
    }

    void calculateBonus() override {
        double bonus = salary * 0.15;  
        cout << "Bonus for Account: " << bonus << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        Admin::getData(); 
    }

    void displayData() override {
        Admin::displayData();  
    }

    void calculateBonus() override {
        double bonusAdmin = Admin::salary * 0.10;
        double bonusAccount = Account::salary * 0.15;
        cout << "Bonus for Master: " << (bonusAdmin > bonusAccount ? bonusAdmin : bonusAccount) << endl;
    }
};

int main() {
    Person* ptr;
    
    Admin admin;
    ptr = &admin;
    ptr->getData();
    ptr->displayData();
    ptr->calculateBonus();

    Account account;
    ptr = &account;
    ptr->getData();
    ptr->displayData();
    ptr->calculateBonus();

    Master master;
    ptr = &master;
    ptr->getData();
    ptr->displayData();
    ptr->calculateBonus();

    return 0;
}
