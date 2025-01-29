#include <iostream>
#include <iomanip>  
#include <sstream> 

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 7) {
        cout << "Please enter the student's name followed by five test scores." << endl;
        return 1;  
    }

    string studentName = argv[1];  
    for (int i = 2; i < argc - 5; i++) {
        studentName += " " + string(argv[i]);  
    }

    double testScores[5], total = 0.0, average;

    for (int i = 0; i < 5; i++) {
        testScores[i] = stod(argv[argc - 5 + i]);  
        total += testScores[i];  
    }

    average = total / 5.0;

    cout << fixed << setprecision(2);

    cout << "Student name: " << studentName << endl;
    cout << "Test scores: ";
    for (int i = 0; i < 5; i++) {
        cout << testScores[i] << " ";
    }
    cout << endl;

    cout << "Average test score: " << average << endl;

    return 0;
}
