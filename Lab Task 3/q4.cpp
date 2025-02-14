#include <iostream>
#include <string>
#include <iomanip>

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
        // If salary is positive, use it. Otherwise, set to 0.0.
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
        monthlySalary *= 1.10;  // Increase salary by 10%
    }

    void displayEmployeeInfo() const {
        cout << "Employee: " << firstName << " " << lastName << endl;
        cout << "Monthly Salary: $" << fixed << setprecision(2) << monthlySalary << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cout << "Usage: EmployeeTest <FirstName1> <LastName1> <Salary1> <Salary2>" << endl;
        return 1;
    }

    string firstName1 = argv[1], lastName1 = argv[2];
    double salary1 = stod(argv[3]);

    string firstName2 = argv[1], lastName2 = argv[2];
    double salary2 = stod(argv[4]);

    Employee employee1(firstName1, lastName1, salary1);
    Employee employee2(firstName2, lastName2, salary2);

    cout << "Initial Yearly Salaries:" << endl;
    cout << "Employee 1: $" << employee1.getYearlySalary() << endl;
    cout << "Employee 2: $" << employee2.getYearlySalary() << endl;

    employee1.giveRaise();
    employee2.giveRaise();

    cout << "\nYearly Salaries after 10% Raise:" << endl;
    cout << "Employee 1: $" << employee1.getYearlySalary() << endl;
    cout << "Employee 2: $" << employee2.getYearlySalary() << endl;

    return 0;
}
