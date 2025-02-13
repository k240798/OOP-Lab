#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    double monthlySalary;

public:
    Employee(string first, string last, double salary) {
        firstName = first;
        lastName = last;
        if (salary > 0.0) {
            monthlySalary = salary;
        } else {
            monthlySalary = 0.0;  
        }
    }

    double getYearlySalary() const {
        return monthlySalary * 12;
    }

    void giveRaise() {
        monthlySalary *= 1.10; 
    }

    void displayEmployeeInfo() const {
        cout << firstName << " " << lastName << " has a monthly salary of $" 
             << monthlySalary << " and a yearly salary of $" 
             << getYearlySalary() << "." << endl;
    }
};

int main() {
    Employee employee1("John", "Doe", 3000.0);
    Employee employee2("Jane", "Smith", -500.0); 

    cout << "Initial yearly salaries:" << endl;
    employee1.displayEmployeeInfo();
    employee2.displayEmployeeInfo();

    employee1.giveRaise();
    employee2.giveRaise();

    cout << "\nUpdated yearly salaries after a 10% raise:" << endl;
    employee1.displayEmployeeInfo();
    employee2.displayEmployeeInfo();

    return 0;
}
