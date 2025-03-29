#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int rollNo;

public:
    void getStudentDetails() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNo;
    }

    void displayStudentDetails() {
        cout << "\nStudent Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
    }
};

class Marks : public Student {
protected:
    int marks[5]; // Assuming there are 5 courses

public:
    void getMarks() {
        cout << "Enter marks for 5 courses: ";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
        }
    }

    void displayMarks() {
        cout << "Marks obtained in each course: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

class Result : public Marks {
private:
    int total;
    float average;

public:
    void calculateResult() {
        total = 0;
        for (int i = 0; i < 5; i++) {
            total += marks[i];
        }
        average = total / 5.0;
    }

    void displayResult() {
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};

int main() {
    Result studentResult;

    studentResult.getStudentDetails();
    studentResult.getMarks();
    studentResult.calculateResult();
    
    studentResult.displayStudentDetails();
    studentResult.displayMarks();
    studentResult.displayResult();

    return 0;
}
