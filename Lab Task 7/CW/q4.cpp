#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string addr, string phone, string email)
        : name(n), id(i), address(addr), phoneNumber(phone), email(email) {}

    string getName() const { return name; }

    string getId() const { return id; }

    string getAddress() const { return address; }

    string getPhoneNumber() const { return phoneNumber; }

    string getEmail() const { return email; }

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    virtual void updateInfo(string newName, string newAddress, string newPhone, string newEmail) {
        name = newName;
        address = newAddress;
        phoneNumber = newPhone;
        email = newEmail;
    }
};

class Student : public Person {
private:
    vector<string> coursesEnrolled;
    float GPA;  

public:
    Student(string n, string i, string addr, string phone, string email, vector<string> courses, float gpa)
        : Person(n, i, addr, phone, email), coursesEnrolled(courses), GPA(gpa) {}

    float getGPA() const { return GPA; }

    void displayInfo() const override {
        Person::displayInfo(); 
        cout << "Courses Enrolled: ";
        for (const string& course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << endl;
        cout << "GPA: " << fixed << setprecision(2) << GPA << endl;
    }

    void registerCourse(string courseName) {
        coursesEnrolled.push_back(courseName);
    }
};

class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    float salary;

public:
    Professor(string n, string i, string addr, string phone, string email, string dept, vector<string> courses, float sal)
        : Person(n, i, addr, phone, email), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo(); 
        cout << "Department: " << department << endl;
        cout << "Courses Taught: ";
        for (const string& course : coursesTaught) {
            cout << course << " ";
        }
        cout << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    }
};

class Staff : public Person {
private:
    string department;
    string position;
    float salary;

public:
    Staff(string n, string i, string addr, string phone, string email, string dept, string pos, float sal)
        : Person(n, i, addr, phone, email), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo(); 
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    }
};

class Course {
private:
    string courseId;
    string courseName;
    int credits;
    Professor* instructor;
    string schedule;
    vector<Student*> enrolledStudents;

public:
    Course(string id, string name, int cred, Professor* prof, string sched)
        : courseId(id), courseName(name), credits(cred), instructor(prof), schedule(sched) {}

    void registerStudent(Student* student) {
        enrolledStudents.push_back(student);
    }

    void calculateGrades() const {
        cout << "Grades for Course: " << courseName << endl;
        for (const Student* student : enrolledStudents) {
            student->displayInfo();
            cout << "GPA: " << fixed << setprecision(2) << student->getGPA() << endl;
        }
    }

    void displayCourseInfo() const {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor->getName() << endl;
        cout << "Schedule: " << schedule << endl;
    }
};

int main() {
    Student student1("Alice", "S123", "123 Elm St", "555-1234", "alice@university.edu", {"Math101", "CS102"}, 3.9);
    Student student2("Bob", "S124", "456 Oak St", "555-5678", "bob@university.edu", {"Math101", "Hist201"}, 3.5);

    Professor professor1("Dr. Smith", "P001", "789 Pine St", "555-9101", "smith@university.edu", "Computer Science", {"CS102", "CS201"}, 70000);
    Staff staff1("Charlie", "ST001", "101 Maple St", "555-3456", "charlie@university.edu", "Administration", "Manager", 45000);

    Course course1("CS102", "Introduction to Computer Science", 3, &professor1, "Mon-Wed-Fri 10:00 AM - 12:00 PM");
    course1.registerStudent(&student1);
    course1.registerStudent(&student2);

    cout << "---- Student Details ----" << endl;
    student1.displayInfo();
    cout << endl;
    student2.displayInfo();
    cout << endl;

    cout << "---- Professor Details ----" << endl;
    professor1.displayInfo();
    cout << endl;

    cout << "---- Staff Details ----" << endl;
    staff1.displayInfo();
    cout << endl;

    cout << "---- Course Details ----" << endl;
    course1.displayCourseInfo();
    cout << endl;

    course1.calculateGrades();

    return 0;
}
