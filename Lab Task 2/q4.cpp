#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int employee_id;
    string name;
    double salary;
};

struct Organisation {
    string organisation_name;
    string organisation_number;
    Employee emp;
};

int main() {
    Organisation org;
    
    org.organisation_name = "NU-Fast";
    org.organisation_number = "NUFAST123ABC";
    org.emp.employee_id = 127;
    org.emp.name = "Linus Sebastian";
    org.emp.salary = 400000;

    cout << "The size of structure organisation : " << sizeof(org) << "\n";
    cout << "Organisation Name : " << org.organisation_name << "\n";
    cout << "Organisation Number : " << org.organisation_number << "\n";
    cout << "Employee id : " << org.emp.employee_id << "\n";
    cout << "Employee name : " << org.emp.name << "\n";
    cout << "Employee Salary : " << org.emp.salary << "\n";

    return 0;
}
