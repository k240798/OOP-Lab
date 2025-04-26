#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int years_of_service;

    void display() const {  
        cout << "ID: " << id << ", Name: " << name 
             << ", Designation: " << designation 
             << ", Years of Service: " << years_of_service << endl;
    }

    string to_string() const {  
        return std::to_string(id) + " " + name + " " + designation + " " + std::to_string(years_of_service);
    }
};

vector<Employee> readFromFile(const string &filename) {
    ifstream file(filename);
    vector<Employee> employees;
    string line;

    while (getline(file, line)) {
        Employee emp;
        size_t pos1 = line.find(" ");
        emp.id = stoi(line.substr(0, pos1));

        size_t pos2 = line.find(" ", pos1 + 1);
        emp.name = line.substr(pos1 + 1, pos2 - pos1 - 1);  

        size_t pos3 = line.find(" ", pos2 + 1);
        emp.designation = line.substr(pos2 + 1, pos3 - pos2 - 1); 

        emp.years_of_service = stoi(line.substr(pos3 + 1));  
        
        employees.push_back(emp);
    }
    file.close();
    return employees;
}

void writeToFile(const string &filename, const vector<Employee> &employees) {
    ofstream file(filename);
    for (const auto &emp : employees) {
        file << emp.to_string() << endl;
    }
    file.close();
}

vector<Employee> findManagersWithService(const vector<Employee> &employees) {
    vector<Employee> result;
    for (const auto &emp : employees) {
        if (emp.designation == "manager" && emp.years_of_service >= 2) {
            result.push_back(emp);
        }
    }
    return result;
}

vector<Employee> deleteExceptManagers(const vector<Employee> &employees, const vector<Employee> &managers) {
    vector<Employee> result = managers; 
    return result; 
}

vector<Employee> incrementEmployeeData(const vector<Employee> &employees) {
    vector<Employee> updatedEmployees = employees;
    for (auto &emp : updatedEmployees) {
        emp.id++;  
        emp.years_of_service++;  
    }
    return updatedEmployees;
}

int main() {
    string filename = "employees.txt";

    vector<Employee> employees = {
        {1, "Amir", "manager", 3},
        {2, "Babar", "developer", 1},
        {3, "Chishti", "manager", 2},
        {4, "Dawood", "developer", 5}
    };
    writeToFile(filename, employees);

    employees = readFromFile(filename);
    
    vector<Employee> managers = findManagersWithService(employees);
    cout << "Managers with at least 2 years of service:" << endl;
    for (const auto &emp : managers) {
        emp.display();
    }

    vector<Employee> remainingData = deleteExceptManagers(employees, managers);
    cout << "\nData after deletion (only managers with at least 2 years of service):" << endl;
    for (const auto &emp : remainingData) {
        emp.display();
    }

    vector<Employee> updatedData = incrementEmployeeData(remainingData);
    cout << "\nUpdated Data (with incremented IDs and years of service):" << endl;
    for (const auto &emp : updatedData) {
        emp.display();
    }

    writeToFile(filename, updatedData);

    return 0;
}
