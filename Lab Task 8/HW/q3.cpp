#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int employeeID;  

public:
    virtual void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }

    virtual void displayData() const {
        cout << "Employee ID: " << employeeID << endl;
    }

    virtual double bonus() const = 0;
};

class Admin : public Person {
private:
    string name;        
    double monthlyIncome; 

public:
    void getData() override {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() const override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonus() << endl;
    }

    double bonus() const override {
        return monthlyIncome * 12 * 0.05;
    }
};

class Accounts : public Person {
private:
    string name;       
    double monthlyIncome; 

public:
    void getData() override {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() const override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonus() << endl;
    }

    double bonus() const override {
        return monthlyIncome * 12 * 0.05;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Person* employees[n];

    for (int i = 0; i < n; ++i) {
        int type;
        cout << "Enter 1 for Admin or 2 for Accounts: ";
        cin >> type;

        if (type == 1) {
            employees[i] = new Admin();  
        } else if (type == 2) {
            employees[i] = new Accounts();  
        }

        employees[i]->getData();  
    }

    for (int i = 0; i < n; ++i) {
        cout << "\nEmployee " << (i + 1) << " details:\n";
        employees[i]->displayData();
        delete employees[i]; 
    }

    return 0;
}
