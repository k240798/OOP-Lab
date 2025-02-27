#include <iostream>

using namespace std;

class Student {
private:
    const int roll_no; 

public:
    Student(int roll) : roll_no(roll) {}

    void display() const {
        cout << "Student Roll Number: " << roll_no << endl;
    }
};

int main() {
    int roll;
    cout << "Enter student roll number: ";
    cin >> roll;

    Student student(roll);

    student.display();

    return 0;
}
